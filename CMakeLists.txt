
cmake_minimum_required(VERSION 3.10)
project(MultiThreadedFileProcessing)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(MultiThreadedFileProcessing 
    src/main.cpp 
    src/FileProcessor.cpp 
    src/Logger.cpp 
    src/TaskQueue.cpp
)
