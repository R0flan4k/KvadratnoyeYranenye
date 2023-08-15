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
    coefs input;
    show_menu();
    input=get_coefs();
    show_ans(&input);
    puts("Vsego dobrogo! Programma zavershena.");
    return 0;
}
void show_menu(void)
{
    puts("Dobriy den, Ruslan Alekseyevich.");
    puts("Eta programma prednoznachena dlya reshenya kvadratnih yravneniy");
    puts("Pust' yravneniye imeet vid: ax^2 + bx + c = 0.");
}
coefs get_coefs(void)
{
    coefs input;
    puts("Vvedite koeficienti a,b,c:");
    while (scanf("%f%f%f",&input.a,&input.b,&input.c)!=3)
    {
        puts("Oshibka. Vvedite 3 deysvitelnih chisla,");
        puts("takih kak 12, -1.5, 3.14 ili 1.618");
        scanf("%*s");
    }
    return input;
}
int show_ans(const coefs * inp)
{
    printf("Vvedennye uravneniye: %.3g*x^2 + %.3g*x + %.3g = 0\n",inp->a,inp->b,inp->c);
    if (DISCR(inp->a,inp->b,inp->c)<0)
    {
        puts("Dannoye yravneniye ne imeet veshestvennih korney.");
        return 0;
    }
    else if (DISCR(inp->a,inp->b,inp->c)==0)
    {
        puts("Dannoue yravneniye yavlayetca polnim kvadratom (discriminant = 0)");
        printf("koren yravneniya: %5.3g\n",FIRST_ROOT(inp->a,inp->b,inp->c));
        return 1;
    }
    else
    {
        puts("Dannoye yravneniye imeet 2 kornya");
        printf("perviy koren: %5.3g\nvtoroy koren: %5.3g\n",FIRST_ROOT(inp->a,inp->b,inp->c),
        SECOND_ROOT(inp->a,inp->b,inp->c));
        return 2;
    }
}