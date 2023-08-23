#ifndef TEST_H

    #include "calculations.h"

    enum TEST_RESULTS {
        TEST_SUCCESS,
        TEST_COUNT_FAILURE,
        TEST_ROOTS_FAILURE
    };

    const char TEST_FILE[] = "test_arguments.txt";

    TEST_RESULTS test_program(void);
    void show_test_results(TEST_RESULTS, const EquationRoots *, const EquationRoots *);

    #define TEST_H
#endif