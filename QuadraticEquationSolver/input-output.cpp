/////////////////////////////////////////////////////////////////////////
/// \file input-output.cpp
/// \brief The part of the program responsible for stdin and stdout
/////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include "input-output.h"
#include "languages.h"
#include "my_assert.h"


/////////////////////////////////////////////////////////////////////////
/// \brief Skip all characters until a non-space character is encountered.
/// \return First non-space character.
/////////////////////////////////////////////////////////////////////////
static int skip_spaces_and_getchar(void);

/**//////////////////////////////////////////////////////////////////////
/// \brief Show one calculated root.
/// \param[in] root This root.
////////////////////////////////////////////////////////////////////////*/
static void show_one_root(const float root);



void show_equation_format(void)
{
    puts("ax^2 + bx + c = 0.");
}


void show_menu(const OutputLanguage * language)
{
    printf("%s", language->language_menu);
    show_equation_format();
}



int get_coefficients(EquationCoefficients * coefficients)
{
    return scanf("%f%f%f", &(coefficients->a), &(coefficients->b), &(coefficients->c));
}


bool is_valid_coefficients_input (EquationCoefficients * coefficients)
{
    return get_coefficients(coefficients) == 3;
}


void show_equation(const EquationCoefficients * coeffs, const OutputLanguage * language)
{
    printf("%s", language->language_show_equation);
    printf(GREEN_COLOR "%.3g*x^2 + %.3g*x + %.3g = 0.\n" DEFAULT_COLOR, coeffs->a, coeffs->b, coeffs->c);
}


static void show_one_root(const float root)
{
    printf(GREEN_COLOR "\x1b[32m%5.5g\n" DEFAULT_COLOR, root);
}


void show_solution(const EquationRoots * solution, const OutputLanguage * language)
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


void show_goodbye(const OutputLanguage * language)
{
    printf("%s", language->language_goodbye);
}


int get_one_char(const char * str, int n)
{
    int ch = 0;
    bool is_required_char = false;

    ch = skip_spaces_and_getchar();
    ch = tolower(ch);

    if (!isspace_extra_characters())
        return EXTRA_CHARACTERS;

    for (int i = 0; i < n; i++) 
        if (ch == str[i])
        {
            is_required_char = true;
            break;
        }
          
    if (is_required_char == true)
        return ch;
    else    
        return WRONG_CHARACTER;
        
    MY_ASSERT(0 && "GET_ONE_CHAR() ERROR");
}


bool isspace_extra_characters (void)
{
    int ch = 0;
    bool marker = true;

    while ((ch = getchar()) != '\n')
    {
        if (!isspace(ch) && marker == true)
            marker = false;
        else
            continue;
    }

    return marker;
}


static int skip_spaces_and_getchar(void)
{
    int ch = 0;

    while (isspace(ch = getchar()))
        continue;

    return ch;
}


void show_language_menu(void)
{
    puts("Enter language:");
    puts("\"R\" - Russian,      \"E\" - English,");
    puts("\"G\" - Germany,      \"C\" - Chinese.");
}


const OutputLanguage * select_language(const int ch)
{
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

void skip_input(void)
{
    while (getchar() != '\n')
        continue;
}

void show_request(const OutputLanguage * language)
{
    printf("%s", language->language_request);
}


void show_error(const OutputLanguage * language)
{
    printf("%s", language->language_error);
}
