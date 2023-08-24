/////////////////////////////////////////////////////////////////////////
/// \file calculations.cpp
/////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>
#include "calculations.h"

/////////////////////////////////////////////////////////////////////////
/// \brief calculating discriminant of equation
/// \param[in] coefficients coefficients of equation inputed
/// \return discriminant
/////////////////////////////////////////////////////////////////////////
static float calculate_discriminant(const EquationCoefficients * coefficients);

/////////////////////////////////////////////////////////////////////////
/// \brief calculating first root of equation
/// \param[in] coefficients coefficients of equation inputed
/// \param[in] sqrtf_discriminant square root of discriminant
/// \return calculated root
/////////////////////////////////////////////////////////////////////////
static float calculate_root1(const EquationCoefficients * coefficients, const float sqrtf_discriminant);

/////////////////////////////////////////////////////////////////////////
/// \brief calculating first root of equation
/// \param[in] coefficients coefficients of equation inputed
/// \param[in] sqrtf_discriminant square root of discriminant
/// \return calculated root
/////////////////////////////////////////////////////////////////////////
static float calculate_root2(const EquationCoefficients *, const float);


EquationRoots solve_equation(const EquationCoefficients * coeffs)
{
    EquationRoots solution = {ROOTS_COUNT_ZERO, 0.0, 0.0};
    float discriminant = calculate_discriminant(coeffs);
    float sqrtf_discriminant = sqrtf(discriminant);

    if (is_equal_float(coeffs->a, 0.0))
    {
        if (is_equal_float(coeffs->b, 0.0))
        {
            if (is_equal_float(coeffs->c, 0.0))
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
    else if (discriminant < 0)
    {
        solution.count = ROOTS_COUNT_ZERO;
    }
    else if (is_equal_float(discriminant, 0))
    {
        solution.count = ROOTS_COUNT_ONE;
        solution.first_root = calculate_root1(coeffs, sqrtf_discriminant);
    }
    else 
    {
        solution.count = ROOTS_COUNT_TWO;
        solution.first_root = calculate_root1(coeffs, sqrtf_discriminant);
        solution.second_root = calculate_root2(coeffs, sqrtf_discriminant);
    }
    return solution;
}


static float calculate_discriminant(const EquationCoefficients * coefficients)
{
    return coefficients->b * coefficients->b - 4 * (coefficients->a) * (coefficients->c);
}


static float calculate_root1(const EquationCoefficients * coefficients, const float sqrtf_discriminant)
{
    return (- coefficients->b - sqrtf_discriminant ) / ( 2 * coefficients->a );
}


static float calculate_root2(const EquationCoefficients * coefficients, const float sqrtf_discriminant)
{
    return (- coefficients->b + sqrtf_discriminant ) / ( 2 * coefficients->a );
}


bool is_equal_float(const float num1, const float num2)
{
    return (fabs(num1 - num2) < FLT_EPSILON);
}