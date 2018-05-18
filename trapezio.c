//CIC250 - Cálculo Numérico para Computação
//Exercício Prático 10 - 16/05/2018
//2017001437 - Érick de Oliveira Teixeira
//Integração pelo método dos trapézios

#include <stdio.h>
#include <math.h>

double f(double x) //A definição da função acontece AQUI
{
	//return 1-exp(-2*x);
	return 6+3*cos(x);
	//return 1-x-4*pow(x,3)+2*pow(x,5);
}

double df(double x) //A definição da derivada segunda da função acontece AQUI
{
	//return -4*exp(-2*x);
	return -3*cos(x);
	//return 40*pow(x,3)-24*x;
}

int main()
{
	double a, b, h, it, x0, x1, erro, maior;
	
	//Lendo valores de a e b da integral:
	printf("Digite o valor de a: ");
	scanf("%lf", &a);
	printf("Digite o valor de b: ");
	scanf("%lf", &b);
	
	x0 = a;
	x1 = b;
	h = x1-x0; //Calculando h
	
	it = (h/2)*(f(x0)+f(x1)); //Calculando integral pelo método do trapézio

	//Vendo qual derivada segunda é maior
    double dfx0 = fabs(df(x0));
    double dfx1 = fabs(df(x1));
    if(dfx0 > dfx1) maior = dfx0;
    else maior = dfx1;
	
	//Calculando o erro
	erro = (pow(h,3.0)/12.0);
	erro *= maior;
	
	//Mostrando os resultados
	printf("\n\nIt = %lf\n\n", it);
	printf("Et <= %lf\n\n", erro);
	printf("\nDados adicionais:\n\nf''(x0) = %lf\nf''(x1) = %lf\nh = %lf\n", df(x0), df(x1), h);
	
	
	return 0;
}
