/////////////////////////////////////////////////////////////////////////
/// \file main.cpp
/////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <assert.h>

#include "input-output.h"
#include "calculations.h"
#include "test.h"
#include "my_assert.h"


int main(int argc, char * argv[])
{
    EquationRoots solution = {ROOTS_COUNT_ZERO, 0.0, 0.0};
    EquationCoefficients coefficients = {0.0, 0.0, 0.0};

    extern const OutputLanguage LANGUAGE_ENGLISH;
    const OutputLanguage * language = &LANGUAGE_ENGLISH;
    
    if (check_cmd_input(argc, argv) == WRONG_CMD_INPUT)
        return 0;

    show_language_menu();

    int character = 0;
    while ((character = get_one_char("regc", 4)) == WRONG_CHARACTER || character == EXTRA_CHARACTERS)
        puts("Error. Enter language again (\"E\", \"R\", \"G\" or \"C\")");
    language = select_language(character);


    show_menu(language);
    printf("%s", language->language_request); 
    while (!is_valid_coefficients_input(&coefficients))
        printf("%s", language->language_error);
    solution = solve_equation(&coefficients);
    show_equation(&coefficients, language);
    show_solution(&solution, language);
    show_goodbye(language);

    return 0;
}

// nazvanuye, ccel, kto pisal, ispolzovaniye,
