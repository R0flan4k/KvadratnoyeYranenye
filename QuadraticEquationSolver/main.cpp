#include <stdio.h>
#include "header.h"


int main(void)
{
    EquationRoots solution = {zero, 0.0, 0.0};
    EquationCoefficients coefficients = {0.0, 0.0, 0.0};
    extern OutputLanguages eng;
    OutputLanguages language = eng;

    language = get_language();
    show_menu(&language);
    coefficients = get_coefficients(&language);
    solution = solve_equation(&coefficients);
    show_equation(&coefficients, &language);
    show_solution(&solution, &language);
    show_goodbye(&language);

    return 0;
}
