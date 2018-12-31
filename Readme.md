This sample was made to make life easy for people who searching for UVC example that is in,https://docs.microsoft.com/en-us/windows-hardware/drivers/stream/building-the-extension-unit-sample-control

Open a commandline with WDK environment. Note that latest(Dont know when this become the default) WDK is integrated with Visual studio. Therefore, we dont have a build.exe. 
However, you can use https://networchestration.wordpress.com/2017/12/10/wdk-download/ (use Windows 7 (WDK 7.1.0))to get a WDK(past it is called DDK) that can be used with commandline. After installation use "x64 free build environment" from start menu.
Change directory in the source code
Use ```Build -cZg``` to build 

Keywords :
Windows, Win32, DDK, WDK, UVC, USB video class, C, C++
