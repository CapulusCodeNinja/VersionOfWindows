#pragma once

#include "IWindowsVersion.h"
#include <Windows.h>
#include <vector>

class Kernel32Library : public IWindowsVersion
{
public:
    Kernel32Library();

    virtual ~Kernel32Library();

    Kernel32Library(Kernel32Library&) = delete;
    Kernel32Library(Kernel32Library&&) = delete;

    void operator=(Kernel32Library&) = delete;
    void operator=(Kernel32Library&&) = delete;

public:
    virtual std::string GetVariant() const override;

    virtual uint32_t GetMajor() const override;

    virtual uint32_t GetMinor() const override;

    virtual uint32_t GetBuild() const override;

    virtual bool IsWindows10OrGreater() const override;

private:
    VS_FIXEDFILEINFO* m_Version{};
    std::vector<byte> m_VersionInformationBuffer{};
};
