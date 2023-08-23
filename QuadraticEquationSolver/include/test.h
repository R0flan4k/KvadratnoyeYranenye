#ifndef TEST_H
    #define TEST_H

    #include "calculations.h"

    enum test_results {
        TEST_SUCCESS,
        TEST_COUNT_FAILURE,
        TEST_ROOTS_FAILURE
    };

    const char TEST_FILE[] = "test_arguments.txt";

    test_results test_program(void);
    void show_test_results(test_results, const EquationRoots *, const EquationRoots *);

#endif