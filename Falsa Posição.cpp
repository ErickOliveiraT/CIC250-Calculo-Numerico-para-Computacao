/*
	Nome: Érick de Oliveira Teixeira 
	Matrícula: 2017001437 
	Description: Aplicação do método da falsa posição para cálculo de ráizes de funções
*/
#include <bits/stdc++.h>
using namespace std;

//Constantes para definição de precisão e número max de iterações
const int MAX_TRY = 50;
const double prec = 0.001;

double f(double x) //A definição da função acontece AQUI
{
  return -0.5*x*x+2.5*x+4.5;
}

int main(void)
{
  double A, B, centro; //Extremos R/L e valor central
  int cont = 0; //Contagem de iterações
  
  printf("Insira o intervalo real [a,b]: ");
  scanf("%lf %lf", &A, &B);
   printf("\n\nK\t A\t\t B\t\t Centro\t\t f(A)\t\t f(x)\t\t f(A)*f(x)\n");
  
  if(f(A)*f(B) <= 0)
  {
    while(abs(A-B) > prec)
    {
      cont++;
      //if(cont >= MAX_TRY) break;
      
      centro = (A * f(B) - B * f(A)) / (f(B) - f(A));
      
      printf("%d\t %lf\t %lf\t %lf\t %lf\t %lf\t %lf\n", cont, A, B, centro, f(A), f(centro), f(A)*f(centro));
      
	  if(f(A) * f(centro) > 0) A = centro;
      else B = centro; 
    }
    
    printf("\nRaiz encontrada!!\n\nx = %lf\n\n", centro);
    printf("Numero de iteracoes = %d\n", cont);
  }
  else
  {
    printf("Nao existe raiz no intervalo [%.2lf,%.2lf]\n", A, B);
    return 0;
  }
	return 0;
}
