#pragma once 

#include <iostream>

#include <thread>
#include <mutex>
#include <shared_mutex>


#define FRAME_HEIGHT 2048
#define FRAME_WIDTH 1536
#define MAT_TYPE CV_8UC3


// Base Class definition base off an Integer Buffer Type
    //    - m_buffer_ptr : pointer to the memory location of data type
    //    - m_smtx : gives a instance specific mutex lock for the reader writer problem and race condition 


class ThreadSafeBuffer{
    private:
    // ThreadSafebuffer Attributes
    cv::Mat m_host_buffer;
    cv::cuda::GpuMat m_host_buffer;
    mutable std::shared_mutex m_smtx;
    
    public:
    // ThreaSafeBuffer Constructor 
    ThreadSafeBuffer()
    {   
        // Memory Management placeholder
        std::cout << "Host Heap Memory Allocated {Buffer}" << std::endl;
        m_buffer_ptr = (int*) malloc(sizeof(int));
        
        
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
    void setThreadSafeBuffer(int arg)
    {
        // Enetr Critical Section as Writer
        std::unique_lock<std::shared_mutex> lock(m_smtx);
        (*m_buffer_ptr) = arg;
        // unlock due to drop out of scope
    }

};