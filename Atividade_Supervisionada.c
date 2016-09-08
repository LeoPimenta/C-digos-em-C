/*Atividade Supervisionada Programação Estruturada
  Autor-------------------Leonardo Correia Pimenta 
  Data de inicio da criação-------------22/05/2016
  Data de término ----------------------05/06/2016
  Matrícula-----------------------------2015101991 
  Turma----------------------------------------831*/ 

//--------Bibliotecas----------//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//--------Protótipos-----------//
void somarMatrizes();
void menuPrincipal();
void limparTela();
void esperarTela();
void GerenteDeOpcoes(int opcao);
void GerenteDeOpcoesMatrizes(int opcao);
void subMenuPrimo();
void subMenuMatrizes();
int verificarPrimo(int x);
void preencherMatriz(); 
void escreverMatriz();
void maiorPrimoDaMatriz();
void subMenuFatorialDeFibonacci();
long int calcularFibonacci(long int x);
long int calcularFatorial(long int x);
void subMenuCartesiano();
void gravarCartesiano();
void lerCartesiano();
void escreverMatrizes();

//------Variaveis Globais------//
int matriz [2] [2] [2];
int mat1 [2] [2] [2];
int mat2 [2] [2] [2];
int maiorPrimo;
int TAMCART; 
//--------Constantes-----------//

#define SAIR    	  0
#define PRIMO   	  1 
#define MATRIZ  	  2 
#define MAIORPRIMO    1
#define FATFIB        3
#define GRAVARLERCART 4
#define GRAVARDADOS   1
#define LERDADOS	  2
#define N 			  10
#define SOMAMATRIZ    2
#define url "arquivos_texto/pontoscartesianos.txt"

int main(int argc, char *argv[]){
	
	menuPrincipal();
	
}

void menuPrincipal()
{
	int opcao;
	
	do
	{
		printf("Digite:\n\n");
		printf("0 - Sair\n");
		printf("1 - Verificar se um numero eh primo.\n");
		printf("2 - Trabalhar com matrizes tridimensionais.\n");
		printf("3 - Obter o fatorial de um numero qualquer da serie de Fibonacci.\n");
		printf("4 - Ler e gravar dados de uma estrutura de pontos cartesianos em \n    um arquivo texto.\n");
		scanf("%d", &opcao);
		
		limparTela();
		
		GerenteDeOpcoes(opcao);	
			
	}while(opcao != SAIR);	
}

void GerenteDeOpcoes(int opcao)
{
	switch(opcao)
	{   
	    case SAIR  :  printf("Saindo do sistema...\n\n");
	    		    	break;		    		    	
		case PRIMO :  subMenuPrimo();
				    	break;				    	
		case MATRIZ:  subMenuMatrizes();
		                break;		       
		case FATFIB:  subMenuFatorialDeFibonacci();
						break;   
		case GRAVARLERCART: subMenuCartesiano();
						break;      
		default    :  printf("Opcao invalida!\n\n");
	}
	esperarTela();
	limparTela();
}

void subMenuPrimo()
{
	int x;
	printf("Digite o numero a ser verificado: ");
	scanf("%d", &x);
	
	limparTela();
	if (verificarPrimo(x))
		{
		    printf("O numero eh primo!\n\n");	
		}
	    else
	    {
	    	printf("O numero nao eh primo!\n\n");
		}
}

int verificarPrimo(int x)
{
	int i; 
	float contador;
	int resultado;
	int num = x;
	
	if(num <= 2)
	{
		return 1;
	} 
	else
	{
		for(i=1 ; i<=num ; i++)
		{
		  resultado = num % i;  
		  		
		  		if (resultado==0)
				  {
					contador = contador + 1;	  	
				  }			  
		}
		
		if (contador == 2)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
}

void subMenuMatrizes()
{
	int opcao;
	
	do
	{
   		 printf("Digite:\n\n");
   		 printf("0 - Sair\n");
   		 printf("1 - Verificar o maior elemento primo em uma matriz tridimensional.\n");
   		 printf("2 - Realizar a soma de duas matrizes tridimensionais.\n");
    
  		scanf("%d", &opcao);
    	 
		 limparTela();
    	 
   		 GerenteDeOpcoesMatrizes(opcao);		
	}while(opcao != SAIR);
	
}

void GerenteDeOpcoesMatrizes(int opcao)
{
	switch(opcao)
	{   
	    case SAIR  :  printf("Saindo...\n\n");
	    		    	break;		    		    	
		case MAIORPRIMO :  maiorPrimoDaMatriz();
				    	break;
		case SOMAMATRIZ :  somarMatrizes();	
						break;			    			                
		default    :  printf("Opcao invalida!\n\n");
	}
	esperarTela();
	limparTela();
}

void somarMatrizes()
{
	int i,j,k;
	
	prencherMAtrizes();
	
	for(i = 0 ; i<2 ; i++)
 	{
 		for(j = 0 ; j<2 ; j++)
		 {
 			for(k = 0 ; k<2 ; k++)
 			{   
 			matriz [i] [j] [k] = mat1 [i] [j] [k] + mat2 [i] [j] [k];	
			}
		}
    }
    
    escreverMatrizes();
}

void escreverMatrizes()
{
	int i,j,k;
	 	for(i = 0 ; i<2 ; i++)
 	{   
	 	
 		for(j = 0 ; j<2 ; j++)
		 {
 			for(k = 0 ; k<2 ; k++)
 		    	{
 			    	printf("Matriz 1: %d(I) - %d(J) - %d(K): %d\n", i,j,k,mat1[i][j][k]);	
			    }    
		} 
    }
    printf("\n\n\n\n\n\n");
    
     	for(i = 0 ; i<2 ; i++)
 	{   
	 	
 		for(j = 0 ; j<2 ; j++)
		 {
 			for(k = 0 ; k<2 ; k++)
 		    	{
 			    	printf("Matriz 2: %d(I) - %d(J) - %d(K): %d\n", i,j,k,mat2[i][j][k]);	
			    }    
		} 
    }
    printf("\n\n\n\n\n\n");
    
     	for(i = 0 ; i<2 ; i++)
 	{   
	 	
 		for(j = 0 ; j<2 ; j++)
		 {
 			for(k = 0 ; k<2 ; k++)
 		    	{
 			    	printf("Soma das matrizes: %d(I) - %d(J) - %d(K): %d\n", i,j,k,matriz[i][j][k]);	
			    }    
		} 
    }
	
}

void prencherMAtrizes()
{
	int i,j,k;
	 	for(i = 0 ; i<2 ; i++)
 	{
 		for(j = 0 ; j<2 ; j++)
		 {
 			for(k = 0 ; k<2 ; k++)
 			{   
 				printf("Digite o valor da posicao para a matriz 1 %d(I) - %d(J) - %d(K): ", i,j,k);
 				scanf("%d", &mat1[i][j][k]);	
			}
		}
    }
    
    limparTela();
    
    	 	for(i = 0 ; i<2 ; i++)
 	{
 		for(j = 0 ; j<2 ; j++)
		 {
 			for(k = 0 ; k<2 ; k++)
 			{   
 				printf("Digite o valor da posicao para a matriz 2 %d(I) - %d(J) - %d(K): ", i,j,k);
 				scanf("%d", &mat2[i][j][k]);	
			}
		}
    }
    limparTela();
}
void maiorPrimoDaMatriz()
{
	int contador;
	
	preencherMatriz();
	escreverMatriz();
	
	int i,j,k;
	 	
 	for(i = 0 ; i<2 ; i++)
 	{
 		for(j = 0 ; j<2 ; j++)
		 {
 			for(k = 0 ; k<2 ; k++)
 			{   
 			   	if (verificarPrimo(matriz[i][j][k]))
					{	
						if (matriz[i][j][k] > maiorPrimo)
		   				{
							maiorPrimo = matriz[i][j][k];
							
							printf("Elemento %d eh primo e o maior valor agora eh %d\n\n", matriz[i][j][k], maiorPrimo);	
						} 
						else
						{
							printf("Elemento %d eh primo mas o maior continua sendo o valor %d.\n\n", matriz[i][j][k], maiorPrimo);
						}		   				
		
					}	
				else
				{
					printf("Elemento %d nao eh primo e o maior continua sendo o valor %d.\n\n", matriz[i][j][k], maiorPrimo);	
				}			
			}
		}
    }
    
    printf("O maior numero primo da matriz eh: %d\n\n\n", maiorPrimo);
	
		
}
 
 void preencherMatriz()
 { 	
 	printf("Agora voce preenchera a matriz tridimensional.\n\n");
	int i,j,k;
	 	
 	for(i = 0 ; i<2 ; i++)
 	{
 		for(j = 0 ; j<2 ; j++)
		 {
 			for(k = 0 ; k<2 ; k++)
 			{   
 				printf("Digite o valor da posicao %d(I) - %d(J) - %d(K): ", i,j,k);
 				scanf("%d", &matriz[i][j][k]);	
			}
		}
    }
    
    esperarTela();
    limparTela();
}
	
void escreverMatriz()
{   
	int i,j,k;
	
    printf("O resultado da sua matriz eh:\n\n");
 	for(i = 0 ; i<2 ; i++)
 	{   
	 	
 		for(j = 0 ; j<2 ; j++)
		 {
 			for(k = 0 ; k<2 ; k++)
 		    	{
 			    	printf("Indice: %d(I) - %d(J) - %d(K): %d\n", i,j,k,matriz[i][j][k]);	
			    }    
		} 
    }		
    esperarTela();
	limparTela();	
		
}

void subMenuFatorialDeFibonacci()
{
	long int x;
	
	printf("Digite o elemento da serie: ");
	scanf("%d", &x);
	
	limparTela();
	
	x = calcularFatorial(calcularFibonacci(x));
	
		printf("\n\nO resultado da fatorial para a serie de fibonacci escolhida eh: %d\n\n\n\n\n\n\n", x);
	
}

long int calcularFibonacci(long int x)
{
	int i, res;
	int anterior = 0;
	int proximo = 1;
	
	printf("\n==============================\n\n");
	printf("\nCalculo Fibonacci\n");
	
	for(i=1; i<=x-1 ; i++)
	{
		res = anterior + proximo;	
		
		printf("\nElemento %d da serie Fibonacci: %d \n", x, res);
		
		proximo = anterior;
		anterior = res;
			
	}
	
	printf("\n\nO resultado da serie eh: %d\n\n", anterior);
	
	
	return anterior;
	
}

long int calcularFatorial(long int x)
{
	printf("\n==============================\n\n");
	printf("Calculo Fatorial\n\n");
	int i;
	long int fat;
	
	for(i=x; i>1 ; i--)
	{
		printf("%d x %d = ", fat, i-1);
		fat = fat * (i-1);
		printf(" %d .\n\n", fat);
	}
	
	return fat;
		
}

void subMenuCartesiano()
{
	int opcao;
	
	do
	{
   		 printf("Digite:\n\n");
   		 printf("0 - Sair\n");
   		 printf("1 - Gravar dados dos pontos cartesianos.\n");
   		 printf("2 - Ler os dados dos pontos cartesianos.\n");
    
  		scanf("%d", &opcao);
    	 
		 limparTela();
    	 
   		 GerenteDeOpcoesCartesiano(opcao);		
	}while(opcao != SAIR);
	
}

void GerenteDeOpcoesCartesiano(int opcao)
{
	switch(opcao)
	{   
	    case SAIR       :  	printf("Saindo...\n\n");
	    		    			break;		    		    	
		case GRAVARDADOS:   gravarCartesiano();
				    			break;		
		case LERDADOS   :  	lerCartesiano();
				    			break;			    			                
		default         : 	printf("Opcao invalida!\n\n");
	}
	esperarTela();
	limparTela();
}

void gravarCartesiano()
{
	char PONTOX[N], PONTOY[N];
	int i;
	FILE *arq;
	
	printf("Gravando os pontos cartesianos...\n");  
	
	printf("Qual o numero de pontos cartesianos que voce deseja gravar?\n");
	scanf("%d", &TAMCART);
	
	limparTela(); 
	
	arq = fopen(url, "w");
	
	for(i=0; i <= TAMCART-1; i++)
	{	
		  printf("Valor de X no ponto %d: ", i+1); 
  		  scanf("%s", PONTOX);
          printf("Valor de Y no ponto %d: ", i+1); 
          scanf("%s", PONTOY);
          fputs("(", arq);
		  fputs(PONTOX, arq);
		  fputs(",", arq);
          fputs(PONTOY, arq);
          fputs(")", arq);
          fputs("\n", arq);    
		  
		  limparTela();  
	}  
	
	fclose(arq);
		
}

void lerCartesiano()
{
	
  FILE *arq;
  char linha[N];
  int i;
  arq = fopen(url, "r");
  
  printf("\nLeitura dos pontos cartesianos\n\n\n");
  
  	for(i=0; i <= TAMCART-1; i++)
	{	
		  fgets(linha, N, arq);
 		  printf("PONTO %d: %s", i+1, linha);
		 
	}  
	
	fclose(arq);
	esperarTela();
	limparTela();
}

//--------Função para limpar a tela----------//
void limparTela()
{
	system("cls");
}

//--------Função para aguardar o comando do usuário para continuar----------//
void esperarTela()
{
	printf("Aperte uma tecla para continuar...\n");
	getch();
}


    
