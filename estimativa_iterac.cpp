//CIC250 - Cálculo Numérico para Computação
//Exercício Prático 02 - 14/03/18
//2017001437 - Érick de Oliveira Teixeira
//Algoritmo para estimativa de iterações pelo método da bissecção
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	double a, b, e, k;
	
	printf("Insira o intervalo [a,b]: ");
	scanf("%lf %lf", &a, &b);
	printf("Insira o erro: ");
	scanf("%lf", &e);
	
	k = (log10(b-a)-log10(e))/log10(2);
	
	printf("\n\nEstimativa de iteracoes: %lf\n\n", k);
	return 0;
}
