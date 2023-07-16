# synchronisation_buffer

A C++ Generic Thread Safe Buffer Class using synchronisation primitives to be used in personal multi-threaded projects. 
The thread safe defintion operated under is that it will always produce correct results when call repeatedly from 
multiple concurrent threads. 

Synchronization Primitives for Class Design:
1) Mutex
2) Shared Mutex
3) Conditional Variables 
4) Semaphores

In Case Unfamiliar with CMake:

To run the executables starting from project root,
```
cd build
cmake ..
make 
./synchronisation_buffer
```

References (Non specific format):

    - Youtube Channel | Chris Kanich | https://www.youtube.com/@ChrisKanich
    
    - Website | cppreference.com | https://en.cppreference.com/w/cpp/language/classes
