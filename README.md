# Simple C Server

A simple C build example that embbedds text and binary files in the final binary.

Steps to compile
```
cmake -S . -B build
cmake --build build
./build/SimpleServer
```

One go command
```
cmake -S . -B build && cmake --build build && ./build/SimpleServer
```
