//CIC250 - Cálculo Númerico para Computação
//Exercício Prático 6 - 11/04/2018
//2017001437 - Érick de Oliveira Teixeira
//Interpolação Polinomial

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void eliminacao_gauss(float **m, int n, int j); //Faz Eliminação de Gauss
void calcula_var(float **m, int n, float *x); //Calcula valor das variáveis

int main(void)
{
    int n, i, j;
    float fx,val;

    printf("Quantidade de pontos conhecidos: ");
    scanf("%d",&n);
    
	float *x =(float*)malloc(sizeof(float)*n); 
    float *xr = (float*)malloc(sizeof(float)*n);
    float **m = (float**)malloc(sizeof(float*)*n);
    
    printf("\n");
    for(i = 0; i < n; i++)
	{
        printf("Insira x%d: ",i); //Lendo valores de xn
        scanf("%f",&x[i]);
        m[i] = (float*)malloc(sizeof(float)*n+1);
    }
    printf("\n");
    
    for(i = 0; i < n; i++) //Lendo valores de f(xn)
	{
        for(j = 0; j < n+1; j++)
		{
            if(j != n)
			{
                m[i][j] = pow(x[i],j);
            }
            else
			{
                printf("Insira f(x%d): ", i);
                scanf("%f", &m[i][j]);
            }
        }
    }

    j = 0; //Fazendo Eliminação de Gauss
    do
	{
    	eliminacao_gauss(m,n,j);
        j++;
    }while(j < n-1);

    printf("\nResultado:\n\n"); //Mostrando resultado

    calcula_var(m,n,xr);
}

void eliminacao_gauss(float **m, int n, int j) //Faz Eliminação de Gauss
{
    float val;
    int i = j;
    
	do
	{
	    val = m[i+1][j]/m[j][j];
	    int k;

	    for(k = 0;k < n+1; k++)
		{
	        m[i+1][k] = m[i+1][k]-m[j][k]*val;
	    }	
	    i++;

    }while(m[i][i] != m[n-1][n-1]);
} 

void calcula_var(float **m, int n, float *x) //Calcula valor das variáveis
{
    int i, j;   
	
	for(i = 0; i < n; i++) x[i] = 0;

    x[n-1] = 0; 
    
	//Resolvendo sistema já simplificado com Gauss
    for(i = (n-1); i >= 0; i--)
	{
        for(j = 0; j < n; j++)
		{
            if( i != j)
			{
                x[i] -= x[j]*m[i][j];
            }
        }
        x[i] += m[i][n];
        x[i] /= m[i][i];
    }

    for(i = 0; i < n;i++) //mostrando valor das variáveis
	{
        printf("x%d = %f\n", i, x[i]);
    }

    printf("\ng(x) = "); //Montando e imprimindo g(x) -- função interpolada
    for(i = 0; i < n; i++)
	{
        if(i!=n-1) printf("(%fx^%d) + ", x[i], i);      
        else printf("(%fx^%d)", x[i], i);       
    }
    printf("\n\n");
}  
