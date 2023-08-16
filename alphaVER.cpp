#include <stdio.h>
#include <math.h>
#define DISCR(A,B,C) (powf(B,2.0)-4*(A)*(C))
#define FIRST_ROOT(A,B,C) ((-(B)-sqrtf((powf(B,2.0))-4*(A)*(C)))/(2*(A)))
#define SECOND_ROOT(A,B,C) ((-(B)+sqrtf((powf(B,2.0))-4*(A)*(C)))/(2*(A)))

typedef struct {
    float a;
    float b;
    float c;
} coefs;

typedef struct {
    int count;
    float first;
    float second;
} ans;

void show_menu(void);
coefs get_coefs(void);
ans solve_ans(const coefs * );
void show_equation(const coefs *);
void show_ans(const ans *);

int main(void)
{
    ans answer;
    coefs input = {0,0,0};
    show_menu();
    input=get_coefs();
    answer=solve_ans(&input);
    show_equation(&input);
    show_ans(&answer);
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

ans solve_ans(const coefs * inp)
{
    ans answer = {0,0.0,0.0};
    if (inp->a==0)
    {
        if (inp->b==0)
        {
            if (inp->c==0)
            answer.count = -1;
            else answer.count = 0;
        }    
        else 
        {
            answer.count = 1;
            answer.first = -(inp->c/inp->b);
        }       
    }
    else if (DISCR(inp->a,inp->b,inp->c)<0)
    {
        answer.count = 0;
    }
    else if (DISCR(inp->a,inp->b,inp->c)==0)
    {
        answer.count = 1;
        answer.first = FIRST_ROOT(inp->a,inp->b,inp->c);
    }
    else 
    {
        answer.count = 2;
        answer.first = FIRST_ROOT(inp->a,inp->b,inp->c);
        answer.second = SECOND_ROOT(inp->a,inp->b,inp->c);
    }
    return answer;
}

void show_equation(const coefs * inp)
{
    printf("Your equation: %.3g*x^2 + %.3g*x + %.3g = 0\n",inp->a,inp->b,inp->c);
}

void show_ans(const ans * answer)
{
    if (answer->count == -1)
    {
        puts("This equation has infinite number of roots");
    }
    else if (answer->count == 0)
    {
        puts("This equation hasn't roots");
    }
    else if (answer->count ==1)
    {
        puts("This equation has one root");
        printf("This root: %5.5g\n",answer->first);
    }
    else
    {
        puts("This equation has two roots");
        printf("First root: %5.5g\n",answer->first);
        printf("Second root: %5.5g\n",answer->second);
    }
}