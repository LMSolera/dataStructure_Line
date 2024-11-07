#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 10

void inserir(int numero);
void inicializar();
int verificarVazia();
int verificarCheia();
void imprimir();
int remover();

typedef struct _fila {
	int vetor[TAM_MAX];
	int final;
} Fila;

Fila f;

void inicializar(){
	f.final = -1;
}

int verificarVazia(){
	if(f.final == -1)
		return 1;
	else return 0;
}

int verificarCheia() {
	if(f.final == TAM_MAX - 1)
		return 1;
	else return 0;
}

void inserir(int numero){
	//verificar se a fila nao estah cheia
	if(!verificarCheia()) {
		//atualiza o final da fila	
		f.final++;
		//insere o numero no vetor no final
		f.vetor[f.final] = numero;
	} else {
		//informa o usuario que a fila estah cheia
		printf("\nA fila estah cheia.");
	}
}

void imprimir(){
	//verificar se a fila nao estah vazia
	if(!verificarVazia()) {
		int i;
		printf("\nOs elementos na fila sao: ");
		//percorrer o vetor de 0 ateh f.final
		for(i = 0; i <= f.final; i++)
			//imprimir o elemento na posicao i
			printf(" %d", f.vetor[i]);
	} else {
		printf("\nA fila estah vazia.");
	}
}

int remover() {
	//verificar se a fila n�o estah vazia
	if(!verificarVazia()) {
		int aux, i;
		//aux ir� guardar o elemento do in�cio da fila
		aux = f.vetor[0];
		//translada os elementos do inicio ao fim -1
		for(i = 0; i <= f.final -1; i++)
			//a posi��o i receber o valor da posi��o i+1
			f.vetor[i] = f.vetor[i+1];
		//atualizar o final da fila
		f.final--;
		return aux;
	} else {
		printf("A fila estah vazia.");
	}
}

void inverterLista () {
    if (!verificarVazia()) {
        if (f.final < 1) {
            printf ("Nao existem elementos o suficiente para realizar a acao.");
        } else {
            int temp, end, i;
            end = f.final;
            for (i = 0; i <= (f.final / 2); i++) {
                temp = f.vetor[end];
                f.vetor[end] = f.vetor[i];
                f.vetor[i] = temp;
                end--;
            }
        }
    } else {
        printf ("A fila estah vazia.");
    }
}

int main(int argc, char *argv[]) {
	int temp;
	int opcao;
	inicializar();

	do {
		//exibir o menu
		printf("\n    MENU");
		printf("\n1. Inicializar");
		printf("\n2. Inserir");
		printf("\n3. Remover");
		printf("\n4. Imprimir");
		printf("\n5. Inverter Fila");
		printf("\n6. Sair");
		printf("\nDigite a opcao desejada: ");
		
		//ler a opcao desejada pelo usuario
		scanf("%d", &opcao);
		
		//processar a funcionalidade
		switch(opcao) {
			case 1:
				inicializar();
				break;
			case 2:
				printf("Digite o numero: ");
				scanf("%d", &temp);
				inserir(temp);
				break;
			case 3:
				temp = remover();
				printf("\nNumero removido: %d", temp);
				break;
			case 4:
				imprimir();
				break;
			case 5:
				inverterLista();
				break;
			case 6:
				printf("Encerrando o programa...");
				break;
			default:
				printf("\nOpcao invalida. Escolha um numero valido de opcao.");
		}
		
	} while(opcao != 6);
}
