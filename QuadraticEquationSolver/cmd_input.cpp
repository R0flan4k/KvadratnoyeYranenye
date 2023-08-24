/////////////////////////////////////////////////////////////////////////
/// file cmd_input.cpp
/////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

#include "input-output.h"
#include "test.h"
#include "my_assert.h"

/////////////////////////////////////////////////////////////////////////
/// \brief show instruction how to use test flag (--test)
/// \param[in] argv program name pointer
/////////////////////////////////////////////////////////////////////////
static void show_instruction_test(char * argv);

int check_cmd_input(int argc, char ** argv)
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--test") == 0)
        {
            if (argc >= i+1)
            {
                MY_ASSERT(test_program(argv[i+1]) == TEST_SUCCESS);
                return RIGHT_CMD_INPUT;
            }
            else    
            {
                show_instruction_test(argv[0]);
                return WRONG_CMD_INPUT;
            }
        }
        
    }
    
    return TRIVIAL_CMD_INPUT;
}

static void show_instruction_test(char * argv)
{
    printf("Please, use: %s --test *test_name.txt*\n", argv);
    printf("or use: %s\n", argv);
}
