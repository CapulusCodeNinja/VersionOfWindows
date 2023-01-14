#include "Kernel32Library.h"
#include <system_error>

#pragma comment(lib, "version")

Kernel32Library::Kernel32Library()
{
    const auto bufferSize = GetFileVersionInfoSize(L"kernel32.dll", nullptr);
    if (0 == bufferSize)
    {
        throw std::system_error(std::error_code(GetLastError(), std::system_category()),
            "Unable to get the buffer size for the needed version information");
    }

    m_VersionInformationBuffer = std::vector<byte>(bufferSize, 0);
    const auto bufferFilledSize = GetFileVersionInfo(L"kernel32.dll", 0, bufferSize, m_VersionInformationBuffer.data());
    if (0 == bufferFilledSize)
    {
        throw std::system_error(std::error_code(GetLastError(), std::system_category()),
            "Unable to get the version information written to the buffer");
    }

    UINT versionLength = 0;
    const auto queryValueResult = VerQueryValue(m_VersionInformationBuffer.data(), 
        L"\\", 
        reinterpret_cast<LPVOID*>(&m_Version), 
        &versionLength);

    if (FALSE == queryValueResult)
    {
        throw std::system_error(std::error_code(GetLastError(), std::system_category()),
            "Unable to query the version information value from the version information buffer");
    }
}

Kernel32Library::~Kernel32Library()
{
    m_Version = nullptr;
}

std::string Kernel32Library::GetVariant() const
{
    return "Kernel32Library";
}

uint32_t Kernel32Library::GetMajor() const
{
    return HIWORD(m_Version->dwProductVersionMS);
}

uint32_t Kernel32Library::GetMinor() const
{
    return LOWORD(m_Version->dwProductVersionMS);
}

uint32_t Kernel32Library::GetBuild() const
{
    return HIWORD(m_Version->dwProductVersionLS);
}

bool Kernel32Library::IsWindows10OrGreater() const
{
    return GetMajor() >= 10;
}