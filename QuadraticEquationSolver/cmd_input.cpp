/////////////////////////////////////////////////////////////////////////
/// \file cmd_input.cpp
/// \brief Command line data processing.
/////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "input-output.h"
#include "test.h"
#include "languages.h"

#include "my_assert.h"


CmdLineArg TESTS = {
    .name =         "--test",
    .num_of_param = 1,
    .necessity =    false,
    .argc_number =  0,
    .help =         "--test *test_file*"
};
CmdLineArg COEFFS = {
    .name =         "--coeffs",
    .num_of_param = 3,
    .necessity =    false,
    .argc_number =  0,
    .help =         "--coeffs *a coefficient* *b coefficient* *c coefficient*"
};

bool check_cmd_input(int argc, char * * argv)
{
    CmdLineArg * flags[SUPPORTED_FLAGS_NUMBER] = {&TESTS, &COEFFS};

    for (int i = 0; i < SUPPORTED_FLAGS_NUMBER; i++)
    {
        for (int j = 1; j < argc; j++)
        {
            if (strcmp(flags[i]->name, argv[j]) == 0)
            {
                if (argc > j + flags[i]->num_of_param)
                {
                    flags[i]->argc_number = j;
                    flags[i]->necessity = true;
                }
                else 
                {
                    printf("Error. Please, use %s %s\n", argv[0], flags[i]->help);
                    printf("or use %s\n", argv[0]);
                    return false;
                }    
            }
        }
    }

    return true;
}


void run_from_cmdline(const float a, const float b, const float c)
{
    EquationCoefficients coefficients = {a, b, c};
    EquationRoots solution = solve_equation(&coefficients);
    show_equation(&coefficients, &LANGUAGE_ENGLISH);
    show_solution(&solution, &LANGUAGE_ENGLISH);
}