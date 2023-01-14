# Read version record from Windows

Demonstrate the different ways of reading the version information from Windows

## Version read from the operating system
![Read Windows Version](https://github.com/Therena/VersionOfWindows/blob/master/Images/ReadWindowsVersion.png?raw=true)

![Read Windows Version](https://github.com/Therena/VersionOfWindows/blob/master/Images/CurrentWindowsInstalltion.png?raw=true)

## Characteristic of the APIs

| API                           | Accuracy  | Deprecation | Documented   | Compatibility Mode | Manifest needed |
|-------------------------------|-----------|-------------|--------------|--------------------|-----------------|
| GetVersion                    |           | Deprecated  | User Mode    | dependent          | yes             |
| GetVersionEx                  |           | Deprecated  | User Mode    | dependent          | yes             |
| Kernel32Library               | no        |             | Undocumented | independent        | no              |
| RegistryCurrentVersion        | no        |             | Undocumented | independent        | no              |
| RegistryCurrentVersionNumbers | undefined |             | Undocumented | independent        | no              |
| RtlGetNtVersionNumbers        | undefined |             | Undocumented | independent        | no              |
| RtlGetVersion                 |           |             | Kernel Mode  | dependent          | no              |
| VersionHelper                 |           |             | User Mode    | independent        | yes             |

## API descriptions

### API GetVersion

Microsoft documentation: [GetVersion on MSDN](https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getversion)

### API GetVersionEx

Microsoft documentation: [GetVersionEx on MSDN](https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getversionexw)

### API Kernel32Library

### API RegistryCurrentVersion

### API RegistryCurrentVersionNumbers

### API RtlGetNtVersionNumbers

### API RtlGetVersion

Microsoft documentation: [RtlGetVersion on MSDN](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlgetversion)

### API VersionHelper

Microsoft documentation: [VersionHelper on MSDN](https://learn.microsoft.com/en-us/windows/win32/sysinfo/version-helper-apis)

## Windows Compatibility Mode 