#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>
#include <float.h>
#include "header.h"


void show_equation_format(void)
{
    // setcolor(EQUATION_COLOR);
    puts("ax^2 + bx + c = 0.");
    // setcolor(DEFAULT_COLOR);
}


void show_menu(const char language)
{
    //setcolor(DEFAULT_COLOR);
    switch(language)
    {
        case 'e':
            puts("Hello, Ruslan Alekseyevich.");
            puts("This program can solve quadratic equation.");
            printf("Equation must looks like: ");
            break;

        case 'r':
            puts("Здравствуйте, Руслан Алексеевич.");
            puts("Эта программа преднозначена для решения квадратных уравнений.");
            printf("Уравнение должно выглядеть следующим образом: ");
            break;

        case 'g':
            puts("Hallo, Ruslan Alekseevich.");
            puts("Dieses Programm dient zur Lösung quadratischer Gleichungen.");
            printf("Die Gleichung sollte so aussehen: ");
            break;

        case 'c':
            puts("你好，鲁斯兰·阿列克谢耶维奇。");
            puts("该程序旨在求解二次方程。");
            printf("等式应如下所示： ");
            break;

        default:
            puts("LANGUAGE ERROR");
            assert(0);   
            break;
    }
    show_equation_format();
}


EquationCoefficients get_coefficients(const char language)
{
    EquationCoefficients coefficients = {0.0, 0.0, 0.0};
    
    switch(language)
    {
        case 'e':
            puts("Enter coeficients a, b, c:");
            while (scanf("%f%f%f", &coefficients.a, &coefficients.b, &coefficients.c) != 3)
            {
                puts("Error. Enter 3 real numbers");
                puts("like 12, -1.5, 3.14 or 1.618.");
                scanf("%*s");
            }
            break;

        case 'r':
            puts ("Введите коэффициенты a, b и c:");
            while (scanf("%f%f%f", &coefficients.a, &coefficients.b, &coefficients.c) != 3)
            {
                puts("Ошибка. Введите 3 вещественных числа");
                puts("таких как 12, -1.5, 3.14 или 1.618.");
                scanf("%*s");
            }
            break;

        case 'g':
            puts ("Geben Sie die Quoten ein a, b, c:");
            while (scanf("%f%f%f", &coefficients.a, &coefficients.b, &coefficients.c) != 3)
            {
                puts("Fehler. Geben Sie 3 reelle Zahlen ein");
                puts("Zum Beispiel 12, -1.5, 3.14, 1.618.");
                scanf("%*s");
            }
            break;

        case 'c':
            puts ("输入赔率 a, b, c:");
            while (scanf("%f%f%f", &coefficients.a, &coefficients.b, &coefficients.c) != 3)
            {
                puts("错误。输入三个实数");
                puts("例如 12, -1.5, 3.14, 1.618.");
                scanf("%*s");
            }
            break;

        default:
            puts("LANGUAGE ERROR");
            assert(0);
            break;
    }
    return coefficients;
}


EquationRoots solve_equation(const EquationCoefficients * coeffs)
{
    EquationRoots solution = {zero, 0.0, 0.0};
    float discriminant = calculate_discriminant(coeffs);

    if (check_equality_float(coeffs->a, 0.0))
    {
        if (check_equality_float(coeffs->b, 0.0))
        {
            if (check_equality_float(coeffs->c, 0.0))
                solution.count = infinity;
            else 
                solution.count = zero;
        }    
        else 
        { 
            solution.count = one;
            solution.first_root = - (coeffs->c / coeffs->b);
        }       
    }
    else if (discriminant < 0)
    {
        solution.count = zero;
    }
    else if (check_equality_float(discriminant, 0))
    {
        solution.count = one;
        solution.first_root = calculate_root1(coeffs, discriminant);
    }
    else 
    {
        solution.count = two;
        solution.first_root = calculate_root1(coeffs, discriminant);
        solution.second_root = calculate_root2(coeffs, discriminant);
    }
    return solution;
}


void show_user_equation(const EquationCoefficients * coeffs)
{
    // setcolor(EQUATION_COLOR);
    printf("%.3g*x^2 + %.3g*x + %.3g = 0.\n", coeffs->a, coeffs->b, coeffs->c);
    // setcolor(DEFAULT_COLOR);
}


void show_equation(const EquationCoefficients * coeffs, const char language)
{
    switch (language)
    {
        case 'e':
            printf("Your equation: ");
            break;

        case 'r':
            printf("Ваше уравнение: ");
            break;

        case 'g':
            printf("Hier ist deine Gleichung: ");
            break;

        case 'c':
            printf("这是你的等式： ");
            break;

        default:
            puts("LANGUAGE ERROR");
            assert(0);
            break;
    }
    show_user_equation(coeffs);
}


void show_one_root(const float root)
{
    // setcolor(ROOTS_COLOR);
    printf("%5.5g\n", root);
    // setcolor(DEFAULT_COLOR);
}


void show_solution(const EquationRoots * solution, const char language)
{
    switch (language)
    {
        case 'e':
            switch (solution->count)
            {
                case infinity:
                    puts("This equation has infinite number of roots.");
                    break;

                case zero:
                    puts("This equation hasn't roots.");
                    break;

                case one: 
                    puts("This equation has one root.");
                    printf("This root: ");
                    show_one_root(solution->first_root);
                    break;

                case two:
                    puts("This equation has two roots.");
                    printf("First root: ");
                    show_one_root(solution->first_root);
                    printf("Second root: ");
                    show_one_root(solution->second_root);
                    break;

                default:
                    puts("ROOTS COUNT ERROR");
                    assert(0);
                    break;
            }
            break;

        case 'r':
            switch (solution->count)
            {
                case infinity:
                    puts("Это уравнение имеет бесконечное количество корней.");
                    break;

                case zero:
                    puts("Это уравнение не имеет корней.");
                    break;

                case one: 
                    puts("Это уравнение имеет всего один корень.");
                    printf("Этот корень: ");
                    show_one_root(solution->first_root);
                    break;

                case two:
                    puts("Это уравнение имеет два корня.");
                    printf("Первый корень: ");
                    show_one_root(solution->first_root);
                    printf("Второй корень: ");
                    show_one_root(solution->second_root);
                    break;

                default:
                    puts("ROOTS COUNT ERROR");
                    assert(0);
                    break;
            }
            break;        

        case 'g':
            switch (solution->count)
            {
                case infinity:
                    puts("Diese Gleichung hat unendlich viele Wurzeln.");
                    break;

                case zero:
                    puts("Diese Gleichung hat keine Wurzeln.");
                    break;

                case one: 
                    puts("Diese Gleichung hat nur eine Wurzel.");
                    printf("das ist die Wurzel: ");
                    show_one_root(solution->first_root);
                    break;

                case two:
                    puts("Diese Gleichung hat zwei Wurzeln.");
                    printf("erste Wurzel: ");
                    show_one_root(solution->first_root);
                    printf("zweite Wurzel: ");
                    show_one_root(solution->second_root);
                    break;
                
                default:
                    puts("ROOTS COUNT ERROR");
                    assert(0);
                    break;
            }
            break;   

        case 'c':
            switch (solution->count)
            {
                case infinity:
                    puts("这个方程有无数个根。");
                    break;

                case zero:
                    puts("该方程没有实根。");
                    break;

                case one: 
                    puts("这个方程只有一个根。");
                    printf("这是根: ");
                    show_one_root(solution->first_root);
                    break;

                case two:
                    puts("这个方程有两个根。");
                    printf("第一个根： ");
                    show_one_root(solution->first_root);
                    printf("第二根： ");
                    show_one_root(solution->second_root);
                    break;
                
                default:
                    puts("ROOTS COUNT ERROR");
                    assert(0);
                    break;
            }
            break;

        default:
            puts("LANGUAGE ERROR");
            assert(0);
            break;
    }
}


float calculate_discriminant(const EquationCoefficients * coefficients)
{
    return coefficients->b * coefficients->b - 4 * (coefficients->a) * (coefficients->c);
}


float calculate_root1(const EquationCoefficients * coefficients, const float discriminant)
{
    return (- coefficients->b - sqrtf( discriminant ) ) / ( 2 * coefficients->a );
}


float calculate_root2(const EquationCoefficients * coefficients, const float discriminant)
{
    return (- coefficients->b + sqrtf( discriminant ) ) / ( 2 * coefficients->a );
}


char get_language(void)
{
    int ch = 0;
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

    return (char) ch;
}


void show_goodbye(const char language)
{
    switch (language)
    {
        case 'e':
            puts("Have a good day! End.");
            break;

        case 'r':
            puts("Всего доброго! Конец.");
            break;

        case 'g':
            puts("Auf Wiedersehen! Ende.");
            break;

        case 'c':
            puts("再见！结尾。");
            break;

        default:
            puts("LANGUAGE ERROR");
            assert(0);
            break;
    }
}


bool check_equality_float(const float num1, const float num2)
{
    return (fabs(num1 - num2) < 0);
}