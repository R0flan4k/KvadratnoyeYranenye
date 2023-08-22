#include <stdio.h>
#include <stdlib.h>

#include "calculations.h"
#include "test.h"

TEST_RESULTS test_program(void)
{
    EquationCoefficients test_coeffs = {0.0, 0.0, 0.0};
    EquationRoots right_solution = {ROOTS_COUNT_ZERO, 0.0, 0.0};
    EquationRoots program_solution = {ROOTS_COUNT_ZERO, 0.0, 0.0};
    FILE * fp = 0;


    if ((fp = fopen(TEST_FILE, "r")) == NULL)
    {
        puts("Can't open the file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%f %f %f %d %f %f", &test_coeffs.a, &test_coeffs.b, &test_coeffs.c, 
                  (int *) &program_solution.count, &program_solution.first_root, &program_solution.second_root) 
                  == 6) 
    {
        program_solution = solve_equation(&test_coeffs);

        if ((int) program_solution.count != (int) right_solution.count)
        {
            fclose(fp);
            return TEST_COUNT_FAILURE;
        }
        else if (is_equal_equation_roots(program_solution.first_root, program_solution.second_root, right_solution.first_root, right_solution.second_root))
        {
            fclose(fp);
            return TEST_ROOTS_FAILURE;
        }
    }

    fclose(fp);
    return TEST_SUCCES;
}


bool is_first_to_first(const float program_root1, const float program_root2, const float right_root1, const float right_root2)
{
    return (is_equal_float(program_root1, right_root1) && is_equal_float(program_root2, right_root2));
}


bool is_first_to_second(const float program_root1, const float program_root2, const float right_root1, const float right_root2)
{
    return (is_equal_float(program_root1, right_root2) && is_equal_float(program_root2, right_root1));
}


bool is_equal_equation_roots(const float program_root1, const float program_root2, const float right_root1, const float right_root2)
{
    return (is_first_to_first(program_root1, program_root2, right_root1, right_root2) || is_first_to_second(program_root1, program_root2, right_root1, right_root2));
}