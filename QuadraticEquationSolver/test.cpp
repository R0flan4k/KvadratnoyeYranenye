/////////////////////////////////////////////////////////////////////////
/// \file test.cpp
/// \brief Testing the operation of the computational part of the program.
/////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>      

#include "calculations.h"
#include "test.h"
#include "input-output.h"
#include "my_assert.h"

/////////////////////////////////////////////////////////////////////////
/// \brief Check is equal calculated and right roog.
/// \param[in] program_root1 Calculated first root.
/// \param[in] program_root2 Calculated second root.
/// \param[in] right_root1 Right first root from tests file.
/// \param[in] right_root2 Right second root from tests file.
/// \return Is program roots equal to right roots.
/////////////////////////////////////////////////////////////////////////
static bool is_equal_equation_roots(const float program_root1, const float program_root2, const float right_root1, const float right_root2);

/////////////////////////////////////////////////////////////////////////
/// \brief Show results of tests.
/// \param[in] test_result Result of tests (succes or failure).
/// \param[in] program_solution Calculated roots and count point.
/// \param[in] right_solution Right roots and count from tests file.
/////////////////////////////////////////////////////////////////////////
static void show_test_results(TestResults test_result, const EquationRoots * program_solution, const EquationRoots * right_solution);

TestResults test_program(const char * test_file)
{
    EquationCoefficients test_coeffs = {0.0, 0.0, 0.0};
    EquationRoots right_solution = {ROOTS_COUNT_ZERO, 0.0, 0.0};
    EquationRoots program_solution = {ROOTS_COUNT_ZERO, 0.0, 0.0};
    FILE * fp = 0;
    int test_string_number = 1;

    if ((fp = fopen(test_file, "r")) == NULL)
    {
        puts("Can't open the file.");
        return TEST_CANT_OPEN_FILE;
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
            printf("%s: string %d\n", test_file, test_string_number);

            return TEST_COUNT_FAILURE;
        }
        else if (!is_equal_equation_roots(program_solution.first_root, program_solution.second_root, 
                 right_solution.first_root, right_solution.second_root))
        {
            show_test_results(TEST_ROOTS_FAILURE, &program_solution, &right_solution);
            printf("%s: string %d\n", test_file, test_string_number);

            return TEST_ROOTS_FAILURE;
        }

        test_string_number++;
    }

    fclose(fp);

    show_test_results(TEST_SUCCESS, &program_solution, &right_solution);

    return TEST_SUCCESS;
}


static bool is_equal_equation_roots(const float program_root1, const float program_root2, const float right_root1, const float right_root2)
{
    bool first_to_first  = true;
    bool first_to_second = true;

    first_to_first  = (is_equal_float(program_root1, right_root1) && is_equal_float(program_root2, right_root2));
    first_to_second = (is_equal_float(program_root1, right_root2) && is_equal_float(program_root2, right_root1));

    return (first_to_first || first_to_second);
}


static void show_test_results(TestResults test_result, const EquationRoots * program_solution, const EquationRoots * right_solution)
{
    switch (test_result)
    {
        case TEST_SUCCESS:
            puts("");
            puts("The tests successfully passed.");
            puts ("");
            break;

        case TEST_COUNT_FAILURE:
            puts ("");
            puts ("Test error: wrong count.");
            printf("Expected count: " GREEN_COLOR "%d" DEFAULT_COLOR "\n", (int) right_solution->count);
            printf("Program count:  " RED_COLOR "%d" DEFAULT_COLOR "\n", (int) program_solution->count);
            puts ("");
            break;

        case TEST_ROOTS_FAILURE:
            puts ("");
            puts("Test error: wrong roots.");
            printf("Expected roots: " GREEN_COLOR "%+f and %+f" DEFAULT_COLOR "\n", right_solution->first_root, right_solution->second_root);
            printf("Program roots:  " RED_COLOR "%+f and %+f" DEFAULT_COLOR "\n", program_solution->first_root, program_solution->second_root);
            puts ("");
            break;

        case TEST_CANT_OPEN_FILE:
            puts ("");
            printf("Test error: can't open this file.");
            puts ("");
            break;

        default:
            MY_ASSERT(0 && "TEST RESULT OUTPUT ERROR");
            break;
    }
}