# _Simple_ SQLite Clone in C++

A lightweight `SQLite` clone written in `C++` to explore the internal workings and basic data structures of a database system. This project focuses on simplicity and learning, rather than full SQL feature support.

---

## Table of Contents

1. [Project Overview](#project-overview)
2. [Prerequisites](#prerequisites)
3. [CMake User Presets](#cmake-user-presets)
4. [Installing Dependencies](#installing-dependencies)
5. [Building the Project](#building-the-project)
6. [Running Tests](#running-tests)

---

## Project Overview

This project demonstrates how to build a simplified database engine in `C++`:

- Implements core storage and query mechanics.
- Uses `C++23` features for modern coding practices.
- Focuses on understanding database internals.

---

## Prerequisites

Ensure the following tools are installed:

- **C++ Compiler:** `clang++` (version 20.1.8 recommended)  
- **C++ Standard:** C++23  
- **Package Manager:** `conan` (version 2.19.1 recommended)  
- **Build System Generator:** `CMake` (version 4.0.3 recommended)  
- **Build System:** Unix Makefiles  

---

## CMake User Presets

Configure paths to your `clang` compiler and `make` binary in `CMakeUserPresets.json`:

```json
{
    "version": 4,
    "cmakeMinimumRequired": { "major": 4, "minor": 0, "patch": 3 },
    "configurePresets": [
        {
            "name": "user-base",
            "hidden": true,
            "description": "Base user preset for configuring path to Clang and make.",
            "cacheVariables": {
                "CMAKE_MAKE_PROGRAM": "/path/to/make",
                "CMAKE_C_COMPILER": "/path/to/clang",
                "CMAKE_CXX_COMPILER": "/path/to/clang++"
            }
        },
        {
            "name": "user-debug",
            "inherits": ["conan-debug", "user-base"],
            "hidden": false,
            "description": "Debug configuration using Clang"
        },
        {
            "name": "user-release",
            "inherits": ["conan-release", "user-base"],
            "hidden": false,
            "description": "Release configuration using Clang"
        }
    ],
    "buildPresets": [
        {
            "name": "user-build-debug",
            "inherits": "build-debug",
            "configurePreset": "user-debug",
            "description": "Build debug using Clang"
        },
        {
            "name": "user-build-release",
            "inherits": "build-release",
            "configurePreset": "user-release",
            "description": "Build release using Clang"
        }
    ],
    "testPresets": [
        {
            "name": "user-test-debug",
            "inherits": "test-debug",
            "configurePreset": "user-debug",
            "description": "Run tests using debug build with Clang"
        }
    ]
}
```

---

## Installing Dependencies

Run the following commands in the project root to install dependencies via `conan`:
```sh
# Debug build
conan install . --output-folder=build/debug --build=missing -s build_type=Debug

# Release build
conan install . --output-folder=build/release --build=missing -s build_type=Release
```

---

## Building the Project

1. <b>Configure Build Files</b> using CMake presets:
    ```sh
    # Debug
    cmake --preset=user-debug

    # Release
    cmake --preset=user-release
    ```

2. <b>Build Project Binaries</b>:
    ```sh
    # Debug
    cmake --build --preset=user-build-debug

    # Release
    cmake --build --preset=user-build-release
    ```

---

## Running Tests

Tests are built alongside the main project binary when using the debug build.

Run all tests using the `user-test-debug` preset:
```sh
ctest --preset user-test-debug
```