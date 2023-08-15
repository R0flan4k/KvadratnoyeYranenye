#include <stdio.h>
#include <math.h>
typedef struct {
    float a;
    float b;
    float c;
} coefs;
void show_menu(void);
coefs get_coefs(void);
void show_ans(const coefs *);
int main(void)
{
    coefs inpt;
    show_menu();
    inpt=get_coefs();
    printf("%3.3g %3.3g %3.3g\n",inpt.a,inpt.b,inpt.c);
    return 0;
}
void show_menu(void)
{
    puts("Dobriy den, Ruslan Alekseyevich.");
    puts("Eta programma prednoznachena dlya reshenya kvadratnih yravneniy");
    puts("Pust' yravneniye imeet vid ax^2+bx+c=0.");
}
coefs get_coefs(void)
{
    coefs input;
    puts("Vvedite koeficienti a,b,c:");
    while (scanf("%f%f%f",&input.a,&input.b,&input.c)!=3)
    {
        puts("Oshibka. Vvedite 3 deysvitelnih chisla,");
        puts("takih kak 12, 1.5, 3.14 ili 1.618");
        scanf("%*s");
    }
    return input;
}