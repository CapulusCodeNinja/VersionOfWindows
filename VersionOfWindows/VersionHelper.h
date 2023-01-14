#pragma once

#include "IWindowsVersion.h"
#include <Windows.h>

class VersionHelper : public IWindowsVersion
{
public:
    VersionHelper() = default;

    virtual ~VersionHelper() = default;

    VersionHelper(VersionHelper&) = delete;
    VersionHelper(VersionHelper&&) = delete;

    void operator=(VersionHelper&) = delete;
    void operator=(VersionHelper&&) = delete;

public:
    virtual std::string GetVariant() const override;

    virtual uint32_t GetMajor() const override;

    virtual uint32_t GetMinor() const override;

    virtual uint32_t GetBuild() const override;

    virtual bool IsWindows10OrGreater() const override;
};
