# synchronisation_buffer

A C++ Generic Thread Safe Buffer Class using synchronisation primitives to be used in personal multi-threaded projects. 
The thread safe defintion operated under is that it will always produce correct results when call repeatedly from 
multiple concurrent threads. 

Synchronization Primitives for Class Design:
1) Mutex
2) Shared Mutex
3) Conditional Variables 
4) Semaphores



References:
    - Chris Kanich | https://www.youtube.com/@ChrisKanich