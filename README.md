# synchronisation_buffer 

A C++ Generic Thread Safe Buffer Class using synchronisation primitives to be used in personal multi-threaded projects. 
The thread safe defintion operated under is that it will always produce correct results when call repeatedly from 
multiple concurrent threads. 

Synchronization Primitives for Class Design:
1) Mutex
2) Shared Mutex
3) Conditional Variables 
4) Semaphores

This repository is a sub-project for a private project to develop skills to complete existing tasks. The development of the Class defs. in the Header file is to make 
it directly portable with an existing project. The branches of this repo will be for different buffer types, the base implementation is an integer type 
as it is the simplest example of implemntation and can be tested the easiest. 

### In Case Unfamiliar with CMake:

To run the executables starting from project root,
```
cd build
cmake ..
make 
./synchronisation_buffer
```

### References (Non specific format):

    - Youtube Channel | Chris Kanich | https://www.youtube.com/@ChrisKanich
    
    - Website | cppreference.com | https://en.cppreference.com/w/cpp/language/classes

    - An Introduction to Multithreading in C++20 - Anthony Williams - CppCon 2022 | https://www.youtube.com/watch?v=A7sVFJLJM-A
