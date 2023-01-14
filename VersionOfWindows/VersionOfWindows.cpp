#include <iostream>
#include "WindowsVersionFactory.h"
#include <sstream>

void PrintWindowsVersion(std::shared_ptr<IWindowsVersion> version)
{
    auto variantWhitespace = "\t\t\t";
    const auto variant = version->GetVariant();

    if (29 <= variant.length())
    {
        variantWhitespace = "\t";
    }
    else if (19 <= variant.length())
    {
        variantWhitespace = "\t\t";
    }

    std::stringstream versionStream;
    versionStream << version->GetMajor() << "." << version->GetMinor() << "." << version->GetBuild();

    auto versionWhitespace = "\t\t";
    const auto versionString = versionStream.str();
    if (5 < versionString.length())
    {
        versionWhitespace = "\t";
    }

    std::cout << "Windows version from " << version->GetVariant() << ": " << 
        variantWhitespace << versionString << versionWhitespace <<
        " - Is Windows 10 or greater: " << (version->IsWindows10OrGreater() ? "true" : "false") << std::endl;
}

int main()
{
    try
    {
        PrintWindowsVersion(WindowsVersionFactory::CreateRtlGetVersionApi());
        PrintWindowsVersion(WindowsVersionFactory::CreateRtlGetNtVersionNumbersApi());
        PrintWindowsVersion(WindowsVersionFactory::CreateKernel32Library());
        PrintWindowsVersion(WindowsVersionFactory::CreateVersionHelper());
        PrintWindowsVersion(WindowsVersionFactory::CreateGetVersionExApi());
        PrintWindowsVersion(WindowsVersionFactory::CreateGetVersionApi());
        PrintWindowsVersion(WindowsVersionFactory::CreateRegistryCurrentVersion());
        PrintWindowsVersion(WindowsVersionFactory::CreateRegistryCurrentVersionNumbers());

        return 0;
    }
    catch (const std::exception error)
    {
        std::cerr << "Exception while getting the Windows version: " << error.what() << std::endl;
        return 1;
    }
}
