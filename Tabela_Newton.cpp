#include <bits/stdc++.h>
using namespace std;

//A definição da precisão acontece AQUI
const double prec1 = 0.0001;
const double prec2 = 0.0001;

double f(double x) //A definição da função acontece AQUI
{
  //return pow(2,x)-(2*x*x)+1;
  //return -0.5*x*x+2.5*x+4.5;
  //return -1+5.5*x-4*x*x+0.5*x*x*x;
  //return -0.5*x*x+2.5*x+4.5;
  return 5*x*x*x*x-sin(x);
}

double df(double x) //A definição da derivada da função principal acontece AQUI
{
  //return (log(2)*pow(2,x))-(4*x);
  //return -x+2.5;
  //return 1.5*x*x-8*x+5.5;
  //return -1*x+2.5;
  return 20*x*x*x-cos(x); 
}

int main(void)
{
	double x0, fx0, raiz, x1, dfx0, fx1, dif;
	int n, cont = 0;
	
	printf("Insira a aproximacao inicial (x0): ");
	scanf("%lf", &x0);
	printf("Insira a quantidade max de iteracoes: ");
	scanf("%d", &n);
	printf("\n");
	
	fx0 = f(x0);
	if (abs(fx0) < prec1) 
	{
		raiz = x0;
	}
	cont++;
	
	while (n--)
	{
		fx0 = f(x0);
		dfx0 = df(x0);
		x1 = x0-(fx0/dfx0);
		fx1 = f(x1);
		dif = x1-x0;
		
		printf("k = %d\n", cont);
		printf("x0 = %lf\n", x0);
		printf("f(x0) = %lf\n", fx0);
		printf("f'(x0) = %lf\n", dfx0);
		printf("x1 = %lf\n", x1);
		printf("f(x1) = %lf\n\n", fx1);
		
		if (abs(fx1) < prec1)
		{
			raiz = x1;
			break;
		}
		else if (abs(dif) < prec2)
		{
			raiz = x1;
			break;
		}
		
		x0 = x1;
		cont++;	
	}
	
	printf("\nRaiz encontrada! --> x = %lf\n", raiz);
	printf("Quantidade de iteracoes = %d\n\n", cont);
	return 0;	
}


