# Read version record from Windows

Demonstrate the different ways of reading the version information from Windows

## Version read from the operating system
![Read Windows Version](https://github.com/Therena/VersionOfWindows/blob/master/Images/ReadWindowsVersion.png?raw=true)

## Characteristic of the APIs

| API                           | Accuracy  | Deprecation | Documented   | Compatibility Mode | Compatibility Manifest |
|-------------------------------|-----------|-------------|--------------|--------------------|------------------------|
| GetVersion                    | yes       | yes         | User Mode    | dependent          | yes                    |
| GetVersionEx                  | yes       | yes         | User Mode    | dependent          | yes                    |
| Kernel32Library               | no        | no          | Undocumented | independent        | no                     |
| RegistryCurrentVersion        | no        | no          | Undocumented | independent        | no                     |
| RegistryCurrentVersionNumbers | unknown   | no          | Undocumented | independent        | no                     |
| RtlGetNtVersionNumbers        | unknown   | no          | Undocumented | independent        | no                     |
| RtlGetVersion                 | yes       | no          | Kernel Mode  | dependent          | no                     |
| VersionHelper                 | yes       | no          | User Mode    | independent        | yes                    |

## API descriptions

### API GetVersion

Microsoft documentation: [GetVersion on MSDN](https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getversion)

```cpp
#include <Windows.h>
const auto version = GetVersion();
```

The "GetVersion" WinAPI function returns the verion in one DWORD. The parts of the version can be extracted using the "LOWORD" and "LOWORD" macros.
The function is deprecated since Windows 8.1 and requires an Compatibility Manifest added to the application (See below). Furthermore it depends
on the Windows Compatibility Mode settings for the application which Windows Version will get returned (See section below).

### API GetVersionEx

Microsoft documentation: [GetVersionEx on MSDN](https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getversionexw)

```cpp
#include <Windows.h>
OSVERSIONINFOEX versionInformation{};
SecureZeroMemory(&versionInformation, sizeof(OSVERSIONINFOEX));
versionInformation.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
GetVersionEx(reinterpret_cast<OSVERSIONINFO*>(&versionInformation));
```

The "GetVersionEx" WinAPI function returns the Windows version using an struct as out parameter. The parts of the version are stored as member variables in the struct.
The function is deprecated since Windows 8.1 and requires an Compatibility Manifest added to the application (See below). Furthermore it depends
on the Windows Compatibility Mode settings for the application which Windows Version will get returned (See section below).

### API Kernel32Library

### API RegistryCurrentVersion

### API RegistryCurrentVersionNumbers

### API RtlGetNtVersionNumbers

### API RtlGetVersion

Microsoft documentation: [RtlGetVersion on MSDN](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlgetversion)

### API VersionHelper

Microsoft documentation: [VersionHelper on MSDN](https://learn.microsoft.com/en-us/windows/win32/sysinfo/version-helper-apis)

## Windows Compatibility Mode

## Compatibility Manifest

```xml
<?xml version="1.0" encoding="utf-8"?>
<assembly manifestVersion="1.0" xmlns="urn:schemas-microsoft-com:asm.v1">
    <assemblyIdentity version="1.0.0.0" name="VersionOfWindows.app"/>
    <!-- 
        This manifest entries are important for getting the Windows version correctly
        while using the Version Helper header
    -->
    <compatibility xmlns="urn:schemas-microsoft-com:compatibility.v1">
        <application>
            <!-- A list of the Windows versions that this application has been tested on
           and is designed to work with. Uncomment the appropriate elements
           and Windows will automatically select the most compatible environment. -->

            <!-- Windows Vista -->
            <supportedOS Id="{e2011457-1546-43c5-a5fe-008deee3d3f0}" />

            <!-- Windows 7 -->
            <supportedOS Id="{35138b9a-5d96-4fbd-8e2d-a2440225f93a}" />

            <!-- Windows 8 -->
            <supportedOS Id="{4a2f28e3-53b9-4441-ba9c-d69d4a4a6e38}" />

            <!-- Windows 8.1 -->
            <supportedOS Id="{1f676c76-80e1-4239-95bb-83d0f6d0da78}" />

            <!-- Windows 10 -->
            <supportedOS Id="{8e0f7a12-bfb3-4fe8-b9a5-48fd50a15a9a}" />
        </application>
    </compatibility>
</assembly>
```