//CIC250 - Cálculo Numerico para Computação
//
//2017001437 - Érick de Oliveira Teixeira
//Interpolação pelo Método de Lagrange

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int i, k, n;
    double inter, px;

    printf("Quantidade de pontos conhecidos: ");
    scanf("%d", &n);

    double fx[n];
    double x[n], xn, xk;
    double L[n];

    for(i = 0; i < n; i++)
	{
        printf("\nx%d = ", i);
        scanf("%lf", &x[i]);
        printf("f(x%d) = ", i);
        scanf("%lf", &fx[i]);
    }

    printf("\nInforme o valor de x a ser calculado: ");
    scanf("%lf", &inter);

    for(i = 0; i < n; i++)
    {
        xn = 1.0;
        xk = 1.0;
        for(k = 0; k < n; k++)
        {
            if(i==k)continue;
            else
            {
                xn = xn * (inter - x[k]);
                xk = xk * (x[i] - x[k]);
            }
        }
        L[i] = xn/xk;
    }
    
	px = 0.0;
    
	for(i = 0; i < n; i++)
    {
        printf("\nL(%d) = %lf", i, L[i]);
    }
    for(i = 0; i < n; i++)
    {
        px = px + (fx[i] * L[i]);
    }
    printf("\n\nP%d = %lf", n-1, px);


    printf("\n\nP(%lf) = %lf", inter, px);
    return 0;
}

