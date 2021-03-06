//CIC250 - C�lculo Num�rico para Computa��o
//Exerc�cio Pr�tico 05 - 04/04/18
//2017001437 - �rick de Oliveira Teixeira
//Resolu��o de sistemas lineares pelo m�todo de Gauss-Jacobi

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define MAX_IT 15 //N�mero m�ximo de itera��es

double calcula_x(double x,double y,double z); //Inserir a express�o de x isolado nessa fun��o
double calcula_y(double x,double y,double z); //Inserir a express�o de y isolado nessa fun��o
double calcula_z(double x,double y,double z); //Inserir a express�o de z isolado nessa fun��o

double max(double x,double y,double z); //Retorna o valor da maior vari�vel

int main(void)
{
    int k = 1;
    double x, y, z, dtax, dtaz, dtay, dta, erro;
    double x_ant, y_ant, z_ant;
    
    x = y = z = 1.0;
    
    printf("Digite a precisao desejada: ");
    scanf("%lf", &erro);
    
    dta = 1;
    x = calcula_x(1,1,1);
    y = calcula_y(1,1,1);
    z = calcula_z(1,1,1);
    
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
    //aux = (7-2*y-z)/10;
    aux = (0.7+0.1*y-sqrt(x))/0.005;
    return aux;
}

double calcula_y(double x,double y,double z)
{
    double aux;
    //aux = (-8-x-z)/5;
    aux = sqrt(0.5+0.3*x+0.1*sqrt(x));
    return aux;
}

double calcula_z(double x,double y,double z)
{
    double aux;
    //aux = (6-2*x-3*y)/10;
    aux = (1.2-0.4*y-0.1*sqrt(x)*z);
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
