#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include "header.h"


void show_equation_format(void)
{
    // setcolor(EQUATION_COLOR);
    puts("ax^2 + bx + c = 0.");
    // setcolor(DEFAULT_COLOR);
}


void show_menu(const Languages language)
{
    //setcolor(DEFAULT_COLOR);
    switch(language)
    {
        case english:
            puts("Hello, Ruslan Alekseyevich.");
            puts("This program can solve quadratic equation.");
            printf("Equation must looks like: ");
            break;

        case russian:
            puts("Здравствуйте, Руслан Алексеевич.");
            puts("Эта программа преднозначена для решения квадратных уравнений.");
            printf("Уравнение должно выглядеть следующим образом: ");
            break;

        case germany:
            puts("Hallo, Ruslan Alekseevich.");
            puts("Dieses Programm dient zur Lösung quadratischer Gleichungen.");
            printf("Die Gleichung sollte so aussehen: ");
            break;

        case chinese:
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


EquationCoefficients get_coefficients(const Languages language)
{
    EquationCoefficients coefficients = {0.0, 0.0, 0.0};
    
    switch(language)
    {
        case english:
            puts("Enter coeficients a, b, c:");
            while (scanf("%f%f%f", &coefficients.a, &coefficients.b, &coefficients.c) != 3)
            {
                puts("Error. Enter 3 real numbers");
                puts("like 12, -1.5, 3.14 or 1.618.");
                scanf("%*s");
            }
            break;

        case russian:
            puts ("Введите коэффициенты a, b и c:");
            while (scanf("%f%f%f", &coefficients.a, &coefficients.b, &coefficients.c) != 3)
            {
                puts("Ошибка. Введите 3 вещественных числа");
                puts("таких как 12, -1.5, 3.14 или 1.618.");
                scanf("%*s");
            }
            break;

        case germany:
            puts ("Geben Sie die Quoten ein a, b, c:");
            while (scanf("%f%f%f", &coefficients.a, &coefficients.b, &coefficients.c) != 3)
            {
                puts("Fehler. Geben Sie 3 reelle Zahlen ein");
                puts("Zum Beispiel 12, -1.5, 3.14, 1.618.");
                scanf("%*s");
            }
            break;

        case chinese:
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


void show_user_equation(const EquationCoefficients * coeffs)
{
    // setcolor(EQUATION_COLOR);
    printf("%.3g*x^2 + %.3g*x + %.3g = 0.\n", coeffs->a, coeffs->b, coeffs->c);
    // setcolor(DEFAULT_COLOR);
}


void show_equation(const EquationCoefficients * coeffs, const Languages language)
{
    switch (language)
    {
        case english:
            printf("Your equation: ");
            break;

        case russian:
            printf("Ваше уравнение: ");
            break;

        case germany:
            printf("Hier ist deine Gleichung: ");
            break;

        case chinese:
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


void show_solution(const EquationRoots * solution, const Languages language)
{
    switch (language)
    {
        case english:
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

        case russian:
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

        case germany:
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

        case chinese:
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


void show_goodbye(const Languages language)
{
    switch (language)
    {
        case english:
            puts("Have a good day! End.");
            break;

        case russian:
            puts("Всего доброго! Конец.");
            break;

        case germany:
            puts("Auf Wiedersehen! Ende.");
            break;

        case chinese:
            puts("再见！结尾。");
            break;

        default:
            puts("LANGUAGE ERROR");
            assert(0);
            break;
    }
}


Languages get_language(void)
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

    return (Languages) ch;
}