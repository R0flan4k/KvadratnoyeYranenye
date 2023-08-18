#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>
#include "header.h"


EquationRoots solve_equation(const EquationCoefficients * coeffs)
{
    EquationRoots solution = {zero, 0.0, 0.0};
    float discriminant = calculate_discriminant(coeffs);
    float sqrtf_discriminant = sqrtf(discriminant);

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
        solution.first_root = calculate_root1(coeffs, sqrtf_discriminant);
    }
    else 
    {
        solution.count = two;
        solution.first_root = calculate_root1(coeffs, sqrtf_discriminant);
        solution.second_root = calculate_root2(coeffs, sqrtf_discriminant);
    }
    return solution;
}


float calculate_discriminant(const EquationCoefficients * coefficients)
{
    return coefficients->b * coefficients->b - 4 * (coefficients->a) * (coefficients->c);
}


float calculate_root1(const EquationCoefficients * coefficients, const float sqrtf_discriminant)
{
    return (- coefficients->b - sqrtf_discriminant ) / ( 2 * coefficients->a );
}


float calculate_root2(const EquationCoefficients * coefficients, const float sqrtf_discriminant)
{
    return (- coefficients->b + sqrtf_discriminant ) / ( 2 * coefficients->a );
}


bool check_equality_float(const float num1, const float num2)
{
    return (fabs(num1 - num2) < FLT_EPSILON);
}