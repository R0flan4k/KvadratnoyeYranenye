#ifndef TEST_H

    enum TEST_RESULTS {
        TEST_SUCCES,
        TEST_COUNT_FAILURE,
        TEST_ROOTS_FAILURE
    };

    const char TEST_FILE[] = "test_arguments.txt";

    TEST_RESULTS test_program(void);
    bool is_first_to_first(const float program_root1, const float program_root2, const float right_root1, const float right_root2);
    bool is_first_to_second(const float program_root1, const float program_root2, const float right_root1, const float right_root2);
    bool is_equal_equation_roots(const float program_root1, const float program_root2, const float right_root1, const float right_root2);

    #define TEST_H
#endif