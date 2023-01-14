# Read version record from Windows

Demonstrate the different ways of reading the version information from Windows

![Read Windows Version](https://github.com/Therena/VersionOfWindows/blob/master/Images/ReadWindowsVersion.png?raw=true)

| API                           | Accuracy  | Deprecation | Documented        | Compatibility Mode | Manifest needed |
|-------------------------------|-----------|-------------|-------------------|--------------------|-----------------|
| GetVersion                    |           | Deprecated  | UM: yes / KM: no  | dependent          | yes             |
| GetVersionEx                  |           | Deprecated  | UM: yes / KM: no  | dependent          | yes             |
| Kernel32Library               | no        |             | UM: no  / KM: no  | independent        | no              |
| RegistryCurrentVersion        | no        |             | UM: no  / KM: no  | independent        | no              |
| RegistryCurrentVersionNumbers | undefined |             | UM: no  / KM: no  | independent        | no              |
| RtlGetNtVersionNumbers        | undefined |             | UM: no  / KM: no  | independent        | no              |
| RtlGetVersion                 |           |             | UM: no  / KM: yes | dependent          | no              |
| VersionHelper                 |           |             | UM: yes / KM: no  | independent        | yes             |

# API descriptions

## API GetVersion

Microsoft documentation: [GetVersion on MSDN](https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getversion)

## API GetVersionEx

Microsoft documentation: [GetVersionEx on MSDN](https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getversionexw)

## API Kernel32Library

## API RegistryCurrentVersion

## API RegistryCurrentVersionNumbers

## API RtlGetNtVersionNumbers

## API RtlGetVersion

Microsoft documentation: [RtlGetVersion on MSDN](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlgetversion)

## API VersionHelper

Microsoft documentation: [VersionHelper on MSDN](https://learn.microsoft.com/en-us/windows/win32/sysinfo/version-helper-apis)

# Windows Compatibility Mode 