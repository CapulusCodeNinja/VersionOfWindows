#include "RegistryCurrentVersionNumbers.h"
#include <system_error>
#include <vector>
#include <ranges>

#pragma comment(lib, "advapi32")

#ifndef STATUS_SUCCESS
#define STATUS_SUCCESS 0x00000000
#endif

RegistryCurrentVersionNumbers::RegistryCurrentVersionNumbers()
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

    auto queryResult = RegQueryValueEx(m_CurrentVersionKey,
        L"CurrentMajorVersionNumber", nullptr, nullptr, buffer.data(), reinterpret_cast<LPDWORD>(&dataLength));
    if (STATUS_SUCCESS != queryResult)
    {
        throw std::system_error(std::error_code(result, std::system_category()),
            "Failed to query the current major version number registry value");
    }

    m_MajorVersion = static_cast<uint32_t>(*buffer.data());

    dataLength = 256;
    buffer = std::vector<byte>(dataLength, L'\0');

    queryResult = RegQueryValueEx(m_CurrentVersionKey,
        L"CurrentMinorVersionNumber", nullptr, nullptr, buffer.data(), reinterpret_cast<LPDWORD>(&dataLength));
    if (STATUS_SUCCESS != queryResult)
    {
        throw std::system_error(std::error_code(result, std::system_category()),
            "Failed to query the current minor version number registry value");
    }

    m_MinorVersion = static_cast<uint32_t>(*buffer.data());

    dataLength = 256;
    buffer = std::vector<byte>(dataLength, L'\0');

    queryResult = RegQueryValueEx(m_CurrentVersionKey,
        L"CurrentBuildNumber", nullptr, nullptr, buffer.data(), reinterpret_cast<LPDWORD>(&dataLength));
    if (STATUS_SUCCESS != queryResult)
    {
        throw std::system_error(std::error_code(result, std::system_category()),
            "Failed to query the current build version number registry value");
    }

    m_BuildNumber = ::_wtol(reinterpret_cast<wchar_t*>(buffer.data()));
}

RegistryCurrentVersionNumbers::~RegistryCurrentVersionNumbers()
{
    if (nullptr != m_CurrentVersionKey)
    {
        RegCloseKey(m_CurrentVersionKey);
    }
}

std::string RegistryCurrentVersionNumbers::GetVariant() const
{
    return "RegistryCurrentVersionNumbers";
}

uint32_t RegistryCurrentVersionNumbers::GetMajor() const
{
    return m_MajorVersion;
}

uint32_t RegistryCurrentVersionNumbers::GetMinor() const
{
    return m_MinorVersion;
}

uint32_t RegistryCurrentVersionNumbers::GetBuild() const
{
    return m_BuildNumber;
}

bool RegistryCurrentVersionNumbers::IsWindows10OrGreater() const
{
    return GetMajor() >= 10;
}