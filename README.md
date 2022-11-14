[![Tests](https://github.com/Kolterdyx/CementEngine/actions/workflows/cmake.yml/badge.svg)](https://github.com/Kolterdyx/CementEngine/actions/workflows/cmake.yml)

# Cement Engine

The Cement Engine is a C++ engine designed for the development of 2D games/programs. It is designed to be as simple as
possible, while still being powerful enough to create a wide variety of applications. It is intended to be cross-platform,
but currently only officially supports Linux.

## Features

* Event IEntitySystem

## TODO

* 2D rendering
* Entity Component IEntitySystem


## Building

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

