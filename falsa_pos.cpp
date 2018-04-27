//CIC250 - Cálculo Numérico para Computação
//Exercício Prático 02 - 14/03/18
//2017001437 - Érick de Oliveira Teixeira
//Cálculo de raízes de funções reais - método da falsa posição
#include <bits/stdc++.h>
using namespace std;

//Constantes para definição de precisão e número max de iterações
const int MAX_TRY = 50;
const double prec = 0.001;

double f(double x) //A definição da função acontece AQUI
{
  return sin(x)-x-1;
}

int main(void)
{
  double A, B, centro; //Extremos R/L e valor central
  int cont = 0; //Contagem de iterações
  
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

