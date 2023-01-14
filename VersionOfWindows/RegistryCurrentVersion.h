#pragma once

#include "IWindowsVersion.h"
#include <Windows.h>

class RegistryCurrentVersion : public IWindowsVersion
{
public:
    RegistryCurrentVersion();

    virtual ~RegistryCurrentVersion();

    RegistryCurrentVersion(RegistryCurrentVersion&) = delete;
    RegistryCurrentVersion(RegistryCurrentVersion&&) = delete;

    void operator=(RegistryCurrentVersion&) = delete;
    void operator=(RegistryCurrentVersion&&) = delete;

public:
    virtual std::string GetVariant() const override;

    virtual uint32_t GetMajor() const override;

    virtual uint32_t GetMinor() const override;

    virtual uint32_t GetBuild() const override;

    virtual bool IsWindows10OrGreater() const override;

private:
    HKEY m_CurrentVersionKey{};
    uint32_t m_MajorVersion{};
    uint32_t m_MinorVersion{};
    uint32_t m_BuildNumber{};

};
