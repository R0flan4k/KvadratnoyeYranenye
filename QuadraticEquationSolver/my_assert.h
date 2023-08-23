#ifndef NDEBUG
    #ifndef MY_ASSERT_H
        #define MY_ASSERT_H

#define MY_ASSERT(X)\
 if (!(X))\
  { printf("Assertion failed: " #X ", line %d, file" __FILE__ ", date " __DATE__ ", function" "\n", __LINE__);\
   exit(EXIT_FAILURE);\
    }

    #endif 
#endif
    