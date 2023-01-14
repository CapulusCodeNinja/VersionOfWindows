#include "RtlGetNtVersionNumbersApi.h"
#include <system_error>

RtlGetNtVersionNumbersApi::RtlGetNtVersionNumbersApi()
{
    m_NtDll = GetModuleHandle(L"ntdll.dll");
    if (nullptr == m_NtDll)
    {
        throw std::system_error(std::error_code(GetLastError(), std::system_category()),
            "Failed to get the ntdll.dll library module handle");
    }

    m_RtlGetNtVersionNumbers = (RtlGetNtVersionNumbersFunc)GetProcAddress(m_NtDll, "RtlGetNtVersionNumbers");
    if (nullptr == m_RtlGetNtVersionNumbers)
    {
        throw std::system_error(std::error_code(GetLastError(), std::system_category()),
            "Failed to get the RtlGetNtVersionNumbers function pointer");
    }

    constexpr uint32_t buildNumberMask = 0x0000FFFF;

    m_RtlGetNtVersionNumbers(
        reinterpret_cast<LPDWORD>(&m_MajorVersion), 
        reinterpret_cast<LPDWORD>(&m_MinorVersion), 
        reinterpret_cast<LPDWORD>(&m_BuildNumber));

    m_BuildNumber &= buildNumberMask;
}

RtlGetNtVersionNumbersApi::~RtlGetNtVersionNumbersApi()
{
    if (nullptr != m_NtDll)
    {
        FreeModule(m_NtDll);
    }
}

std::string RtlGetNtVersionNumbersApi::GetVariant() const
{
    return "RtlGetNtVersionNumbers";
}

uint32_t RtlGetNtVersionNumbersApi::GetMajor() const
{
    return m_MajorVersion;
}

uint32_t RtlGetNtVersionNumbersApi::GetMinor() const
{
    return m_MinorVersion;
}

uint32_t RtlGetNtVersionNumbersApi::GetBuild() const
{
    return m_BuildNumber;
}

bool RtlGetNtVersionNumbersApi::IsWindows10OrGreater() const
{
    return GetMajor() >= 10;
}