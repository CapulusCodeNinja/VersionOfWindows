#pragma once

#include <cstdint>
#include <string>

class IWindowsVersion
{
public:
    virtual ~IWindowsVersion() = default;

public:
    virtual std::string GetVariant() const = 0;

    virtual uint32_t GetMajor() const = 0;

    virtual uint32_t GetMinor() const = 0;

    virtual uint32_t GetBuild() const = 0;

    virtual bool IsWindows10OrGreater() const = 0;
};
