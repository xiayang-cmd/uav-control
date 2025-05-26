# UAV Control

This repository contains a basic C++ project for sending TCP command frames to a UAV.

## Building

```bash
mkdir build && cd build
cmake ..
make
```

## Running

The example in `examples/main.cpp` connects to `127.0.0.1` on port `9000` and sends a simple command frame. Adjust the host, port, and frame contents as needed for your UAV.
