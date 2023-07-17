#pragma once 

#include <thread>
#include <mutex>
#include <shared_mutex>

// Base Class definition base off an Integer Buffer Type
    //    - m_buffer_ptr : pointer to the memory location of data type
    //    - m_smtx : gives a instance specific mutex lock for the reader writer problem and race condition 


class ThreadSafeBuffer{
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
        // Enetr Critical Section as Reader
        std::shared_lock<std::shared_mutex> lock(m_smtx);
        return (*m_buffer_ptr);
        // unlock due to drop out of scope
    }


    // Edit the Buffer for from external src
    int setThreadSafeBuffer()
    {
        // Enetr Critical Section as Writer
        std::unique_lock<std::shared_mutex> lock(m_smtx);
        return (*m_buffer_ptr);
        // unlock due to drop out of scope
    }

};