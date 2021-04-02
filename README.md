![Project logo](/screenshots/logo.png?raw=true)

# Lynx Engine
Description...
## Some features.

- Cat friendly 
- ✨Magic ✨

## IDE setup
For now cmake is tested under Windows 10 with Visual Studio 2019, Visual Studio Code and CLion 2020.3  
**Note** Do not use VS integrated cmake generator, instead of that please install cmake from [here](https://github.com/Kitware/CMake/releases/)

### Installing MVC++ 
Even you want use something another than VS Studio you need to install basic Windows SDK, it's done by installing 
VS Studio (newer = better) with C++ support:  
#### I have VS Studio 2016 or newer case:

1. Open Visual Studio Installer
2. Choose your version in "Installed" tab
3. Click "Modify"
4. In section "Desktop & Mobile" check option "Desktop development with C++"  
#### I don't know what is Visual Studio:
Visual Studio can be downloaded from [here](https://visualstudio.microsoft.com/pl/) **you need to download Visual Studio, not Visual Studio Code or something**  
Click "Download Visual Studio" and go for "Community" version(it's free :yay:)
After common installation(please use default settings in installer), go to start menu and open "Visual Studio Installer", now follow steps shown above.


### Configuration for Visual Studio
We don't use here integrated VS support mechanism for cmake - it does not work as expected.
Instead we will use simple [cmake-gui application](https://github.com/Kitware/CMake/releases/)
1. Run cmake-gui(from menu start)
2. In first text field "Where is the source code", insert path to unpacked repository
3. Choose where you want store binaries(Using the same location as the source is recommended)
4. Click button "Configure"
5. In new window select Visual Studio version which you use, then click "Finish"
6. Wait for output message "Configuring done" (down section of the window)
7. Now you can click on "Generate" and start your IDE via "Open Project"

### Configuration for CLion
Make sure that you have installed MSVC++ compiler.
1. Run CLion
2. Click "Open" then select folder where located repository
3. Wait until button with bug icon gets green, Enjoy.
4. If bug is not getting green right click on CMakeLists.txt and use "Reload CMake project"

### Configuration for VS Code
Make sure that you have installed MSVC++ compiler.
1. Install extensions: [cmake](https://marketplace.visualstudio.com/items?itemName=twxs.cmake) and [C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
2. Open repository folder in VSCode
3. As the compiler choose: Visual Studio Community - amd64

### Building examples
When there is no use building examples, you can switch them off by setting variable "BUILD_EXAMPLES" to OFF in CMakeLists.txt file(row ~12) 

## Coding
 
**Note** do not create files by project explorer in IDE(especially in stupid Visual Studio). If working in CLion do not use option "Add to targets".  
**Keep files in designed structure**  
If you know what doing keep going, but remember missing or broken paths to files can cause future problem for other people.
After insertion/deletion of files please rerun cmake for your develop environment before compiling. 

## Issues
For IDE configuration issues please contact [Jakub Przystasz](https://github.com/jakubprzystasz)

## License
MIT
