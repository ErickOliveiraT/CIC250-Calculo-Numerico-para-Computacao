//CIC250 - Cálculo Numérico para Computação
//Exercício Prático 10 - 16/05/2018
//2017001437 - Érick de Oliveira Teixeira
//Integração pelo método dos trapézios repetido

#include <stdio.h>
#include <math.h>

double f(double x) //A definição da função acontece AQUI
{
	return 1-exp(-2*x);
	//return 6+3*cos(x);
	//return 1-x-4*pow(x,3)+2*pow(x,5);
}

double df(double x) //A definição da derivada segunda da função acontece AQUI
{
	return -4*exp(-2*x);
	//return -3*cos(x);
	//return 40*pow(x,3)-24*x;
}

int main(void)
{
	double a, b, h, soma = 0, it, maior, erro;
	int i, t;
	
	//Lendo dados de entrada:
	printf("Digite o valor de a: ");
	scanf("%lf", &a);
	printf("Digite o valor de b: ");
	scanf("%lf", &b);
	printf("Digite a quantidade de trapezios: ");
	scanf("%d", &t);
	
	double x[t+1]; //Vetor que armazena os xi
	x[0] = a; //x0
	x[t] = b; //xn
	
	//Calculando h:
	h = (b-a)/t;
	
	//Calculando os xi:
	for (i = 1; i <= t; i++) x[i] = x[i-1]+h;
	
	//Calculando somatório:
	for (i = 1; i <= t-1; i++) soma += f(x[i]);
	
	//Calculando integral:
	it = (h/2)*(f(x[0]) + f(x[t]) + 2*soma);
	
	//Vendo qual é o maior f''(xk):
	double d2f[t+1]; //Vetor que armazena os valores de f''(xk)
	for (i = 0; i <= t; i++) d2f[i] = fabs(df(x[i])); //Calculando os valores de f''(xk) (em módulo)
	maior = d2f[0];
	for (i = 1; i <= t; i++) if (d2f[i] > maior) maior = d2f[i];
	
	//Calculando erro:
	erro = (pow(h,2)/12.0)*(x[t]-x[0])*maior;
	
	//Mostrando resultandos:
	printf("\n\nIt = %lf\n", it);
	printf("\nEt <= %lf\n", erro);
	printf("\nDados adicionais:\n\n");
	printf("X[0] = %lf\n", x[0]);
	printf("X[n] = %lf\n", x[t]);
	printf("h = %lf\n", h);
	printf("Maior f''(xk) = %lf\n\n", maior);

	return 0;	
}
