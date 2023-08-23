#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include "input-output.h"
#include "languages.h"


extern const OutputLanguages LANGUAGE_RUSSIAN;
extern const OutputLanguages LANGUAGE_ENGLISH;
extern const OutputLanguages LANGUAGE_GERMANY;
extern const OutputLanguages LANGUAGE_CHINESE;


void show_equation_format(void)
{
    puts("\x1b[31max^2 + bx + c = 0.\x1b[0m");
}


void show_menu(const OutputLanguages * language)
{
    //setcolor(DEFAULT_COLOR);
    printf("%s", language->language_menu);
    show_equation_format();
}


EquationCoefficients get_coefficients(const OutputLanguages * language)
{
    EquationCoefficients coefficients = {0.0, 0.0, 0.0};
    int checker = 0;
    int EOF_checker = 0;
    bool marker = true;
    
    printf("%s", language->language_request);

    start:
    marker = true;
    while (scanf("%f%f%f", &coefficients.a, &coefficients.b, &coefficients.c) < 3)
    {
        while ((EOF_checker = getchar()) != '\n')
        {
            if (EOF_checker == EOF)
                exit(EXIT_SUCCESS);
        }
        
        printf("%s", language->language_error);
        
    }

    while ((checker = getchar()) != '\n')
    {
        if (!(isspace(checker)) && marker)
        {
            if (checker == EOF)
                exit(EXIT_SUCCESS);
            printf("%s", language->language_error);
            marker = false;
        }
    }

    if (!marker)
        goto start;

    return coefficients;
}


void show_equation(const EquationCoefficients * coeffs, const OutputLanguages * language)
{
    printf("%s", language->language_show_equation);
    printf("\x1b[31m%.3g*x^2 + %.3g*x + %.3g = 0.\x1b[0m\n", coeffs->a, coeffs->b, coeffs->c);
}


void show_one_root(const float root)
{
    printf("\x1b[31m%5.5g\x1b[0m\n", root);
}


void show_solution(const EquationRoots * solution, const OutputLanguages * language)
{
    switch (solution->count)
    {
        case ROOTS_COUNT_INFINITY:
            printf("%s", language->language_inf_roots);
            break;

        case ROOTS_COUNT_ZERO:
            printf("%s", language->language_no_roots);
            break;

        case ROOTS_COUNT_ONE: 
            printf("%s", language->language_one_root);
            printf("%s", language->language_this_root);
            show_one_root(solution->first_root);
            break;

        case ROOTS_COUNT_TWO:
            printf("%s", language->language_two_roots);
            printf("%s", language->language_first_root);
            show_one_root(solution->first_root);
            printf("%s", language->language_second_root);
            show_one_root(solution->second_root);
            break;

        default:
            assert(0 && "ROOTS COUNT ERROR");
            break;
    }
}


void show_goodbye(const OutputLanguages * language)
{
    printf("%s", language->language_goodbye);
}


const OutputLanguages * get_language(void)
{
    int ch = 0;
    int checker = 0;
    bool extra_characters_marker = true;
    bool wrong_character_marker = true;

    puts("Enter language:");
    puts("\"R\" - Russian,      \"E\" - English,");
    puts("\"G\" - Germany,      \"C\" - Chinese.");

    do
    {
        extra_characters_marker = true;
        wrong_character_marker = true;
        ch = getchar();
        ch = tolower(ch);

        if (ch == EOF)
            return EXIT_SUCCESS;
        if ((ch != 'r' && ch != 'e' && ch != 'g' && ch != 'c'))
        {
            puts("Error. Enter language again (\"R\", \"E\", \"G\" or \"C\".)");
            
            while (getchar() != '\n')
                continue;
            
            wrong_character_marker = false;
        }
        else
        {
            do
            {
                checker = getchar();
                if (!(isspace(checker)) && extra_characters_marker == true)
                {
                    puts("Error. Enter language again (\"R\", \"E\", \"G\" or \"C\".)");
                    extra_characters_marker = false;
                }
            }  while (checker != '\n');
        }
    } while ((ch != 'r' && ch != 'e' && ch != 'g' && ch != 'c') || extra_characters_marker == false || wrong_character_marker == false);

    switch (ch)
    {
        case 'r':
            return &LANGUAGE_RUSSIAN;
            break;
        case 'e':
            return &LANGUAGE_ENGLISH;
            break;
        case 'g':
            return &LANGUAGE_GERMANY;
            break;
        case 'c':
            return &LANGUAGE_CHINESE;
            break;
        default:
            assert(0 && "GET_LANG ERROR");
            break;
    }
}


char get_test_necessity(void)
{
    int ch = 0;
    int checker = 0;
    bool extra_characters_marker = true;
    bool wrong_character_marker = true;

    puts("Run the test?:");
    puts("\"Y\" - yes,      \"N\" - no.");

    do
    {
        extra_characters_marker = true;
        wrong_character_marker = true;
        ch = getchar();
        ch = tolower(ch);

        if (ch == EOF)
            return EXIT_SUCCESS;
        if ((ch != 'y' && ch != 'n'))
        {
            puts("Error. Enter your choice again (\"Y\" or \"N\".)");
            
            while (getchar() != '\n')
                continue;
            
            wrong_character_marker = false;
        }
        else
        {
            do
            {
                checker = getchar();
                if (!(isspace(checker)) && extra_characters_marker == true)
                {
                    puts("Error. Enter language again (\"Y\" or \"N\".)");
                    extra_characters_marker = false;
                }
            }  while (checker != '\n');
        }
    } while ((ch != 'y' && ch != 'n') || extra_characters_marker == false || wrong_character_marker == false);

    return (char) ch;
}