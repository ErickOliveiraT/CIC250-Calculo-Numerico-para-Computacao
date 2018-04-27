//CIC250 - Cálculo Numérico para Computação
//Exercício Prático 05 - 04/04/18
//2017001437 - Érick de Oliveira Teixeira
//Resolução de sistemas lineares pelo método de Gauss-Seidel

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define MAX_IT 15 //Número máximo de iterações

double calcula_x(double x,double y,double z); //Inserir a expressão de x isolado nessa função
double calcula_y(double x,double y,double z); //Inserir a expressão de y isolado nessa função
double calcula_z(double x,double y,double z); //Inserir a expressão de z isolado nessa função

double max(double x,double y,double z); //Retorna o valor da maior variável

int main(void)
{
    int k = 1;
    double x, y, z, dtax, dtaz, dtay, dta, erro;
    double x_ant, y_ant, z_ant;
    
    x = y = z = 1.0;
    
    printf("Digite a precisao desejada: ");
    scanf("%lf", &erro);
    
    dta = 1;
    x = calcula_x(x, y, z);
    y = calcula_y(x, y, z);
    z = calcula_z(x, y, z);
    
    printf("\nK\tX\t\tY\t\tZ\t\tDta X\t\tDta Y\t\tDta Z\t\tDta Geral\n");
    
	while (1)
	{
        x_ant = x;
        y_ant = y;
        z_ant = z;
        
		x = calcula_x(x, y, z);
        y = calcula_y(x, y, z);
        z = calcula_z(x, y, z);
        
		dtax = fabs(x - x_ant);
        dtay = fabs(y - y_ant);
        dtaz = fabs(z - z_ant);
        
		dta = fabs(max(dtax,dtay,dtaz)/max(x, y, z));
        
        printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",k , x, y, z, dtax, dtay, dtaz, dta);
        k++;  
        
		if(dta < erro) break;
		if(k > MAX_IT) break;
    }
    
    printf("\n\nResultado final:\n\n");
    printf("X = %lf\nY = %lf\nZ = %lf\n\n", x, y, z);
    
    return 0;
}

double calcula_x(double x,double y,double z)
{
    double aux;
    aux = (5-y-z)/4;
    return aux;
}

double calcula_y(double x,double y,double z)
{
    double aux;
    aux = (-z+2*x)/5;
    return aux;
}

double calcula_z(double x,double y,double z)
{
    double aux;
    aux = (-6.5-3*x-y)/6;
    return aux;
}

double max(double x,double y,double z)
{
    double max;
    if(x>y)
	{
        if(x>z) max = x;    
        else max = z;         
    }
	else
	{ 
        if(y>z) max =y;         
        else max = z;
    }
    return max;
}
