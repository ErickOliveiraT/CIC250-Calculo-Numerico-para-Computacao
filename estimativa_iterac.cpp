//CIC250 - C�lculo Num�rico para Computa��o
//Exerc�cio Pr�tico 02 - 14/03/18
//2017001437 - �rick de Oliveira Teixeira
//Algoritmo para estimativa de itera��es pelo m�todo da bissec��o
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
