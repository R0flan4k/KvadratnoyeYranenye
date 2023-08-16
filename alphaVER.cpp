#include <stdio.h>
#include <math.h>


typedef struct {
    float a;
    float b;
    float c;
} EquationCoefficients;


typedef struct {
    int count;
    float first_root;
    float second_root;
} EquationRoots;


void show_menu(void);
EquationCoefficients get_coefficients(void);
EquationRoots solve_equation(const EquationCoefficients * );
void show_equation(const EquationCoefficients *);
void show_solution(const EquationRoots *);
float calculate_discriminant(const EquationCoefficients * );
float calculate_root1(const EquationCoefficients * );
float calculate_root2(const EquationCoefficients *);


int main(void)
{
    EquationRoots solution = {0, 0.0, 0.0};
    EquationCoefficients coefficients = {0.0, 0.0, 0.0};

    show_menu();
    coefficients = get_coefficients();
    solution = solve_equation(&coefficients);
    show_equation(&coefficients);
    show_solution(&solution);
    puts("Have a good day! End.");

    return 0;
}


void show_menu(void)
{
    puts("Hello, Ruslan Alekseyevich.");
    puts("This program can solve quadratic equation.");
    puts("Equation must looks like: ax^2 + bx + c = 0.");
}


EquationCoefficients get_coefficients(void)
{
    EquationCoefficients coefficients = {0.0, 0.0, 0.0};
    puts("Enter coeficients a,b,c:");
    while (scanf("%f%f%f", &coefficients.a, &coefficients.b, &coefficients.c)!=3)
    {
        puts("Error. Enter 3 real numbers");
        puts("like 12, -1.5, 3.14 or 1.618.");
        scanf("%*s");
    }
    return coefficients;
}


EquationRoots solve_equation(const EquationCoefficients * coeffs)
{
    EquationRoots solution = {0,0.0,0.0};
    float discriminant = calculate_discriminant(coeffs);

    if (coeffs->a == 0)
    {
        if (coeffs->b == 0)
        {
            if (coeffs->c == 0)
            solution.count = -1;
            else 
            solution.count = 0;
        }    
        else 
        {
            solution.count = 1;
            solution.first_root = -(coeffs->c / coeffs->b);
        }       
    }
    else if (discriminant< 0)
    {
        solution.count = 0;
    }
    else if (discriminant == 0)
    {
        solution.count = 1;
        solution.first_root = calculate_root1(coeffs);
    }
    else 
    {
        solution.count = 2;
        solution.first_root = calculate_root1(coeffs);
        solution.second_root = calculate_root2(coeffs);
    }
    return solution;
}


void show_equation(const EquationCoefficients * coeffs)
{
    printf("Your equation: %.3g*x^2 + %.3g*x + %.3g = 0.\n", coeffs->a, coeffs->b, coeffs->c);
}


void show_solution(const EquationRoots * solution)
{
    if (solution->count == -1)
    {
        puts("This equation has infinite number of roots.");
    }
    else if (solution->count == 0)
    {
        puts("This equation hasn't roots.");
    }
    else if (solution->count ==1)
    {
        puts("This equation has one root.");
        printf("This root: %5.5g\n", solution->first_root);
    }
    else
    {
        puts("This equation has two roots.");
        printf("First root: %5.5g\n", solution->first_root);
        printf("Second root: %5.5g\n", solution->second_root);
    }
}


float calculate_discriminant(const EquationCoefficients * coefficients )
{
    return ( coefficients->b * coefficients->b - 4 * (coefficients->a) * (coefficients->c) );
}


float calculate_root1(const EquationCoefficients * coefficients)
{
    return ( (-coefficients->b - sqrtf( calculate_discriminant(coefficients) ) ) / ( 2 * coefficients->a ) );
}


float calculate_root2(const EquationCoefficients * coefficients)
{
    return ( (-coefficients->b + sqrtf( calculate_discriminant(coefficients) ) ) / ( 2 * coefficients->a ) );
}