//CIC250 - C�lculo Num�rico para Computa��o
//Exerc�cio Pr�tico 02 - 14/03/18
//2017001437 - �rick de Oliveira Teixeira
//C�lculo de ra�zes de fun��es reais - m�todo da falsa posi��o
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
  
  if(f(A)*f(B) <= 0)
  {
    while(abs(A-B) > prec)
    {
      cont++;
      if(cont >= MAX_TRY) break;
      
      centro = (A * f(B) - B * f(A)) / (f(B) - f(A));
      
	  if(f(A) * f(centro) > 0) A = centro;
      else B = centro; 
    }
    
    printf("Raiz encontrada!!\n\nx = %lf\n\n", centro);
    printf("Numero de iteracoes = %d\n", cont);
  }
  else
  {
    printf("Nao existe raiz no intervalo [%.2lf,%.2lf]\n", A, B);
    return 0;
  }
	return 0;
}

