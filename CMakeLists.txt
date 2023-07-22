
cmake_minimum_required(VERSION 3.26)
project(synchronisation_buffer)

# Set CMake Policies to surpress warnings regarding findCUDA
cmake_policy(SET CMP0146 OLD)

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
message(STATUS "    include path: ${CUDA_INCLUDE_DIRS}")

# INCLUDE HEADERS
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CUDA_INCLUDE_DIRS})

# LINK LIBRARIES
link_libraries(${OpenCV_LIBS})
link_libraries(${CUDA_LIBS})

# Target the only executable
add_executable(${PROJECT_NAME}
    src/main.cpp 
    src/main.hpp 
    src/buffer.hpp 
)



