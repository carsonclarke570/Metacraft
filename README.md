# Metacraft - A C-based Minecraft Clone

A C-based Minecraft clone written in OpenGL utilizing advanced rendering techniques such as PBR shading, environment mapping and deferred rendering. 

## Getting Started

Clone the repo to your machine.

### Prerequisites

Please ensure you have the latest version of cmake and OpenGL installed. You can install them with:

```
sudo apt install cmake
sudo apt install xorg-dev libgl1-mesa-dev libglu-dev libassimp-dev
```

### Installing

After cloning the repository and installing cmake and OpenGL:

Create a build directory in the project

```
mkdir build
cd build
```
Run CMake in that directory

```
cmake ..
```

Run the produced Makefile and execute the program
```
make
./Daybreak
```

The program shoud launch in a new window.

## Built With

* [glfw](https://github.com/glfw/glfw) - A multi-platform library for OpenGL, OpenGL ES, Vulkan, window and input 
* [assimp](https://github.com/assimp/assimp) - A 3D Object loading library
* [glad](https://github.com/Dav1dde/glad) - OpenGL loader
* [stb](https://github.com/nothings/stb) - Image loading library

## Contributing

Please contact Carson Clarke-Magrab at ctc7359@rit.edu if you are interested in contributing or make a pull request.

## Versioning

TO-DO

## Authors

* **Carson Clarke-Magrab** - *Engine Design* - [carsonclarke570](https://github.com/carsonclarke570)

See also the list of [contributors](https://github.com/carsonclarke570/mineCraft/graphs/contributors) who participated in this project.

## License

This project is licensed under the Apache License - see the [LICENSE.md](LICENSE) file for details

## Acknowledgments

* The existence of the GrubHub delivery service
