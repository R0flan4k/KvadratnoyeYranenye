/////////////////////////////////////////////////////////////////////////
/// \file calculations.cpp
/// \brief Computational part of the program.
/////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>
#include "calculations.h"

/////////////////////////////////////////////////////////////////////////
/// \brief Calculating discriminant of equation.
/// \param[in] coefficients Coefficients of equation inputed.
/// \return Discriminant of equation.
/////////////////////////////////////////////////////////////////////////
static float calculate_discriminant(const EquationCoefficients * coefficients);


EquationRoots solve_equation(const EquationCoefficients * coeffs)
{
    EquationRoots solution = {ROOTS_COUNT_ZERO, 0.0, 0.0};

    if (is_zero_float(coeffs->a))
    {
        if (is_zero_float(coeffs->b))
        {
            if (is_zero_float(coeffs->c))
                solution.count = ROOTS_COUNT_INFINITY;
            else 
                solution.count = ROOTS_COUNT_ZERO;
        }    
        else 
        { 
            solution.count = ROOTS_COUNT_ONE;
            solution.first_root = - (coeffs->c / coeffs->b);
        }       
    }

    float discriminant = calculate_discriminant(coeffs);
    float sqrtf_discriminant = sqrtf(discriminant);
    
    if (is_zero_float(discriminant) && 
        !is_zero_float(coeffs->a))
    {
        solution.count = ROOTS_COUNT_ONE;
        solution.first_root = - coeffs->b / (2 * coeffs->a);
    }
    else if (discriminant < 0)
    {
        solution.count = ROOTS_COUNT_ZERO;
    }
    else if (discriminant > 0)
    {
        solution.count = ROOTS_COUNT_TWO;
        solution.first_root  = ( - coeffs->b - sqrtf_discriminant ) / ( 2 * coeffs->a );
        solution.second_root = ( - coeffs->b + sqrtf_discriminant ) / ( 2 * coeffs->a );
    }

    return solution;
}


static float calculate_discriminant(const EquationCoefficients * coefficients)
{
    return coefficients->b * coefficients->b - 4 * (coefficients->a) * (coefficients->c);
}


bool is_zero_float(const float num)
{
    return (fabs(num - 0.0f) < FLT_EPSILON);
}


bool is_equal_float(const float num1, const float num2)
{
    return (fabs(num1 - num2) < MY_EPSILON);
}