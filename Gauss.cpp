//CIC250 - Cálculo Numérico para Computação
//Exercício Prático 04 - 28/03/18
//2017001437 - Érick de Oliveira Teixeira
//Resolução de Sistemas lineares pelo Método da Eliminação de Gauss

#include <bits/stdc++.h>
using namespace std;

//A DEFINIÇÃO DO TAMANHO DA MATRIZ ENTRADA ACONTECE AQUI
const int N = 4; //Número de linhas da matriz (MUDAR AQUI)
const int M = 5; //Número de colunas da matriz (MUDAR AQUI)

//Definição das variáveis globais
double Matriz[N][M]; //Matriz que identifica o sistema linear
vector<double> var; //Armazena o valor das variáveis

//Funções extras
void mostraMatriz(); //Imprime a matriz a cada passo
int gauss(); //Realiza a eliminação de Gauss

int main(void)
{
	int i, j;
	
	printf("Digite a matriz:\n");
	
	for(int i = 0; i < N; ++i) //Lendo matriz
    {
      for(int j = 0; j < M; ++j)
      {
      	scanf("%lf", &Matriz[i][j]);
	  }
    }
    printf("\n");
  
	gauss(); //Faz o processo de Eliminação de Gauss
    
    printf("Respostas:\n\n");
    for(int i = 0; i < var.size(); i++)
    {
    	printf("x%d = %g\n", i+1, var[i]);
    }
    printf("\n");
  
	return 0;
}

void mostraMatriz()
{
  for(int i = 0; i < N; ++i)
  {
    for(int j = 0; j < M; ++j)
    {
      if(j) printf(" ");
      printf("%.4lf", Matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}

int gauss()
{
  int n = N;
  int m = M - 1;
  double mult; 

  mostraMatriz();
  vector<int> aux(m, -1); //Armazena os coeficientes depois do =
  int lin, col;
  
  for(col = 0, lin = 0; col < m && lin < n; ++col)
  {
    int atual; //linha atual
    atual = lin;
    
    for(int i = lin; i < n; ++i) //seleciona linhas
    {
    	if( abs(Matriz[i][col]) > abs(Matriz[atual][col]) ) //seleciona a maior eq
        atual = i;
	}
     
    for(int i = col; i <= m; ++i) //Efetua a troca das linhas (maior acima)
    {
    	swap(Matriz[atual][i], Matriz[lin][i]);
	}
    aux[col] = lin; // associa coluna/linha/ eq

    for(int i = 0; i < n; ++i) //Procedimento para deixar a matriz triangulada superior
    {
      if(i != lin)
      {
        //Cálculo do valor a ser multiplicado
        mult = Matriz[i][col] / Matriz[lin][col];
        
        for(int j = col; j <= m; ++j)
        {
          Matriz[i][j] -= mult*Matriz[lin][j]; //Subtrai após a multiplicação
        }
      }
    }
    lin++;
    
	mostraMatriz();
  }

  var.assign(m, 0);

  for(int i = 0; i < m; ++i)
  {
    if(aux[i] != -1) //Se houver termo independente (depois do = )
  	{
  		var[i] = Matriz[aux[i]][m] / Matriz[aux[i]][i]; //Calcula postas (valor das variáveis)
	}  	
  } 

  for(int i = 0; i < n; ++i)
  {
    double sum = 0;
    for(int j = 0; j < m; ++j)
    {
    	sum += var[j] * Matriz[i][j]; //variável * coeficiente
	}
  }
}
