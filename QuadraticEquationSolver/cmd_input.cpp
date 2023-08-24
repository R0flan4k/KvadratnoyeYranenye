/////////////////////////////////////////////////////////////////////////
/// \file cmd_input.cpp
/////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

#include "input-output.h"
#include "test.h"
#include "my_assert.h"

extern const OutputLanguage LANGUAGE_RUSSIAN;
extern const OutputLanguage LANGUAGE_ENGLISH;
extern const OutputLanguage LANGUAGE_GERMANY;
extern const OutputLanguage LANGUAGE_CHINESE;

/////////////////////////////////////////////////////////////////////////
/// \brief Show instruction how to use test flag (--test).
/// \param[in] argv Program name pointer.
/////////////////////////////////////////////////////////////////////////
static void show_instruction_test(char * argv);

int check_cmd_input(int argc, char ** argv)
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--test") == 0)
        {
            if (argc >= i+1)
            {
                MY_ASSERT(test_program(argv[i+1]) == TEST_SUCCESS);
                return RIGHT_CMD_INPUT;
            }
            else    
            {
                show_instruction_test(argv[0]);
                return WRONG_CMD_INPUT;
            }
        }
        else if (strcmp(argv[i], "--coeffs") == 0)
        {
            if (argc >= i+3)
            {
                EquationCoefficients coefficients = {(float) atof(argv[i+1]), (float) atof(argv[i+2]), (float) atof(argv[i+3])};
                EquationRoots solution = solve_equation(&coefficients);
                show_equation(&coefficients, &LANGUAGE_ENGLISH);
                show_solution(&solution, &LANGUAGE_ENGLISH);
            }
        }
    }
    
    return TRIVIAL_CMD_INPUT;
}

static void show_instruction_test(char * argv)
{
    printf("Please, use: %s --test *test_name.txt*\n", argv);
    printf("or use: %s\n", argv);
}
