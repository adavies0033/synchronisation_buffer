#pragma once 

#include <iostream>

#include <thread>
#include <mutex>
#include <shared_mutex>

#include <opencv2/highgui.hpp>
#include <opencv2/cudaimgproc.hpp>

#include <cuda_runtime.h>


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
    // ThreadSafeBuffer Constructor 
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

    //ThreadSafeBuffer Device Infomation Getter
    void get_device_info()
    {
        // Device info
        #ifdef x86_64
            cout << "x86_64" << endl;
        #endif
        #ifdef __arm__
            cout << "__arm__" << endl;
        #endif
        #ifdef __aarch64__
            cout << "__aarch64__" << endl;
        #endif
        cv::cuda::printShortCudaDeviceInfo(cv::cuda::getDevice());
        int cuda_devices_number = cv::cuda::getCudaEnabledDeviceCount();
        std::cout << "CUDA Device(s) Number: "<< cuda_devices_number << std::endl;
        cv::cuda::DeviceInfo _deviceInfo;
        bool _isd_evice_compatible = _deviceInfo.isCompatible();
        std::cout << "CUDA Device(s) Compatible: " << _isd_evice_compatible << std::endl;
        // get number of device gpus
        int _device_count = cv::cuda::getCudaEnabledDeviceCount();  
        std::cout << "CUDA Device(s) Count: " << _device_count << std::endl;
        
        // cudaGetDeviceProperties
        cudaDeviceProp _device_prop;
        cudaGetDeviceProperties(&_device_prop, 0);
        std::cout << "CUDA Device(s) Properties: " << std::endl;
        std::cout << "  - name: " << _device_prop.name << std::endl;
        std::cout << "  - totalGlobalMem: " << _device_prop.totalGlobalMem << std::endl;
        std::cout << "  - sharedMemPerBlock: " << _device_prop.sharedMemPerBlock << std::endl;
        std::cout << "  - regsPerBlock: " << _device_prop.regsPerBlock << std::endl;
        std::cout << "  - warpSize: " << _device_prop.warpSize << std::endl;
        std::cout << "  - memPitch: " << _device_prop.memPitch << std::endl;
        std::cout << "  - maxThreadsPerBlock: " << _device_prop.maxThreadsPerBlock << std::endl;
        std::cout << "  - maxThreadsDim[3]: " << _device_prop.maxThreadsDim[3] << std::endl;
        std::cout << "  - maxGridSize[3]: " << _device_prop.maxGridSize[3] << std::endl;
        std::cout << "  - totalConstMem: " << _device_prop.totalConstMem << std::endl;
        std::cout << "  - major: " << _device_prop.major << std::endl;
        std::cout << "  - minor: " << _device_prop.minor << std::endl;
        std::cout << "  - clockRate: " << _device_prop.clockRate << std::endl;
        std::cout << "  - textureAlignment: " << _device_prop.textureAlignment << std::endl;
        std::cout << "  - deviceOverlap: " << _device_prop.deviceOverlap << std::endl;
        std::cout << "  - multiProcessorCount: " << _device_prop.multiProcessorCount << std::endl;
        std::cout << "  - kernelExecTimeoutEnabled: " << _device_prop.kernelExecTimeoutEnabled << std::endl;
        std::cout << "  - integrated: " << _device_prop.integrated << std::endl;
        std::cout << "  - canMapHostMemory: " << _device_prop.canMapHostMemory << std::endl;
        std::cout << "  - computeMode: " << _device_prop.computeMode << std::endl;        
    }


};