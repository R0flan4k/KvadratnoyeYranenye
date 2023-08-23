#ifndef CALCULATIONS_H
    #define CALCULATIONS_H

    enum roots_count {
        ROOTS_COUNT_INFINITY = -1,
        ROOTS_COUNT_ZERO, 
        ROOTS_COUNT_ONE, 
        ROOTS_COUNT_TWO
    };


    typedef struct {
        float a;
        float b;
        float c;
    } EquationCoefficients;


    typedef struct {
        roots_count count;
        float first_root;
        float second_root;
    } EquationRoots;


    EquationRoots solve_equation(const EquationCoefficients *);
    float calculate_discriminant(const EquationCoefficients *);
    float calculate_root1(const EquationCoefficients *, const float);
    float calculate_root2(const EquationCoefficients *, const float);
    bool is_equal_float(const float, const float);


#endif