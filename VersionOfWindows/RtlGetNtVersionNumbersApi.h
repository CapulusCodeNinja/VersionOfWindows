#pragma once

#include "IWindowsVersion.h"
#include <Windows.h>

typedef VOID(NTAPI* RtlGetNtVersionNumbersFunc)(LPDWORD pdwMajorVersion, LPDWORD pdwMinorVersion, LPDWORD pdwBuildNumber);

class RtlGetNtVersionNumbersApi : public IWindowsVersion
{
public:
    RtlGetNtVersionNumbersApi();

    virtual ~RtlGetNtVersionNumbersApi();

    RtlGetNtVersionNumbersApi(RtlGetNtVersionNumbersApi&) = delete;
    RtlGetNtVersionNumbersApi(RtlGetNtVersionNumbersApi&&) = delete;

    void operator=(RtlGetNtVersionNumbersApi&) = delete;
    void operator=(RtlGetNtVersionNumbersApi&&) = delete;

public:
    virtual std::string GetVariant() const override;

    virtual uint32_t GetMajor() const override;

    virtual uint32_t GetMinor() const override;

    virtual uint32_t GetBuild() const override;

    virtual bool IsWindows10OrGreater() const override;

private:
    HMODULE m_NtDll{};
    uint32_t m_BuildNumber{};
    uint32_t m_MajorVersion{};
    uint32_t m_MinorVersion{};
    RtlGetNtVersionNumbersFunc m_RtlGetNtVersionNumbers{};
};
