#include "WindowsVersionFactory.h"
#include "RtlGetVersionApi.h"
#include "RtlGetNtVersionNumbersApi.h"
#include "Kernel32Library.h"
#include "VersionHelper.h"
#include "GetVersionExApi.h"
#include "GetVersionApi.h"
#include "RegistryCurrentVersion.h"
#include "RegistryCurrentVersionNumbers.h"

std::shared_ptr<IWindowsVersion> WindowsVersionFactory::CreateRtlGetVersionApi()
{
    return std::make_unique<RtlGetVersionApi>();
}

std::shared_ptr<IWindowsVersion> WindowsVersionFactory::CreateRtlGetNtVersionNumbersApi()
{
    return std::make_unique<RtlGetNtVersionNumbersApi>();
}

std::shared_ptr<IWindowsVersion> WindowsVersionFactory::CreateKernel32Library()
{
    return std::make_unique<Kernel32Library>();
}

std::shared_ptr<IWindowsVersion> WindowsVersionFactory::CreateVersionHelper()
{
    return std::make_unique<VersionHelper>();
}

std::shared_ptr<IWindowsVersion> WindowsVersionFactory::CreateGetVersionExApi()
{
    return std::make_unique<GetVersionExApi>();
}

std::shared_ptr<IWindowsVersion> WindowsVersionFactory::CreateGetVersionApi()
{
    return std::make_unique<GetVersionApi>();
}

std::shared_ptr<IWindowsVersion> WindowsVersionFactory::CreateRegistryCurrentVersion()
{
    return std::make_unique<RegistryCurrentVersion>();
}

std::shared_ptr<IWindowsVersion> WindowsVersionFactory::CreateRegistryCurrentVersionNumbers()
{
    return std::make_unique<RegistryCurrentVersionNumbers>();
}