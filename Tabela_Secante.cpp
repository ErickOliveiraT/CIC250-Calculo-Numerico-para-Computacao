#include <bits/stdc++.h>
using namespace std;

//A definição das precisões acontece AQUI
const double prec1 = 0.001;
const double prec2 = 0.001;

double f(double x) //A definição da função Acontece AQUI
{
	//return pow(2,x)-(2*x*x)+1;
	return -0.5*x*x+2.5*x+4.5;
}

int main(void)
{
	double x0, x1, fx0, fx1, x2, dif, fx2, raiz;
	int cont = 0, max_it;
	
	printf("Insira as aproximacoes iniciais (x0 e x1): ");
	scanf("%lf %lf", &x0, &x1);
	printf("Insira o numero max de iteracoes: ");
	scanf("%d", &max_it);
	
	fx0 = f(x0);
	fx1 = f(x1);
	x2 = (x0*fx1 - x1*fx0)/(fx1-fx0);
	dif = abs(x1-x0);
	printf("\n");
	
	if (abs(fx0) < prec1)
	{
		raiz = x0;
		printf("\n\nRaiz encontrada!   x = %lf\n\n", raiz);
		return 0;
	}
	
	if (abs(fx1) < prec1 || abs(dif) < prec2)
	{
		raiz = x1;
		printf("\n\nRaiz encontrada!   x = %lf\n\n", raiz);
		return 0;
	}
	
	cont++;
	printf("k = %d\n", cont);
	printf("x0 = %lf\n", x0);
	printf("x1 = %lf\n", x1);
	printf("f(x0) = %lf\n", fx0);
	printf("f(x1) = %lf\n", fx1);
	printf("x2 = %lf\n", x2);
	printf("f(x2) = %lf\n\n", fx2);
	
	while (cont < max_it)
	{
	    cont++;
		
		x0 = x1;
		x1 = x2;
	    fx0 = f(x0);
		fx1 = f(x1);
	    //x2 = (x0*fx1 - x1*fx0)/(fx1-fx0);
	    x2 = x1 - (fx1/(fx1-fx0))*(x1-x0);
	    dif = abs(x1-x0);
	    fx2 = f(x2);
		
		printf("k = %d\n", cont);
		printf("x0 = %lf\n", x0);
		printf("x1 = %lf\n", x1);
		printf("f(x0) = %lf\n", fx0);
		printf("f(x1) = %lf\n", fx1);
		printf("x2 = %lf\n", x2);
		printf("f(x2) = %lf\n\n", fx2);
		
		//if (abs(fx2) < prec1) break;
		//if (abs(dif) < prec1) break;
		if (cont == 3) break;
	}
	
	printf("\nRaiz encontrada!  x = %lf\n", x2);
	printf("Numero de iteracoes = %d\n\n", cont);
	
	return 0;	
}

