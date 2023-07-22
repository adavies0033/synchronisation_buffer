#pragma once 

#include <iostream>

#include <thread>
#include <mutex>
#include <shared_mutex>

#include <opencv2/highgui.hpp>
#include <opencv2/cudaimgproc.hpp>


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
    cv::cuda::GpuMat m_device_buffer;
    mutable std::shared_mutex m_smtx;
    
    public:
    // ThreaSafeBuffer Constructor 
    ThreadSafeBuffer()
    {   
        // Memory Management placeholder
        std::cout << "Host Heap Memory Allocated {Buffer}" << std::endl;
        
    }

    // ThreadSafeBuffer Destructor 
    ~ThreadSafeBuffer()
    {
         // Memory Management placeholder
         std::cout << "Host Heap Memory Deallocated {Buffer}" << std::endl;
    }


};