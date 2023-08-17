#include <stdio.h>
#include "QuadraticEquation.h"


int main(void)
{
    EquationRoots solution = {0, 0.0, 0.0};
    EquationCoefficients coefficients = {0.0, 0.0, 0.0};
    char language = 0;

    language = get_language();
    show_menu(language);
    coefficients = get_coefficients(language);
    solution = solve_equation(&coefficients);
    show_equation(&coefficients, language);
    show_solution(&solution, language);
    show_goodbye(language);

    return 0;
}
