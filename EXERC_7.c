#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>

/*7. Crie um programa em C que preencha um vetor de inteiros de 1000 posi��es com n�meros aleat�rios e implemente o menu de op��es abaixo:
1. Ordena Vetor (Use qualquer m�todo que aprendeu na aula passada)
2. Pesquisa Sequencial (Solicite um numero inteiro e informe o tempo para localiz�-lo)
3. Pesquisa Sentinela (Solicite um numero inteiro e informe o tempo para localiz�-lo)
4. Pesquisa Bin�ria (Solicite um numero inteiro e informe o tempo para localiz�-lo)
5. Pesquisa Interpolada (Solicite um numero inteiro e informe o tempo para localiz�-lo)
6. Sair */

int shellSort(int *vet); //Prototipo da fun��o shell sort.
int pesqSeq(int chave, int *vet, int fim); //Prototipo fun��o pesquisa Sequencial
int pesqSenti(int chave, int *vet, int fim);
int pesqBinRec(int chave, int *vet, int inicio, int fim);
int pesqInter(int chave, int *vet, int inicio, int fim);


int main(){
	clock_t sequencial = 0;
	clock_t sentinela = 0;
	clock_t binaria = 0;
	clock_t interpolacao = 0;
	setlocale(LC_ALL, "portuguese");
	int vet[1000];
	int chave;
	int inicio = 0;
	int fim = 1000;
	int op;	
	
	for(int i = 0 ; i < vet[1000] ; i++) //Loop para pegar n�meros aleat�rios de 0 a 1000.
	vet[i] = rand() % 5000 + 1;

	
	printf("Ol� bem vindo!\n");
	printf("1. Ordena Vetor!\n");
	printf("2. Pesquisa Sequencial (Solicite um numero inteiro e informe o tempo para localiz�-lo)\n");
	printf("3. Pesquisa Sentinela (Solicite um numero inteiro e informe o tempo para localiz�-lo)\n");
	printf("4. Pesquisa Bin�ria (Solicite um numero inteiro e informe o tempo para localiz�-lo)\n");
	printf("5. Pesquisa Interpolada (Solicite um numero inteiro e informe o tempo para localiz�-lo)\n");
	printf("6. Sair\n");
do{
	printf("\nDigite sua op��o: ");
	scanf("%d",&op);
	fflush(stdin);
	switch(op){
		case 1:
			shellSort(vet);
			for(int i = 0 ; i < 1000 ; i++)
			printf("%d,",vet[i]);
			break;
		case 2:
			printf("Digite um numero para busca Sequencial: ");
			scanf("%d",&chave);
			sequencial = clock();
			printf("N�mero %d est� na %d� posi��o!",chave,pesqSeq(chave, vet, fim));	
			sequencial = clock() - sequencial;
			printf("\nTempo de execu��o Busca Sequencial: %lf milissegundos\n\n",(sequencial) /(double)CLOCKS_PER_SEC/1000);
			break;
		case 3:
			printf("Digite um numero para buscar por Pesquisa Sentinela: ");
			scanf("%d",&chave);
			sentinela = clock();
			printf("N�mero %d est� na %d� posi��o!",chave,pesqSenti(chave, vet, fim));
			sentinela = clock() - sentinela;
			printf("\nTempo de execu��o Busca Sentinela: %lf milissegundos\n\n",(sentinela) /(double)CLOCKS_PER_SEC/1000);
			break;
		case 4:
			printf("Digite um n�mero para buscar com Busca Bin�ria: ");
			scanf("%d",&chave);
			binaria = clock();
			printf("N�mero %d est� na %d� pos��o!",chave,pesqBinRec(chave, vet, inicio, fim));
			binaria = clock() - binaria;
			printf("\nTempo de execu��o Busca Bin�ria: %lf milissegundos\n\n",(binaria) /(double)CLOCKS_PER_SEC/1000);
			break;
		case 5:
			printf("Digite um n�mero para buscar com Busca Interpola��o: ");
			scanf("%d",&chave);
			interpolacao = clock();
			printf("N�mero %d est� na %d� posi��o!",chave, pesqInter(chave, vet, inicio, fim));
			interpolacao = clock() - interpolacao;
			printf("\nTempo de execu��o Busca Interpolada: %lf milissegundos\n\n",(interpolacao) /(double)CLOCKS_PER_SEC/1000);
			break;
		case 6:
			return 0;
		default:
			printf("Op��o invalida! Tente novamente: ");
	}
	
		
}while(op != 6);
	
}

	int shellSort(int *vet) //Fun��o para ordenar por Shell Sort.
	{
		printf("\nOpera��o concluida por Shell Sort! ");
		int i, j, troca;
		
		int h = 1; 
		while(h < 1000) //Procura o valor da sequiencia Knuth {1,4,13,40...} para realizar os saltos no vetor.
		{
			h = 3*h+1;	
		}
		 while(h > 0)
		 {
				for(i = h ; i < 1000 ; i++) //Loop que faz as compara��es de cada posi��o.
				{
					troca = vet[i];
					j = i;
					 while(j > h-1 && troca <= vet[j-h]) //Testa as posi��es e faz a troca.
					 {
					 	vet[j] = vet[j-h];
					 	j = j - h;
					 }
				 vet[j] = troca; 
				}
				h = h/3;
			}
	}
	
int pesqSeq(int chave, int *vet, int fim){ // fun��o para pesquisa sequencial.
	for(int i = 0 ; i < fim ; i++){
		if(vet[i] == chave)
			return (i);
	}
	return (-1); //Indice invalido.
}

int pesqSenti(int chave, int *vet, int fim) { //Fun��o pesquisa sequencial sentinela.
	int i = 0; 
	vet[fim] = chave; 
	while (vet[i] != chave) {
		i++; 
	} 
	if( i < fim ) 
		return i; 
	return (-1); // �ndice inv�lido 
} 

int pesqBinRec(int chave, int *vet, int inicio, int fim){ //Fun��o para pesquisa Binaria.
	int meio;
	if(inicio <= fim){
		meio = (inicio + fim)/2;
			if(chave == vet[meio])
				return meio;
			else{
				if(chave < vet[meio])
				return pesqBinRec(chave, vet, inicio, meio - 1);
				else
				return pesqBinRec(chave, vet, meio + 1, fim);
		}
	}
	return -1; //N�o esta encontrado.
}

int pesqInter(int chave, int *vet,int inicio, int fim){ //Fun��o para pesquisa Interpola��o.
	int meio;
	fim = fim - 1;
		while(inicio <= fim){
			meio = inicio +((fim - inicio)*(chave - vet[inicio])) / (vet[fim] - vet[inicio]);
				if(chave < vet[meio]){
					fim = meio - 1;
				}
				else if(chave > vet[meio]){
					inicio = meio + 1;
				}
				else{
					return meio;
				}
		}
	return -1; //Indice n�o encontrado.
}

