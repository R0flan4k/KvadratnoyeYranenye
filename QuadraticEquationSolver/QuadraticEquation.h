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


char get_language(void);                       
void show_menu(const char);
EquationCoefficients get_coefficients(const char);
EquationRoots solve_equation(const EquationCoefficients *);
void show_equation(const EquationCoefficients *, const char);
void show_solution(const EquationRoots *, const char);
float calculate_discriminant(const EquationCoefficients *);
float calculate_root1(const EquationCoefficients *, const float);
float calculate_root2(const EquationCoefficients *, const float);
int check_equality_float(const float, const float);
void show_goodbye(const char);