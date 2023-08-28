/////////////////////////////////////////////////////////////////////////
/// \file main.cpp
/// \brief File with main().
/////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "input-output.h"
#include "calculations.h"
#include "test.h"
#include "languages.h"
#include "my_assert.h"


int main(int argc, char * argv[])
{
    EquationRoots solution = {ROOTS_COUNT_ZERO, 0.0, 0.0};
    EquationCoefficients coefficients = {0.0, 0.0, 0.0};

    const OutputLanguage * language = &LANGUAGE_ENGLISH;
    
    
    if (check_cmd_input(argc, argv) == false)
        return 1;

    if (TESTS.necessity)
    {
        MY_ASSERT(test_program(argv[TESTS.argc_number + 1]) == TEST_SUCCESS);
    }

    if (COEFFS.necessity)
    {
        run_from_cmdline((float) atof(argv[COEFFS.argc_number + 1]),
                         (float) atof(argv[COEFFS.argc_number + 2]),
                         (float) atof(argv[COEFFS.argc_number + 3]));
        return 0;
    }

    show_language_menu();

    int character = 0;
    while ((character = get_one_char("regc", strlen("regc")))
            == WRONG_CHARACTER || character == EXTRA_CHARACTERS)
    {
        puts("Error. Enter language again (\"E\", \"R\", \"G\" or \"C\")");
    }
    language = select_language(character);

    show_menu(language);
    show_request(language); 

    bool coefficients_input_status = true;
    while (!(coefficients_input_status = is_valid_coefficients_input(&coefficients)) || !isspace_extra_characters())
    {
        if (!coefficients_input_status)
        {
            show_error(language);
            skip_input();
        }
        else
        {
            show_error(language);
        }
    }
    solution = solve_equation(&coefficients);
    show_equation(&coefficients, language);
    show_solution(&solution, language);
    show_goodbye(language);

    return 0;
}
 