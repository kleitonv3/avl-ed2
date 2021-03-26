#include <stdio.h>
#include <stdlib.h>
#include "AVL.c"

typedef struct {
	int value;
    int placeholder1;
    int placeholder2;
} Info;

// Assinatura das funções do cliente

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 	createItem: Funcao que aloca memoria para um tipo Info, inicializando seus campos
//		Entrada: Inteiro
//		Saida: Ponteiro para tipo Info
Info *createInfo (int val, int place1, int place2);
//

int PrimeiroMaiorQueSegundo(void *elem1, void *elem2);

void ImprimeValorPrimario(void *elem1);

void menu () 
{
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("[0]  - Sair\n");
	printf("[1]  - Adicionar elemento\n");
	printf("[2]  - Deletar elemento\n");
	printf("[3]  - Imprimir arvore\n");
	printf("[4]  - Verificar se a arvore eh vazia\n");
	printf("[5]  - Buscar um elemento\n");
	printf("[6]  - Altura da arvore\n");
	printf("[7]  - Peso da arvore\n");
	printf("[8]  - Maior elemento\n");
	printf("[9]  - Menor elemento\n");
	printf("[10] - Espelhar arvore\n");
	printf("[11] - Nos internos\n");
	printf("[12] - Nos externos\n");
	printf("[13] - Verificar se esta ordenada\n");
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

int main ()
{
	AVL *avl = createAVL();
	Info *inf;
	int op, num, pl1, pl2;

	do
	{
		menu();
		printf("Sua escolha: ");
		scanf("%d", &op);
		printf("\n");
		switch (op)
		{
			case 0:
				printf("Saindo...\n");
				destroyAVL(avl);
				exit(0);

			case 1:
				if (isOrderedAVL(avl, PrimeiroMaiorQueSegundo) == 0) {
					printf("Arvore NAO ESTA ordenada, o proposito da funcao pode estar comprometido!\n\n");
				}
				printf("Elemento a ser adicionado: ");
				scanf("%d %d %d", &num, &pl1, &pl2);
				inf = createInfo(num, pl1, pl2);
				avl = insertAVL(avl, inf, PrimeiroMaiorQueSegundo);
				printf("Elemento adicionado!\n\n");
				break;

			case 2:
				if (isOrderedAVL(avl, PrimeiroMaiorQueSegundo) == 0) {
					printf("Arvore NAO ESTA ordenada, o proposito da funcao pode estar comprometido!\n\n");
				}
				printf("Elemento a ser deletado: ");
				scanf("%d %d %d", &num, &pl1, &pl2);
				inf = createInfo(num, pl1, pl2);
				if (searchAVL(avl, inf, PrimeiroMaiorQueSegundo) == NULL) {
					printf("Elemento nao existe na arvore!\n\n");
					free(inf);
					break;
				}
				avl = deleteAVL(avl, inf, PrimeiroMaiorQueSegundo);
				printf("Elemento deletado!\n\n");
				break;

			case 3:
				printf("Arvore em profundidade: \n\n");
				printAVL(avl, 0, ImprimeValorPrimario);
				printf("\n");
				break;

			case 4:
				/*
				if (isEmptyAVL(avl) == 1) {
					printf("A lista eh vazia!\n\n");
				} else {
					printf("A lista NAO eh vazia!\n\n");
				}
				*/
				break;

			case 5:
				if (isOrderedAVL(avl, PrimeiroMaiorQueSegundo) == 0) {
					printf("Arvore NAO ESTA ordenada, o proposito da funcao pode estar comprometido!\n\n");
				}
				printf("Elemento a ser procurado: ");
				scanf("%d %d %d", &num, &pl1, &pl2);
				inf = createInfo(num, pl1, pl2);
				if (searchAVL(avl, inf, PrimeiroMaiorQueSegundo) == NULL) {
					printf("Elemento '%d' NAO encontrado!\n\n", num);
				} else {
					printf("Elemento '%d' encontrado!\n\n", num);
				}
				free(inf);
				break;

			case 6:
				printf("Altura da arvore: %d\n\n", heightAVL(avl));
				break;

			case 7:
				printf("Peso da arvore: %d\n\n", weightAVL(avl));
				break;

			case 8:
				/*
				if (isOrderedAVL(avl) == 0) {
					printf("Arvore NAO ESTA ordenada, o proposito da funcao pode estar comprometido!\n\n");
				}
				inf = rootAVL(largestElementAVL(avl));
				if (inf == NULL) {
					printf("Nao existem elementos na arvore!\n\n");
				} else {
					printf("Maior elemento: '%d'\n\n", inf->value);
				}
				*/
				break;

			case 9:
				/*
				if (isOrderedAVL(avl) == 0) {
					printf("Arvore NAO ESTA ordenada, o proposito da funcao pode estar comprometido!\n\n");
				}
				inf = rootAVL(smallestElementAVL(avl));
				if (inf == NULL) {
					printf("Nao existem elementos na arvore!\n\n");
				} else {
					printf("Menor elemento: '%d'\n\n", inf->value);
				}
				*/
				break;

			case 10:
				avl = mirrorAVL(avl);
				printf("Arvore espelhada com sucesso!\n\n");
				break;

			case 11:
				printf("Nos internos: %d\n\n", totalInternalNodes(avl));
				break;

			case 12:
				printf("Nos externos: %d\n\n", totalExternalNodes(avl));
				break;

			case 13:
				if (isOrderedAVL(avl, PrimeiroMaiorQueSegundo) == 1) {
					printf("A arvore ESTA ordenada!\n\n");
				} else {
					printf("A arvore NAO ESTA ordenada!\n\n");
				}
				break;

			default:
				printf("Escolha nao reconhecida! Tente novamente.\n\n");
				break;
		}
	} while(1);
	
	return 0;
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 	createItem: Função que aloca memória para um tipo Info, inicializando seus campos
//		Entrada: Inteiro
//		Saída: Ponteiro para tipo Info
Info *createInfo (int val, int place1, int place2)
{
	Info *inf = (Info *)malloc(sizeof(Info));

	if (inf) {
		inf->value = val;
        inf->placeholder1 = place1;
        inf->placeholder2 = place2;
	} else {
		printf("{ERRO 852}: Memória não alocada para elemento de informação!\n");
	}

	return inf;
}
//
int PrimeiroMaiorQueSegundo(void *elem1, void *elem2) {
    if (((Info *)elem1)->value > ((Info *)elem2)->value) {
        return 1;
    } else {
        return 0;
    }
}
//
void ImprimeValorPrimario(void *elem1) {
	if (((Info *)elem1) != NULL) {
		printf("%d\n", ((Info *)elem1)->value);
	}
}