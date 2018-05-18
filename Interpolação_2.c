//CIC250 - Cálculo Númerico para Computação
//Exercício Prático 6 - 11/04/2018
//2017001437 - Érick de Oliveira Teixeira
//Interpolação Polinomial

#include <stdio.h>
#include <math.h>

int main(void)
{
	double matriz[100][100], c, a[100], soma=0.0, x[100], fx[100];
	int i, j, v, n, k;
	printf("Quantidade de pontos conhecidos: ");
	scanf("%d", &n);

	for(i = 1; i <= n; i++)
	{
		printf("\nDigite x%d : ", i-1);
		scanf("%lf", &x[i]);
		printf("Digite fx%d : ", i-1);
		scanf("%lf", &fx[i]);
	}

	//Calcula a matriz do sistema
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n+1; j++)
		{
		    matriz[i][6] = x[i]*x[i]*x[i]*x[i]*x[i];
		    matriz[i][5] = x[i]*x[i]*x[i]*x[i];
			matriz[i][4] = x[i]*x[i]*x[i];
			matriz[i][3] = x[i]*x[i];
			matriz[i][2] = x[i];
			matriz[i][1] = 1;
			matriz[i][n+1] = fx[i];
		}
	}
	
	//Imprime a matriz do sistema
	printf("\n\nMatriz:\n\n");
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n+1; j++)
		{
			printf("%lf\t", matriz[i][j]);
		}
		printf("\n");
	}


	//Fazendo Eliminação de Gauss
	for(j = 1; j <= n; j++)
	{
		for(i = 1; i <= n; i++)
		{
			if(i>j)
			{
				c = -(matriz[i][j]/matriz[j][j]);
				for(v = 1; v <= n+1; v++)
				{
					matriz[i][v] = c * matriz[j][v] + matriz[i][v];
				}
			}

		}
	}
	
	//Mostrando matriz triangularizada
	printf("\n\nMatriz Triangularizada:\n\n");
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n+1; j++)
		{
			printf("%lf\t", matriz[i][j]);
		}
		printf("\n");
	}

	//Calculando as variáveis do sistema
	a[n]=matriz[n][n+1]/matriz[n][n];
	for(i = n-1; i >= 1; i--)
	{
		soma = 0;
		for(j = i+1; j <= n; j++)
		{
			soma = soma+matriz[i][j]*a[j];
		}
		a[i]=(matriz[i][n+1]-soma)/matriz[i][i];
	}
	
	//Mostrando resultado
	printf("\n\nSolucoes:\n");
	for(i = 1;i <= n; i++)
	{
		printf("\na%d = %lf", i-1,a[i]);
	}
	
	//Imprimindo g(x)
	printf("\n\ng(x) = ");
	for(i = 1; i <= n; i++)
	{
		if (a[i] > 0) printf("+ ");
		printf("%lf x^%d ", a[i], i-1);
	}

	return 0;
}
