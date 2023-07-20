#include "main.hpp"
#include "buffer.hpp"

#define INITALIZATION_STANDARD 0

#ifdef NDEBUG

#  define assert(condition) ((void)0)
#else
#  define assert(condition) /*implementation defined*/
#endif


void test_getter_and_setter(ThreadSafeBuffer* buffer)
{
    int test_case = INITALIZATION_STANDARD;
    assert( 0 == (*buffer)->getThreadSafeBuffer());
    (*buffer).setThreadSafeBuffer(test_case);
    assert( test_case == (*buffer)->getThreadSafeBuffer());

    std::cout << "    - Passed void test_getter_and_setter!" << std::endl;
}





// // ------------------------------------------------------------



int main()
{
    
    ThreadSafeBuffer buffer(INITALIZATION_STANDARD);

    test_getter_and_setter(&buffer);


    return 0;
}