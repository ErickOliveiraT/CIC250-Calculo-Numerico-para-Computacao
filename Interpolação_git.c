//CIC250 - Cálculo Númerico para Computação
//Exercício Prático 6 - 11/04/2018
//2017001437 - Érick de Oliveira Teixeira
//Interpolação Polinomial

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mostraMatriz(float **m, int n)
{
	int i, j;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n+1; j++)
		{
			printf("%.1f ",m[i][j]);
		}
		printf("\n");     
    }
}

void gauss(float **m, int n, int j)
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

	    printf("val = %f\n\n",val);
	    mostraMatriz(m,n);
	    printf("\n\n");
    }while(m[i][i] != m[n-1][n-1]);
}

void solve(float **m, int n, float *x)
{
    int i, j;   
	
	for(i = 0; i < n; i++) x[i] = 0;

    x[n-1] = 0; 
    
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

    for(i = 0; i < n;i++)
	{
        printf("x%d = %f\n", i, x[i]);
    }

    printf("\nSistema: ");
    for(i = 0; i < n; i++)
	{
        if(i!=n-1) printf("(%.2fx^%d) + ", x[i], i);      
        else printf("(%.2fx^%d)", x[i], i);       
    }
    printf("\n\n");
}   

int main(void)
{
    int n, i, j;
    float fx,val;

    printf("Quantidade de pontos conhecidos:");
    scanf("%d",&n);
    
    float *x =(float*)malloc(sizeof(float)*n);
    float *xr = (float*)malloc(sizeof(float)*n);
    float **m = (float**)malloc(sizeof(float*)*n);
    
    for(i = 0; i < n; i++)
	{
        printf("Digite o valor de x%d: ",i);
        scanf("%f",&x[i]);
        m[i] = (float*)malloc(sizeof(float)*n+1);
    }
    
    for(i = 0; i < n; i++)
	{
        for(j = 0; j < n+1; j++)
		{
            if(j != n)
			{
                m[i][j] = pow(x[i],j);
                //printf("m[%d][%d] = %.2f ",i , j, m[i][j]);
            }
            else
			{
                //printf("m[%d][%d] = ", i, j);
                printf("f(x%d) = ", i);
                scanf("%f", &m[i][j]);
            }
        }
        printf("\n");
    }

    j = 0;
    printf("METODO ELIMINACAO DE GAUSS \n\n");
    do
	{
    	gauss(m,n,j);
        j++;
    }while(j < n-1);

    printf("RESULTADO\n");

    solve(m,n,xr);

    printf("Informe o valor de x a ser calculado = ");
    scanf("%f", &val);
    printf("Resultado = ");
    fx = xr[0];
    
    for(i = 1; i < n; i++)
	{
        fx += xr[i]*pow(val,i);
    }
    printf("%f\n\n", fx);

    for(i = 0; i < n; i++) free(m[i]);
	    
    free(m);
    free(x);
}
