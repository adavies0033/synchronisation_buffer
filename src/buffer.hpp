#pragma once 

#include <thread>
#include <mutex>
#include <shared_mutex>

class ThreadSafeBuffer{
    // Base Class definition base off an Integer Buffer Type

    private:
    // ThreadSafebuffer Attributes
    int* m_buffer_ptr;
    mutable std::shared_mutex m_smtx;
    
    public:
    // ThreaSafeBuffer Constructor 
    ThreadSafeBuffer(int arg)
    {   
        // Memory Management placeholder
        std::cout << "Host Heap Memory Allocated {Buffer}" << std::endl;
        m_buffer_ptr = (int*) malloc(sizeof(int));
        (*m_buffer_ptr) = arg;
        
    }

    // ThreadSafeBuffer Destructor 
    ~ThreadSafeBuffer()
    {
         // Memory Management placeholder
         std::cout << "Host Heap Memory Deallocated {Buffer}" << std::endl;
         free(m_buffer_ptr);
    }

    // Access the Buffer for from external src
    int getThreadSafeBuffer()
    {
        return (*m_buffer_ptr);
    }


};