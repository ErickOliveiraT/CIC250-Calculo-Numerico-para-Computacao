//CIC250 - Cálculo Numerico para Computação
//Exercício Prático 07 - 25/04/2018
//2017001437 - Érick de Oliveira Teixeira
//Interpolacao pelo Metodo de Newton

#include <stdio.h>
#include <math.h>

int main(void)
{
    int i, j, n, lin, auxi;
    int ord;


    printf("Insira a quantidade de pontos conhecidos: ");
    scanf("%d", &n);

    double o[n][n];
    double x[n], fx[n];

    for(i = 0; i < n; i++) //Lendo valores dos pontos conhecidos
    {
        printf("\nx%d = ", i+1);
        scanf("%lf", &x[i]);
        printf("f(x%d) = ", i+1);
        scanf("%lf", &fx[i]);
    }
    
    //Montando a tabela
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            o[i][j] = 0.0;
        }
    }

    for(i = 0; i < n; i++)
    {

        o[i][0] = fx[i];
    }

    lin = n;
    auxi = 0;

    for(ord = 1; ord < n; ord++)
    {
        lin--;
        auxi = ord;
        for(i = 0; i < lin; i++)
        {
            o[i][ord]= (o[i+1][ord-1]-o[i][ord-1])/(x[auxi]-x[i]);
            auxi++;
        }
    }
    
    //Imprimindo a tabela
	printf("\n\nTabela de Newton:\n\n");
    for(i = 0; i < n; i++)
    {
        printf("\tD%d\t", i);
    }
    printf("\n\n");
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(j == n-1)
            {
                if (o[i][j] == 0.0) printf("\t--------\n");
                else printf("\t%lf\n", o[i][j]);
            }
            else
            {
            	if (o[i][j] == 0.0) printf("\t--------");
            	else printf("\t%lf", o[i][j]);
			}

        }
    }
      
    return 0;
}
