#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "calculations.h"
#include "test.h"

static bool is_equal_equation_roots(const float program_root1, const float program_root2, const float right_root1, const float right_root2);

TEST_RESULTS test_program(void)
{
    EquationCoefficients test_coeffs = {0.0, 0.0, 0.0};
    EquationRoots right_solution = {ROOTS_COUNT_ZERO, 0.0, 0.0};
    EquationRoots program_solution = {ROOTS_COUNT_ZERO, 0.0, 0.0};
    FILE * fp = 0;
    int test_string_number = 1;


    if ((fp = fopen(TEST_FILE, "r")) == NULL)
    {
        puts("Can't open the file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%f %f %f %d %f %f", &test_coeffs.a, &test_coeffs.b, &test_coeffs.c, 
                  (int *) &right_solution.count, &right_solution.first_root, &right_solution.second_root) 
                  == 6) 
    {
        program_solution = solve_equation(&test_coeffs);

        if (program_solution.count != right_solution.count)
        {
            fclose(fp);

            show_test_results(TEST_COUNT_FAILURE, &program_solution, &right_solution);
            printf("%s: string %d\n", TEST_FILE, test_string_number);

            return TEST_COUNT_FAILURE;
        }
        else if (!is_equal_equation_roots(program_solution.first_root, program_solution.second_root, right_solution.first_root, right_solution.second_root))
        {
            fclose(fp);

            show_test_results(TEST_ROOTS_FAILURE, &program_solution, &right_solution);
            printf("%s: string %d\n", TEST_FILE, test_string_number);
            return TEST_ROOTS_FAILURE;
        }

        test_string_number++;
    }

    fclose(fp);

    puts("Test successfully passed");
    
    return TEST_SUCCESS;
}


static bool is_equal_equation_roots(const float program_root1, const float program_root2, const float right_root1, const float right_root2)
{
    bool first_to_first = true;
    bool first_to_second = true;

    first_to_first = (is_equal_float(program_root1, right_root1) && is_equal_float(program_root2, right_root2));
    first_to_second = (is_equal_float(program_root1, right_root2) && is_equal_float(program_root2, right_root1));

    return (first_to_first || first_to_second);
}


void show_test_results(TEST_RESULTS test_result, const EquationRoots * program_solution, const EquationRoots * right_solution)
{
    switch (test_result)
    {
        case TEST_SUCCESS:
            puts("The test successfully passed");
            break;

        case TEST_COUNT_FAILURE:
            puts ("Test error: wrong count");
            printf("Expected count: %d\n", (int) right_solution->count);
            printf("Program count: %d\n", (int) program_solution->count);
            break;

        case TEST_ROOTS_FAILURE:
            puts("Test error: wrong roots");
            printf("Expected roots: %f and %f\n", right_solution->first_root, right_solution->second_root);
            printf("Program roots: %f and %f\n", program_solution->first_root, program_solution->second_root);
            break;
        default:
            assert(0 && "TEST RESULT OUTPUT ERROR");
            break;
    }
}