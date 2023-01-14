#include "RtlGetVersionApi.h"
#include <system_error>

#ifndef STATUS_SUCCESS
#define STATUS_SUCCESS 0x00000000
#endif

RtlGetVersionApi::RtlGetVersionApi()
{
    m_NtDll = GetModuleHandle(L"ntdll.dll");
    if (nullptr == m_NtDll)
    {
        throw std::system_error(std::error_code(GetLastError(), std::system_category()), 
            "Failed to get the ntdll.dll library module handle");
    }

    m_RtlVersion = (RtlGetVersionFunc)GetProcAddress(m_NtDll, "RtlGetVersion");
    if (nullptr == m_RtlVersion)
    {
        throw std::system_error(std::error_code(GetLastError(), std::system_category()),
            "Failed to get the RtlGetVersion function pointer");
    }

    const auto result = m_RtlVersion(&m_VersionInformation);
    if (STATUS_SUCCESS != result)
    {
        throw std::system_error(std::error_code(GetLastError(), std::system_category()),
            "Failed to get the Windows version from the RtlGetVersion api");
    }
}

RtlGetVersionApi::~RtlGetVersionApi()
{
    if (nullptr != m_NtDll)
    {
        FreeModule(m_NtDll);
    }
}

std::string RtlGetVersionApi::GetVariant() const
{
    return "RtlGetVersion";
}

uint32_t RtlGetVersionApi::GetMajor() const
{
    return m_VersionInformation.dwMajorVersion;
}

uint32_t RtlGetVersionApi::GetMinor() const
{
    return m_VersionInformation.dwMinorVersion;
}

uint32_t RtlGetVersionApi::GetBuild() const
{
    return m_VersionInformation.dwBuildNumber;
}

bool RtlGetVersionApi::IsWindows10OrGreater() const
{
    return GetMajor() >= 10;
}