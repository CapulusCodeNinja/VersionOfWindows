#pragma once

#include "IWindowsVersion.h"
#include <Windows.h>

class GetVersionExApi : public IWindowsVersion
{
public:
    GetVersionExApi();

    virtual ~GetVersionExApi() = default;

    GetVersionExApi(GetVersionExApi&) = delete;
    GetVersionExApi(GetVersionExApi&&) = delete;

    void operator=(GetVersionExApi&) = delete;
    void operator=(GetVersionExApi&&) = delete;

public:
    virtual std::string GetVariant() const override;

    virtual uint32_t GetMajor() const override;

    virtual uint32_t GetMinor() const override;

    virtual uint32_t GetBuild() const override;

    virtual bool IsWindows10OrGreater() const override;

private:
    OSVERSIONINFOEX m_VersionInformation{};
};
