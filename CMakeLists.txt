
cmake_minimum_required(VERSION 3.27)
project(synchronisation_buffer)

# Set C++ Standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# FIND LIBRARIES
find_package(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

find_package(CUDA REQUIRED)
message(STATUS "    libraries: ${CUDA_LIBS}")

# INCLUDE HEADERS
include_directories(${OpenCV_INCLUDE_DIRS})
# Target the only executable
add_executable(${PROJECT_NAME}
    src/main.cpp 
    src/main.hpp 
    src/buffer.hpp 
)



