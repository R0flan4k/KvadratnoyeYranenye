#ifndef INPUT_OUTPUT_H
#   include "languages.h"
#   include "calculations.h"
                       
    void show_menu(const OutputLanguages *);
    void show_equation_format(void);
    void show_user_equation(const EquationCoefficients *);
    void show_equation(const EquationCoefficients *, const OutputLanguages *);
    void show_one_root(const float);
    void show_solution(const EquationRoots *, const OutputLanguages *);
    void show_goodbye(const OutputLanguages *);

    EquationCoefficients get_coefficients(const OutputLanguages *);

    #define INPUT_OUTPUT_H

#endif