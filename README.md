
# Multi-Threaded File Processing System in C++

## Overview

This is a multi-threaded file processing system implemented in C++. The system reads multiple text files concurrently, processes their contents (e.g., word counting), and logs the results to a file (`results.log`). The program demonstrates how to use threads, mutexes, condition variables, and thread-safe data structures in C++.

### Features
- **Multi-threaded Processing**: Files are processed in parallel using multiple threads.
- **Thread-Safe Queue**: Manages tasks (file paths) in a thread-safe manner.
- **Thread-Safe Logging**: Results are logged to a file concurrently from multiple threads.
- **File Operations**: Uses modern C++17 features like `std::filesystem` for directory and file operations.


## Prerequisites

- **C++17 or higher**
- **CMake**

## Build Instructions

1. **Install CMake** (if not installed):
    - On Ubuntu: `sudo apt install cmake`
    - On macOS: `brew install cmake`
  
2. **Build the project**:
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

3. **Run the program**:
    - Make sure you have a directory called `textfiles` with some text files to be processed.
    - Run the executable:
    ```bash
    ./MultiThreadedFileProcessing
    ```

4. **Results**:
    - Results will be logged to the `results.log` file in the current directory.

## How it Works

- **Task Queue**: A thread-safe queue (`TaskQueue`) holds file paths that need to be processed. The main thread pushes file paths into the queue, and worker threads pop tasks from the queue.
- **File Processing**: Each thread processes a file by counting the words and then logs the results.
- **Logger**: The `Logger` class is thread-safe and ensures that multiple threads can write to the log file without data corruption.

