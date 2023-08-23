#include <stdio.h>
#include <assert.h>

#include "input-output.h"
#include "calculations.h"
#include "test.h"
#include "my_assert.h"

  // macros function // i nazvaniye testa

int main(int argc, char * argv[])
{
    EquationRoots solution = {ROOTS_COUNT_ZERO, 0.0, 0.0};
    EquationCoefficients coefficients = {0.0, 0.0, 0.0};

    extern const OutputLanguages LANGUAGE_ENGLISH;
    const OutputLanguages * language = &LANGUAGE_ENGLISH;

    int cmd_input_result = 0;

    if ((cmd_input_result = check_cmd_input(argc, argv)) == WRONG_CMD_INPUT)
    {
        show_instruction(argv);
        MY_ASSERT(0 && "INVALID CMD INPUT")
    }
    else if (cmd_input_result == RIGHT_CMD_INPUT)
    {
        MY_ASSERT(test_program(argv[2]) == TEST_SUCCESS);
    }
    else
    {
        if (get_test_necessity() == 'y')
        MY_ASSERT(test_program("test_arguments.txt") == TEST_SUCCESS);
    }


    language = get_language();
    show_menu(language);
    coefficients = get_coefficients(language);
    solution = solve_equation(&coefficients);
    show_equation(&coefficients, language);
    show_solution(&solution, language);
    show_goodbye(language);

    return 0;
}

