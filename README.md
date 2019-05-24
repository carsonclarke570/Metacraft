# mineCraft - (Hopefully) A C-based Minecraft Clone with Ray-Tracing

This is yet another Minecraft clone...   written in C...   with ray tracing...   if we get that far...   maybe...

## Getting Started

cloen da repo

### Prerequisites

Please ensure you have the latest versions of CMake and OpenGL (4.3) installed.

Install OpenGL:
```
sudo apt install xorg-dev libgl1-mesa-dev libglu-dev
```

Install CMake:
```
sudo apt install cmake
```

If the version of CMake is out of date (because Ubuntu), uninstall it with:
```
sudo apt purge --auto-remove cmake
```

and reinstall manualy with the latest version:
(i.e. version = 3.14, build = 3)
```
mkdir ~/temp
cd ~/temp
wget https://cmake.org/files/v<version>/cmake-<version>.<build>.tar.gz
tar -xzvf cmake-<version>.<build>.tar.gz
cd cmake-<version>.<build>/
./bootstrap
make -j4
sudo make install
cd ..
rm -r temp
```

### Building

Create a build directory in the project, run CMake in that directory,
run the generated Makefile, and execute the program:
```
mkdir build
cd build
cmake ..
make
./Daybreak
```

The program shoud launch in a new window.

## Built With

* [glfw](https://github.com/glfw/glfw) - A multi-platform library for OpenGL, OpenGL ES, Vulkan, window and input 
* [glad](https://github.com/Dav1dde/glad) - OpenGL loader
* [stb](https://github.com/nothings/stb) - Image loading library

## Contributing

TO-DO

## Versioning

TO-DO

## Authors

* **Carson Clarke-Magrab** - *Engine Design* - [carsonclarke570](https://github.com/carsonclarke570)
* **Wesley Dahar** - *Unrealistic Ideas* - [WesleyDahar](https://github.com/WesleyDahar)

See also the list of [contributors](https://github.com/carsonclarke570/mineCraft/graphs/contributors) who participated in this project.

## License

This project is licensed under the Apache License - see the [LICENSE.md](LICENSE) file for details

## Acknowledgments

* The existence of the GrubHub delivery service
* CTRL-Z
