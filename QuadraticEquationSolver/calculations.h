/////////////////////////////////////////////////////////////////////////
/// \file calculations.h
/// \brief
/////////////////////////////////////////////////////////////////////////

#ifndef     CALCULATIONS_H
    #define CALCULATIONS_H

    const double MY_EPSILON = 1e-5;

    /////////////////////////////////////////////////////////////////////////
    /// \brief Equation roots count.    
    /////////////////////////////////////////////////////////////////////////
    enum RootsCount {                          
        ROOTS_COUNT_INFINITY = -1,   ///< Infinity number of roots.                      
        ROOTS_COUNT_ZERO,            ///< Zero roots.
        ROOTS_COUNT_ONE,             ///< One root.
        ROOTS_COUNT_TWO              ///< Two roots.
    };

    /////////////////////////////////////////////////////////////////////////
    /// \brief Coefficients of quadratic equation.
    /////////////////////////////////////////////////////////////////////////
    struct EquationCoefficients {                         
        float a;                                        
        float b;                                                    
        float c;
    };

    /////////////////////////////////////////////////////////////////////////
    /// \brief Roots and number of roots storage.
    /////////////////////////////////////////////////////////////////////////
    struct EquationRoots {                    
        RootsCount count; 
        float first_root;
        float second_root;
    };

    /////////////////////////////////////////////////////////////////////////
    /// \brief Solving equation using input data.
    /// \param[in] coeffs Coefficients of equation
    /// \return Equation roots and number of roots.
    /////////////////////////////////////////////////////////////////////////
    EquationRoots solve_equation(const EquationCoefficients * coeffs);   

    /////////////////////////////////////////////////////////////////////////
    /// \brief Check if two of float numbers are equal.
    /// \param[in] num1 First number of comparing.
    /// \param[in] num2 Second number of comparing.
    /// \return Is first number equal to second number.
    /////////////////////////////////////////////////////////////////////////
    bool is_equal_float(const float num1, const float num2);

    /////////////////////////////////////////////////////////////////////////
    /// @brief Check if float number is equal to zero.
    /// @param[in] num Checking float number.
    /// @return Is this number zero.
    /////////////////////////////////////////////////////////////////////////
    bool is_zero_float(const float num);


#endif // CALCULATIONS_H