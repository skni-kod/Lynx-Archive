![Project logo](/screenshots/logo.png?raw=true)

# Lynx Engine
Description...
## Some features.

- Cat friendly 
- ✨Magic ✨

## IDE setup
For now cmake is tested only under Windows 10 with Visual Studio 2019.
Do not use VS integrated cmake generator, instead of that please install cmake from [here](https://github.com/Kitware/CMake/releases/)
1. Run cmake-gui(from menu start)
2. In first text field "Where is the source code", insert path to unpacked repository
3. Choose where you want store binaries(Using the same location as the source is recommended)
4. Click button "Configure"
5. In new window select Visual Studio version which you use, then click "Finish"
6. Wait for output message "Configuring done" (down section of the window)
7. Now you can click on "Generate" and start your IDE via "Open Project"

## Coding
 
**Note** do not create files by project explorer in IDE(especially in stupid Visual Studio)
If you know what doing keep going, but remember missing or broken paths to files can cause future problem for other people.
After insertion/deletion of files please rerun cmake for your develop environment before compiling. 

## Issues
For IDE configuration issues please contact [Jakub Przystasz](https://github.com/jakubprzystasz)

## License
MIT
