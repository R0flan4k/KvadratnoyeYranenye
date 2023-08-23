#include <stdio.h>
#include <assert.h>

#include "input-output.h"
#include "calculations.h"
#include "test.h"


#define MY_ASSERT(X) if (!(X)) { printf("Assertion failed: " #X ", line %d, file" __FILE__ ", date " __DATE__ "\n", __LINE__); exit(EXIT_FAILURE); }


int main(void)
{
    EquationRoots solution = {ROOTS_COUNT_ZERO, 0.0, 0.0};
    EquationCoefficients coefficients = {0.0, 0.0, 0.0};

    extern const OutputLanguages LANGUAGE_ENGLISH;
    const OutputLanguages * language = &LANGUAGE_ENGLISH;

    if (get_test_necessity() == 'y')
        MY_ASSERT(test_program() == TEST_SUCCESS);

    language = get_language();
    show_menu(language);
    coefficients = get_coefficients(language);
    solution = solve_equation(&coefficients);
    show_equation(&coefficients, language);
    show_solution(&solution, language);
    show_goodbye(language);

    return 0;
}

