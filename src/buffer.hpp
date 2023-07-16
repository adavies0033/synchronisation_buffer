#pragma once 

class ThreadSafeBuffer{
    // Base Class definition base off an Integer Buffer Type
    
    public:
    // ThreaSafeBuffer Constructor 
    ThreadSafeBuffer(int value)
    {   
        // Memory Management placeholder
        std::cout << "Host Heap Memory Allocated {Buffer}" << std::endl;
        m_buffer_ptr = (int*) malloc(sizeof(int));
        
    }

    // ThreaSafeBuffer Destructor 
    ~ThreadSafeBuffer()
    {
         // Memory Management placeholder
         std::cout << "Host Heap Memory Deallocated {Buffer}" << std::endl;
    }

    // Obtain the Buffer's Pointer for external use
    int* getThreadSafeBuffer()
    {
        return m_buffer_ptr;
    }

    private:
    // ThreadSafebuffer Attributes
    int* m_buffer_ptr;

};