enum ROOTS_COUNT {
    ROOTS_COUNT_INFINITY = -1,
    ROOTS_COUNT_ZERO, 
    ROOTS_COUNT_ONE, 
    ROOTS_COUNT_TWO
};


enum LANGUAGES {
    RUSSIAN,
    ENGLISH,
    GERMANY,
    CHINESE
};


typedef struct {
    LANGUAGES language_indentification;
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
    const char * language_goodbye;
} OutputLanguages;


typedef struct {
    float a;
    float b;
    float c;
} EquationCoefficients;


typedef struct {
    ROOTS_COUNT count;
    float first_root;
    float second_root;
} EquationRoots;


OutputLanguages * get_language(void);                       
void show_menu(const OutputLanguages *);
void show_equation_format(void);
void show_user_equation(const EquationCoefficients *);
EquationCoefficients get_coefficients(const OutputLanguages *);
EquationRoots solve_equation(const EquationCoefficients *);
void show_equation(const EquationCoefficients *, const OutputLanguages *);
void show_one_root(const float);
void show_solution(const EquationRoots *, const OutputLanguages *);
float calculate_discriminant(const EquationCoefficients *);
float calculate_root1(const EquationCoefficients *, const float);
float calculate_root2(const EquationCoefficients *, const float);
bool check_equality_float(const float, const float);
void show_goodbye(const OutputLanguages *);