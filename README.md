# Cement Engine [![Tests](https://github.com/Kolterdyx/CementEngine/actions/workflows/cmake.yml/badge.svg)](https://github.com/Kolterdyx/CementEngine/actions/workflows/cmake.yml)

The Cement Engine is a C++ engine designed for the development of 2D games/programs. It is designed to be as simple as
possible, while still being powerful enough to create a wide variety of applications. It is intended to be cross-platform,
but currently only officially supports Linux.

## Features

* Event System (not thread-safe)

## WIP

* Integrate EnTT
* Scene System

## TODO

* 2D rendering
* 2D physics
* UI layout
* Serialization
* Scene/Entity Editor
* Thread-safe Event System

## Building

### Dependencies

```
sudo apt install build-essential libboost-system-dev libboost-thread-dev libboost-program-options-dev libboost-test-dev libbox2d-dev libsfml-dev
```

### Configure
```bash
cmake -B ./build -DCMAKE_BUILD_TYPE=Debug
```

### Compile

Engine:
```bash
cmake --build ./build --config Debug --target CementEngine
```

Tests:
```bash
cmake --build ./build --config Debug --target CementEngineTests
```

## Licensing and Credits

* [License](LICENSE.txt)
* [Credits](CREDITS.md)
