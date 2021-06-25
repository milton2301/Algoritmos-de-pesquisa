#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* 5. Implemente uma versão recursiva da função pesquisa binária, teste com n = 5. 

Protótipo da função: int pesqBinRec(int chave, int v[], int ini, int fim); */

int pesqBinRec(int chave, int *vet, int ini, int fim){
	int meio;
	if(ini <= fim){
		meio = (ini + fim)/2;
			if(chave == vet[meio])
				return meio;
			else{
				if(chave < vet[meio])
				return pesqBinRec(chave, vet, ini, meio - 1);
				else
				return pesqBinRec(chave, vet, meio + 1, fim);
		}
	}
	return -1; //Não esta encontrado.
}

int main(){
	setlocale(LC_ALL, "portuguese");
	int vet[10] = {10,34,77,89,91,99,116,133,250,320};
	int ini = 0;
	int fim = 9;
	int chave;

	printf("\n Dentre os numeros = 10 - 34 - 77 - 89 - 91 - 99 - 116 - 133 - 250 - 320!\n Digite 00 pra Sair!\n");
do{
	printf("\nPosição de qual número vc quer saber a posição: ");
	scanf("%d",&chave);
	printf("\nO número %i está na %d º posição\n",chave, pesqBinRec(chave, vet, ini, fim));
}while(chave != 00);

	return 0;
}
