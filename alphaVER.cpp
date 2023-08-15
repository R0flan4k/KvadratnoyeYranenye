#include <stdio.h>
#include <tgmath.h>
#define DISCR(A,B,C) (pow(B,2.0)-4*(A)*(C))
#define FIRST_ROOT(A,B,C) ((-(B)-sqrt((pow(B,2.0))-4*(A)*(C)))/(2*(A)))
#define SECOND_ROOT(A,B,C) ((-(B)+sqrt((pow(B,2.0))-4*(A)*(C)))/(2*(A)))
typedef struct {
    float a;
    float b;
    float c;
} coefs;
void show_menu(void);
coefs get_coefs(void);
int show_ans(const coefs *);
int main(void)
{
    coefs input = {0,0,0};
    show_menu();
    input=get_coefs();
    show_ans(&input);
    puts("Have a good day! End.");
    return 0;
}
void show_menu(void)
{
    puts("Hello, Ruslan Alekseyevich.");
    puts("This program can solve quadratic equation");
    puts("Equation must looks like: ax^2 + bx + c = 0.");
}
coefs get_coefs(void)
{
    coefs input = {0,0,0};
    puts("Enter coeficients a,b,c:");
    while (scanf("%f%f%f",&input.a,&input.b,&input.c)!=3)
    {
        puts("Error. Enter 3 real numbers");
        puts("like 12, -1.5, 3.14 or 1.618");
        scanf("%*s");
    }
    return input;
}
int show_ans(const coefs * inp)
{
    printf("Your equation: %.3g*x^2 + %.3g*x + %.3g = 0\n",inp->a,inp->b,inp->c);
    if (inp->a==0 && inp->b==0 && inp->c==0)
    {
        puts("This equation has an infinite number of roots");
        return -1;
    }
    else if (inp->a==0 && inp->b!=0)
    {
        puts("This equation has only one root (a==0)");
        printf("This root: %5.5g\n",-(inp->c/inp->b));
        return 1;
    }
    else if (DISCR(inp->a,inp->b,inp->c)<0 || (inp->a==0 && inp->b==0 && inp->c!=0))
    {
        puts("This equation hasn't real roots.");
        return 0;
    }
    else if (DISCR(inp->a,inp->b,inp->c)==0)
    {
        puts("This equation has only one root (discriminant == 0)");
        printf("This root: %5.5g\n",FIRST_ROOT(inp->a,inp->b,inp->c));
        return 1;
    }
    else
    {
        puts("This equation has 2 roots");
        printf("first root: %5.5g\nsecond root: %5.5g\n",FIRST_ROOT(inp->a,inp->b,inp->c),
        SECOND_ROOT(inp->a,inp->b,inp->c));
        return 2;
    }
}