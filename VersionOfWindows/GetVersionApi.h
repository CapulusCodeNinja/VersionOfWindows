#pragma once

#include "IWindowsVersion.h"
#include <Windows.h>

class GetVersionApi : public IWindowsVersion
{
public:
    GetVersionApi();

    virtual ~GetVersionApi() = default;

    GetVersionApi(GetVersionApi&) = delete;
    GetVersionApi(GetVersionApi&&) = delete;

    void operator=(GetVersionApi&) = delete;
    void operator=(GetVersionApi&&) = delete;

public:
    virtual std::string GetVariant() const override;

    virtual uint32_t GetMajor() const override;

    virtual uint32_t GetMinor() const override;

    virtual uint32_t GetBuild() const override;

    virtual bool IsWindows10OrGreater() const override;

private:
    uint32_t m_Version{};
    uint32_t m_MajorVersion{};
    uint32_t m_MinorVersion{};
    uint32_t m_Build{};
};
