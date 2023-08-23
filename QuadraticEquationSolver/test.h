#ifndef TEST_H
    #define TEST_H

    #include "calculations.h"

    enum test_results {
        TEST_CANT_OPEN_FILE,
        TEST_SUCCESS,
        TEST_COUNT_FAILURE,
        TEST_ROOTS_FAILURE
    };

    test_results test_program(const char *);
    void show_test_results(test_results, const EquationRoots *, const EquationRoots *);

#endif