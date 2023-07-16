#include <iostream>

#include "main.hpp"
#include "buffer.hpp"


int main()
{
    std::cout << "hello_world" << std::endl;

    {
        ThreadSafeBuffer buffer(1);
        int value = buffer.getThreadSafeBuffer();
        std::cout << "the value contained in buffer " << value << std::endl;
        int y = 5;

    }
    


    return 0;
}