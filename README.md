![Project logo](/images/logo.png?raw=true)

# Lynx Engine
Description...
## Some features.

- Cat friendly 
- ✨Magic ✨

## IDE setup
For now cmake is tested under Windows 10 with Visual Studio 2019, Visual Studio Code and CLion 2020.3  
**Note** Do not use VS integrated cmake generator, instead of that please install cmake from [here](https://github.com/Kitware/CMake/releases/)

## Required software
Before starting off you need to install some stuff:

### Installing MVC++ 
Even you want use something another than VS Studio you need to install basic Windows SDK, it's done by installing 
VS Studio with C++ support:  
#### I have VS Studio 2016 or newer:
1. Open Visual Studio Installer
2. Choose your version in "Installed" tab
3. Click "Modify"
4. In section "Desktop & Mobile" check option "Desktop development with C++" 
5. Apply changes clicking on "Modify"(bottom right corner)
#### I don't know what is Visual Studio:
Visual Studio can be downloaded from [here](https://visualstudio.microsoft.com/pl/) **you need to download Visual Studio, not Visual Studio Code or something**  
Click "Download Visual Studio" and go for "Community" version(it's free :yay:)
After common installation(please use default settings in installer), go to start menu and open "Visual Studio Installer", now follow steps shown in section *I have VS Studio 2016 or newer*.

### Installing cmake
1. Open in browser [cmake](https://github.com/Kitware/CMake/releases/)
2. Download latest release (i recommend to use windows-x86_64.msi version)
3. Install downloaded file
4. Add cmake path to PATH variable

#### Adding cmake path to PATH
For Windows 7/8/10:
1. Open  "This Computer" or something like that:
![Open computer](/screenshots/.png?raw=true)
2. Click on "Advanced computer settings"
![Open computer](/screenshots/.png?raw=true)
3. Open tab "Advanced" then click button "Environment variables"
![Open computer](/screenshots/.png?raw=true)
4. Find Path:
![Open computer](/screenshots/.png?raw=true)
5. Click New and put path to cmake:
![Open computer](/screenshots/.png?raw=true)
6. Save settings by clicking Ok,Apply etc.

### Configuration for Visual Studio
We don't use here integrated VS support mechanism for cmake - it does not work as expected.
Instead we will use simple [cmake-gui application](https://github.com/Kitware/CMake/releases/)
1. Run cmake-gui(from menu start)
2. In first text field "Where is the source code", insert path to unpacked repository
3. Choose where you want to store binaries(Using the same location as the source is recommended)
4. Click button "Configure"
5. In new window select Visual Studio version which you use, then click "Finish"
6. Wait for output message "Configuring done" (bottom section of the window)
7. Now you can click on "Generate" and start your IDE via "Open Project"

### Configuration for CLion
Make sure that you have installed MSVC++ compiler.
1. Run CLion
2. Click "Open", then select folder where repository is located
3. Wait until button with bug icon gets green, Enjoy.
4. If bug is not getting green right click on CMakeLists.txt and use "Reload CMake project"

### Configuration for VS Code
Make sure that you have installed MSVC++ compiler.
1. Install extensions: [cmake](https://marketplace.visualstudio.com/items?itemName=twxs.cmake) and [C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
2. Open repository folder in VSCode
3. As the compiler choose: Visual Studio Community - amd64

### Building examples
When tno build examples are being used, you can switch them off by setting variable "BUILD_EXAMPLES" to OFF in CMakeLists.txt file(row no. ~12) 

## Coding
**The first rule of a good friend of Lynx - keep all files in designed structure** 
**Note**: do not create files using project explorer in IDE - especially in Visual Studio.  
If working in CLion you can add files via project explorer but be sure to not use option "Add to targets".
If you know what doing keep going, but remember missing or broken paths to files can cause future problems for other people.  
After insertion/deletion of files please rerun cmake for your develop environment before compiling - CLion does it automatically, but (stupid) Visual Studio and Visual Studio Code doesn't.

## Issues
For IDE configuration issues please contact [Jakub Przystasz](https://github.com/jakubprzystasz)
To avoid issues use path for repository without non ascii characters, white spaces etc.
## License
MIT
