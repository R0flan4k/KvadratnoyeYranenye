#include <stdio.h>
#include "input-output.h"


int main(void)
{
    EquationRoots solution = {ROOTS_COUNT_ZERO, 0.0, 0.0};
    EquationCoefficients coefficients = {0.0, 0.0, 0.0};
    extern const OutputLanguages LANG_ENGLISH;
    const OutputLanguages * language = &LANG_ENGLISH;

    language = get_language();
    show_menu(language);
    coefficients = get_coefficients(language);
    solution = solve_equation(&coefficients);
    show_equation(&coefficients, language);
    show_solution(&solution, language);
    show_goodbye(language);

    return 0;
}