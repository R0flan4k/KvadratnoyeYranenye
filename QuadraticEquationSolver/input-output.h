#ifndef INPUT_OUTPUT_H
    #define INPUT_OUTPUT_H

    #include "languages.h"
    #include "calculations.h"

    const int WRONG_CMD_INPUT = 1;
    const int RIGHT_CMD_INPUT = 0;
    const int TRIVIAL_CMD_INPUT = 2;
    
    const int EXTRA_CHARACTERS = -2;
    const int WRONG_CHARACTER = -3;
                       
    void show_menu(const OutputLanguage *);
    void show_language_menu(void);
    
    void show_equation_format(void);
    void show_equation(const EquationCoefficients *, const OutputLanguage *);
    void show_solution(const EquationRoots *, const OutputLanguage *);
    void show_goodbye(const OutputLanguage *);
    

    EquationCoefficients get_coefficients(const OutputLanguage *);
    int get_one_char(const char *, int n);

    int check_cmd_input(int, char * *);


#endif