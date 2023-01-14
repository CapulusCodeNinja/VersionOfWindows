#pragma once

#include "IWindowsVersion.h"
#include <Windows.h>

typedef NTSTATUS(WINAPI* RtlGetVersionFunc)(_Out_ PRTL_OSVERSIONINFOW lpVersionInformation);

class RtlGetVersionApi : public IWindowsVersion
{
public:
    RtlGetVersionApi();

    virtual ~RtlGetVersionApi();

    RtlGetVersionApi(RtlGetVersionApi&) = delete;
    RtlGetVersionApi(RtlGetVersionApi&&) = delete;

    void operator=(RtlGetVersionApi&) = delete;
    void operator=(RtlGetVersionApi&&) = delete;

public:
    virtual std::string GetVariant() const override;

    virtual uint32_t GetMajor() const override;

    virtual uint32_t GetMinor() const override;

    virtual uint32_t GetBuild() const override;

    virtual bool IsWindows10OrGreater() const override;

private:
    HMODULE m_NtDll{};
    RtlGetVersionFunc m_RtlVersion{};
    RTL_OSVERSIONINFOW m_VersionInformation{};
};
