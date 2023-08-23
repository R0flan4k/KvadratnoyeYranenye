#ifndef INPUT_OUTPUT_H
    #define INPUT_OUTPUT_H

    #include "languages.h"
    #include "calculations.h"

    const int WRONG_CMD_INPUT = 1;
    const int RIGHT_CMD_INPUT = 0;
    const int TRIVIAL_CMD_INPUT = 2;
                       
    void show_menu(const OutputLanguages *);
    void show_equation_format(void);
    void show_equation(const EquationCoefficients *, const OutputLanguages *);
    void show_one_root(const float);
    void show_solution(const EquationRoots *, const OutputLanguages *);
    void show_goodbye(const OutputLanguages *);

    EquationCoefficients get_coefficients(const OutputLanguages *);
    char get_test_necessity(void);

    int check_cmd_input(int, char * *);
    void show_instruction(char * *);


#endif