# SFML Template

Basic SFML Template using CMake (see documentation below)

- [Cmake Documentation](https://cmake.org/cmake/help/latest/index.html)
- [SFML documentation](https://www.sfml-dev.org/)

## Compilation

To compile, the following commands can be used
```bash
mkdir build
cd build
cmake .. -DCMAKE_POLICY_VERSION_MINIMUM=3.5
cmake --build .
```
## Audio

Audio module is disabled by default, you can enable it by removing the following line in `CMakeLists.txt`
 `set(SFML_BUILD_AUDIO   OFF CACHE BOOL "" FORCE)`


## Network

Network module is also disabled by default.
Enable it by removing 
`set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)`

Make sure you have the required packages installed.

- Ubuntu / Debian
```sudo pacman -S mbedtls libssh2```

- Arch
```sudo pacman -S mbedtls libssh2```