#pragma once

#include "IWindowsVersion.h"
#include <memory>

class WindowsVersionFactory
{
public:
    WindowsVersionFactory() = delete;

    WindowsVersionFactory(WindowsVersionFactory&) = delete;
    WindowsVersionFactory(WindowsVersionFactory&&) = delete;

    void operator=(WindowsVersionFactory&) = delete;
    void operator=(WindowsVersionFactory&&) = delete;

public:
    static std::shared_ptr<IWindowsVersion> CreateRtlGetVersionApi();

    static std::shared_ptr<IWindowsVersion> CreateRtlGetNtVersionNumbersApi();

    static std::shared_ptr<IWindowsVersion> CreateKernel32Library();

    static std::shared_ptr<IWindowsVersion> CreateVersionHelper();

    static std::shared_ptr<IWindowsVersion> CreateGetVersionExApi();

    static std::shared_ptr<IWindowsVersion> CreateGetVersionApi();

    static std::shared_ptr<IWindowsVersion> CreateRegistryCurrentVersion();

    static std::shared_ptr<IWindowsVersion> CreateRegistryCurrentVersionNumbers();
};