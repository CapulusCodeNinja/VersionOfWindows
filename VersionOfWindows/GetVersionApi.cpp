#include "GetVersionApi.h"
#include <system_error>

GetVersionApi::GetVersionApi()
{
#pragma warning(push)
    // Ignore the deprecation warning for thie API
#pragma warning(disable : 4996)
#pragma warning(disable : 28159)
    m_Version = GetVersion();
#pragma warning(pop) 

    m_MajorVersion = static_cast<uint32_t>(LOBYTE(LOWORD(m_Version)));
    m_MinorVersion = static_cast<uint32_t>(HIBYTE(LOWORD(m_Version)));

    if (m_Version < 0x80000000)
    {
        m_Build = static_cast<uint32_t>(HIWORD(m_Version));
    }
}

std::string GetVersionApi::GetVariant() const
{
    return "GetVersion";
}

uint32_t GetVersionApi::GetMajor() const
{
    return m_MajorVersion;
}

uint32_t GetVersionApi::GetMinor() const
{
    return m_MinorVersion;
}

uint32_t GetVersionApi::GetBuild() const
{
    return m_Build;
}

bool GetVersionApi::IsWindows10OrGreater() const
{
    return GetMajor() >= 10;
}