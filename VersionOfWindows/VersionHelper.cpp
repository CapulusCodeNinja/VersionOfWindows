#include "VersionHelper.h"
#include <VersionHelpers.h>

std::string VersionHelper::GetVariant() const
{
    return "VersionHelper";
}

uint32_t VersionHelper::GetMajor() const
{
    return 0;
}

uint32_t VersionHelper::GetMinor() const
{
    return 0;
}

uint32_t VersionHelper::GetBuild() const
{
    return 0;
}

bool VersionHelper::IsWindows10OrGreater() const
{
    return ::IsWindows10OrGreater();
}