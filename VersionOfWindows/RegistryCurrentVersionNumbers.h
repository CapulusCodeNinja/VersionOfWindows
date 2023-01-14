#pragma once

#include "IWindowsVersion.h"
#include <Windows.h>

class RegistryCurrentVersionNumbers : public IWindowsVersion
{
public:
    RegistryCurrentVersionNumbers();

    virtual ~RegistryCurrentVersionNumbers();

    RegistryCurrentVersionNumbers(RegistryCurrentVersionNumbers&) = delete;
    RegistryCurrentVersionNumbers(RegistryCurrentVersionNumbers&&) = delete;

    void operator=(RegistryCurrentVersionNumbers&) = delete;
    void operator=(RegistryCurrentVersionNumbers&&) = delete;

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
