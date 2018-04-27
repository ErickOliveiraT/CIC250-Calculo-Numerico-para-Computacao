//CIC250 - C�lculo Num�rico para Computa��o
//Exerc�cio Pr�tico 02 - 14/03/18
//2017001437 - �rick de Oliveira Teixeira
//C�lculo de ra�zes de fun��es reais - m�todo da bissec��o
#include <bits/stdc++.h>
using namespace std;

//Constantes para defini��o de precis�o e n�mero max de itera��es
const int MAX_TRY = 50;
const double prec = 0.001;

double f(double x) //A defini��o da fun��o acontece AQUI
{
	return sin(x)-x-1;
}

int main(void)
{
	double A, B, centro; //Extremos R/L e valor central
	int cont = 0; //Contagem de itera��es
    
    printf("Insira o intervalo real [a,b]: ");
    scanf("%lf %lf", &A, &B);
    
    if(f(A)*f(B) <= 0) //Se a x passar de negativo para positivo nesse intervalo
    {
    	while(abs(A-B) > prec)
    	{
    		cont++;
    		if(cont >= MAX_TRY) break;
    		
    	    centro = (A+B)/2.0;
     	    if(f(centro)*f(A) > 0) A = centro;
      	    else B = centro;   	
    	}
    	
		printf("Raiz encontrada!!\n\nx = %lf\n\n", centro);
		printf("Quantidade de iteracoes = %d\n", cont);
		return(0);
    }
    else
    {
    	printf("\nNao existe raiz no intervalo [%.2lf,%.2lf]\n", A, B);
    	return 0;
    }
}
