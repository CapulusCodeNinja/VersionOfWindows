#include "GetVersionExApi.h"
#include <system_error>

GetVersionExApi::GetVersionExApi()
{
    SecureZeroMemory(&m_VersionInformation, sizeof(OSVERSIONINFOEX));
    m_VersionInformation.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

#pragma warning(push)
    // Ignore the deprecation warning for thie API
#pragma warning(disable : 4996)
#pragma warning(disable : 28159)
    GetVersionEx(reinterpret_cast<OSVERSIONINFO*>(&m_VersionInformation));
#pragma warning(pop) 
}

std::string GetVersionExApi::GetVariant() const
{
    return "GetVersionEx";
}

uint32_t GetVersionExApi::GetMajor() const
{
    return m_VersionInformation.dwMajorVersion;
}

uint32_t GetVersionExApi::GetMinor() const
{
    return m_VersionInformation.dwMinorVersion;
}

uint32_t GetVersionExApi::GetBuild() const
{
    return m_VersionInformation.dwBuildNumber;
}

bool GetVersionExApi::IsWindows10OrGreater() const
{
    return GetMajor() >= 10;
}