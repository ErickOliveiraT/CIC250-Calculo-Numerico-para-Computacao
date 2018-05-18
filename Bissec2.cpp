#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
    float y;
    y = pow(x,4)-4*x*x;
    return y;
}

float bissec(float a, float b, float tol)
{
    float c,fa,fb,fc;
    fa=f(a);
    fb=f(b);
    while(fabs(b-a)>tol)
    {
        c=(a+b)/2;
        fc=f(c);
        if(fa*fc<0)
        {
            b=c;
            fb=fc;
        }
        else
        {
            a=c;
            fa=fc;
        }
    }
        c=(a+b)/2;
        return c;

}

int main()
{
    float a, b, c, tol;
    printf("METODO DA BISSECAO. \n \n");
    printf("a = ");
    scanf("%f",&a);
    printf("b = ");
    scanf("%f",&b);
    printf("erro = ");
    scanf("%f",&tol);
    if(f(a)*f(b)>0)
    {
        printf("O intervalo nao e aplicavel. \n \n");
        printf("Digite um novo intervalo. \n \n");
        printf("a = ");
        scanf("%f",&a);
        printf("b = ");
        scanf("%f",&b);
    }
    c=bissec(a,b,tol);
    printf("Raiz aproximada = %0.3f",c);
    system("pause");

    return 0;
}
