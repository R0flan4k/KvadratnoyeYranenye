#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include "header.h"

extern OutputLanguages rus;
extern OutputLanguages eng;
extern OutputLanguages ger;
extern OutputLanguages chi;


void show_equation_format(void)
{
    // setcolor(EQUATION_COLOR);
    puts("ax^2 + bx + c = 0.");
    // setcolor(DEFAULT_COLOR);
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
    
    printf("%s",language->language_request);
    while (scanf("%f%f%f", &coefficients.a, &coefficients.b, &coefficients.c) != 3)
    {
        printf("%s", language->language_error);
        scanf("%*s");
    }

    return coefficients;
}


void show_user_equation(const EquationCoefficients * coeffs)
{
    // setcolor(EQUATION_COLOR);
    printf("%.3g*x^2 + %.3g*x + %.3g = 0.\n", coeffs->a, coeffs->b, coeffs->c);
    // setcolor(DEFAULT_COLOR);
}


void show_equation(const EquationCoefficients * coeffs, const OutputLanguages * language)
{
    printf("%s", language->language_show_equation);
    show_user_equation(coeffs);
}


void show_one_root(const float root)
{
    // setcolor(ROOTS_COLOR);
    printf("%5.5g\n", root);
    // setcolor(DEFAULT_COLOR);
}


void show_solution(const EquationRoots * solution, const OutputLanguages * language)
{
    switch (solution->count)
    {
        case infinity:
            printf("%s", language->language_inf_roots);
            break;

        case zero:
            printf("%s", language->language_no_roots);
            break;

        case one: 
            printf("%s", language->language_one_root);
            printf("%s", language->language_this_root);
            show_one_root(solution->first_root);
            break;

        case two:
            printf("%s", language->language_two_roots);
            printf("%s", language->language_first_root);
            show_one_root(solution->first_root);
            printf("%s", language->language_second_root);
            show_one_root(solution->second_root);
            break;

        default:
            puts("ROOTS COUNT ERROR");
            assert(0);
            break;
    }
}


void show_goodbye(const OutputLanguages * language)
{
    printf("%s", language->language_goodbye);
}


OutputLanguages get_language(void)
{
    int ch = english;
    puts("Enter language:");
    puts("\"R\" - Russian,      \"E\" - English,");
    puts("\"G\" - Germany,      \"C\" - Chinese.");

    do
    {
        ch = getchar();
        ch = tolower(ch);
        while (getchar() != '\n') 
            continue;
        if (ch != 'r' && ch != 'e' && ch != 'g' && ch != 'c')
            puts("Error. Enter language again (\"R\", \"E\", \"G\" or \"C\".)");
    } while (ch != 'r' && ch != 'e' && ch != 'g' && ch != 'c');

    switch (ch)
    {
        case 'r':
            return (OutputLanguages) rus;
            break;
        case 'e':
            return (OutputLanguages) eng;
            break;
        case 'g':
            return (OutputLanguages) ger;
            break;
        case 'c':
            return (OutputLanguages) chi;
            break;
        default:
            puts("GET_LANG ERROR");
            assert(0);
            break;
    }
}