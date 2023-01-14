#include "RegistryCurrentVersion.h"
#include <system_error>
#include <vector>
#include <ranges>

#pragma comment(lib, "advapi32")

#ifndef STATUS_SUCCESS
#define STATUS_SUCCESS 0x00000000
#endif

RegistryCurrentVersion::RegistryCurrentVersion()
{
    const auto result = RegOpenKeyExW(HKEY_LOCAL_MACHINE,
        LR"(SOFTWARE\Microsoft\Windows NT\CurrentVersion)", 0, KEY_READ, &m_CurrentVersionKey);
    if (ERROR_SUCCESS != result)
    {
        throw std::system_error(std::error_code(result, std::system_category()),
            "Failed to open the current version registry path");
    }

    uint32_t dataLength = 256;
    std::vector<byte> buffer(dataLength, L'\0');
    const auto queryResult = RegQueryValueEx(m_CurrentVersionKey,
        L"CurrentVersion", nullptr, nullptr, buffer.data(), reinterpret_cast<LPDWORD>(&dataLength));
    if (STATUS_SUCCESS != queryResult)
    {
        throw std::system_error(std::error_code(result, std::system_category()),
            "Failed to query the current version registry value");
    }

    const auto versionString = std::wstring(reinterpret_cast<wchar_t*>(buffer.data()));

    std::vector<std::wstring> versionStringParts;
    for (const auto word : std::views::split(versionString, L'.'))
    {
        versionStringParts.push_back({ word.begin(), word.end() });
    }

    if (0 < versionStringParts.size())
    {
        m_MajorVersion = ::_wtol(versionStringParts.at(0).c_str());
    }

    if (1 < versionStringParts.size())
    {
        m_MinorVersion = ::_wtol(versionStringParts.at(1).c_str());
    }

    if (2 < versionStringParts.size())
    {
        m_BuildNumber = ::_wtol(versionStringParts.at(2).c_str());
    }
}

RegistryCurrentVersion::~RegistryCurrentVersion()
{
    if (nullptr != m_CurrentVersionKey)
    {
        RegCloseKey(m_CurrentVersionKey);
    }
}

std::string RegistryCurrentVersion::GetVariant() const
{
    return "RegistryCurrentVersion";
}

uint32_t RegistryCurrentVersion::GetMajor() const
{
    return m_MajorVersion;
}

uint32_t RegistryCurrentVersion::GetMinor() const
{
    return m_MinorVersion;
}

uint32_t RegistryCurrentVersion::GetBuild() const
{
    return m_BuildNumber;
}

bool RegistryCurrentVersion::IsWindows10OrGreater() const
{
    return GetMajor() >= 10;
}