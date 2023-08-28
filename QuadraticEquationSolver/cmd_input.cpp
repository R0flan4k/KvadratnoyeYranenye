/////////////////////////////////////////////////////////////////////////
/// \file cmd_input.cpp
/// \brief Command line data processing.
/////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

#include "input-output.h"
#include "test.h"
#include "my_assert.h"
#include "languages.h"
#include "my_assert.h"


/////////////////////////////////////////////////////////////////////////
/// \brief Show instruction how to use test flag (--test).
/// \param[in] argv Program name pointer.
/////////////////////////////////////////////////////////////////////////
static void show_instruction_test(char * argv);

/////////////////////////////////////////////////////////////////////////
/// \brief Show instruction how to use coeffs flag (--coeffs).
/// \param[in] argv Program name pointer.
/////////////////////////////////////////////////////////////////////////
static void show_instruction_coeffs(char * argv);

static CmdLineArg test_flag = {
    .name = "--test",
    .num_of_param = 1
};

static CmdLineArg coeffs_flag = {
    .name = "--coeffs",
    .num_of_param = 3
};

int check_cmd_input(int argc, char ** argv)
{
    MY_ASSERT(argv != nullptr);

    static int input_status = TRIVIAL_CMD_INPUT;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], test_flag.name) == 0)
        {
            if (argc > i + test_flag.num_of_param)
            {
                MY_ASSERT(test_program(argv[i + test_flag.num_of_param]) == TEST_SUCCESS);
                input_status == PREMATURE_CMD_INPUT? 0 : input_status = RIGHT_CMD_INPUT;
            }
            else    
            {
                show_instruction_test(argv[0]);
                return WRONG_CMD_INPUT;
            }
        }
        else if (strcmp(argv[i], coeffs_flag.name) == 0)
        {
            if (argc > i + coeffs_flag.num_of_param)
            {
                EquationCoefficients coefficients = {(float) atof(argv[i + coeffs_flag.num_of_param -2]),
                                                     (float) atof(argv[i + coeffs_flag.num_of_param -1]),
                                                     (float) atof(argv[i + coeffs_flag.num_of_param])};
                EquationRoots solution = solve_equation(&coefficients);
                show_equation(&coefficients, &LANGUAGE_ENGLISH);
                show_solution(&solution, &LANGUAGE_ENGLISH);
                input_status = PREMATURE_CMD_INPUT;
            }
            else
            {
                show_instruction_coeffs(argv[0]);
                return WRONG_CMD_INPUT;
            }
        }
    }
    
    return input_status;
}

static void show_instruction_test(char * argv)
{
    printf("Please, use: %s --test *test_name.txt*\n", argv);
    printf("or use: %s\n", argv);
}


static void show_instruction_coeffs(char * argv)
{
    printf("Please, use: %s --coeffs *a coefficient* *b coefficient* *c coefficient*\n", argv);
    printf("or use: %s\n", argv);
}
