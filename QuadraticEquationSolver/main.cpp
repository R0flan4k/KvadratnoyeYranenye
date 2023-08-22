#include <stdio.h>
#include <assert.h>

#include "input-output.h"
#include "calculations.h"
#include "test.h"

int main(void)
{
    EquationRoots solution = {ROOTS_COUNT_ZERO, 0.0, 0.0};
    EquationCoefficients coefficients = {0.0, 0.0, 0.0};

    extern const OutputLanguages LANG_ENGLISH;
    const OutputLanguages * language = &LANG_ENGLISH;

    TEST_RESULTS test = TEST_SUCCES;

    puts("Running the test");

    if (test == TEST_COUNT_FAILURE)
        assert (0 && "TEST ERROR: WRONG COUNT OF ROOTS");
    else if (test == TEST_ROOTS_FAILURE)
        assert (0 && "TEST ERROR: WRONG ROOTS");
    else 
        puts("The test succesfully passed");

    language = get_language();
    show_menu(language);
    coefficients = get_coefficients(language);
    solution = solve_equation(&coefficients);
    show_equation(&coefficients, language);
    show_solution(&solution, language);
    show_goodbye(language);

    return 0;
}