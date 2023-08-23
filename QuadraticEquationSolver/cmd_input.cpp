#include <stdio.h>
#include <string.h>

#include "input-output.h"

int check_cmd_input(int argc, char ** argv)
{
    if (argc > 3 || (argc <= 3 && argc > 1 && strcmp(argv[1], "--test") != 0))
        return WRONG_CMD_INPUT;
    else if (argc == 1)
        return TRIVIAL_CMD_INPUT;
    else
        return RIGHT_CMD_INPUT;
}

void show_instruction(char ** argv)
{
    printf("Please, use: %s --test *test_name.txt*\n", argv[0]);
    printf("or use: %s\n", argv[0]);
}
