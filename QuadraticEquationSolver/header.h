enum RootsCount {
    infinity = -1,
    zero, 
    one, 
    two
};


enum Languages {
    russian = 'r',
    english = 'e',
    germany = 'g',
    chinese = 'c'
};


typedef struct {
    Languages language_indentification;
    const char * language_menu;
    const char * language_request;
    const char * language_error;
    const char * language_show_equation;
    const char * language_inf_roots;
    const char * language_no_roots;
    const char * language_one_root;
    const char * language_two_roots;
    const char * language_this_root;
    const char * language_first_root;
    const char * language_second_root;
} OutputLanguages;


typedef struct {
    float a;
    float b;
    float c;
} EquationCoefficients;


typedef struct {
    RootsCount count;
    float first_root;
    float second_root;
} EquationRoots;


Languages get_language(void);                       
void show_menu(const Languages);
void show_equation_format(void);
void show_user_equation(const EquationCoefficients *);
EquationCoefficients get_coefficients(const Languages);
EquationRoots solve_equation(const EquationCoefficients *);
void show_equation(const EquationCoefficients *, const Languages);
void show_one_root(const float);
void show_solution(const EquationRoots *, const Languages);
float calculate_discriminant(const EquationCoefficients *);
float calculate_root1(const EquationCoefficients *, const float);
float calculate_root2(const EquationCoefficients *, const float);
bool check_equality_float(const float, const float);
void show_goodbye(const Languages);