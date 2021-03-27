#include <stdio.h>
#include <stdlib.h>
#include "AVL.c"

typedef struct {
	int id;
    int idade;
	float nota;
} Info;

// Assinatura das funções do cliente

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 	createInfo: Funcao que aloca memoria para um tipo Info, inicializando seus campos
//		Entrada: Inteiro, int e float
//		Saida: Ponteiro para tipo Info
Info *createInfo (int val, int place1, float place2);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 	PrimeiroMaiorQueSegundo: Funcao que analisa se o elemento do primeiro parâmetro
//  eh maior que o elemento do segundo parâmetro
//		Entrada: Ponteiro para void
//		Saída: Inteiro (1=True, 0=False)
int PrimeiroMaiorQueSegundo(void *elem1, void *elem2);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 	ImprimeValorPrimario: Funcao que imprime o valor primário
//  do elemento de informacao recebido
//		Entrada: Ponteiro para void
//		Saída: Void
void ImprimeValorPrimario(void *elem1);
//

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
	int op, id, idade;
	float nota;

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
				printf("Elemento a ser adicionado (todos os campos): ");
				scanf("%d %c %d", &id, &idade, &nota);
				inf = createInfo(id, idade, nota);
				if (searchAVL(avl, inf, PrimeiroMaiorQueSegundo) != NULL) {
					printf("Elemento ja existe na arvore!\n\n");
					free(inf);
					break;
				}
				avl = insertAVL(avl, inf, PrimeiroMaiorQueSegundo);
				printf("Elemento adicionado!\n\n");
				break;

			case 2:
				if (isOrderedAVL(avl, PrimeiroMaiorQueSegundo) == 0) {
					printf("Arvore NAO ESTA ordenada, o proposito da funcao pode estar comprometido!\n\n");
				}
				printf("Elemento a ser deletado (chave primaria): ");
				scanf("%d", &id);
				inf = createInfo(id, 0, 0);
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
				if (isEmptyAVL(avl) == 1) {
					printf("A arvore eh vazia!\n\n");
				} else {
					printf("A arvore NAO eh vazia!\n\n");
				}
				break;

			case 5:
				if (isOrderedAVL(avl, PrimeiroMaiorQueSegundo) == 0) {
					printf("Arvore NAO ESTA ordenada, o proposito da funcao pode estar comprometido!\n\n");
				}
				printf("Elemento a ser procurado (chave primaria): ");
				scanf("%d", &id);
				inf = createInfo(id, 0, 0);
				if (searchAVL(avl, inf, PrimeiroMaiorQueSegundo) == NULL) {
					printf("Elemento '%d' NAO encontrado!\n\n", id);
				} else {
					printf("Elemento '%d' encontrado!\n\n", id);
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
				if (isOrderedAVL(avl, PrimeiroMaiorQueSegundo) == 0) {
					printf("Arvore NAO ESTA ordenada, o proposito da funcao pode estar comprometido!\n\n");
				}
				inf = (largestElementAVL(avl))->inf;
				if (inf == NULL) {
					printf("Nao existem elementos na arvore!\n\n");
				} else {
					printf("Maior elemento: '%d'\n\n", inf->id);
				}
				break;

			case 9:
				if (isOrderedAVL(avl, PrimeiroMaiorQueSegundo) == 0) {
					printf("Arvore NAO ESTA ordenada, o proposito da funcao pode estar comprometido!\n\n");
				}
				inf = (smallestElementAVL(avl))->inf;
				if (inf == NULL) {
					printf("Nao existem elementos na arvore!\n\n");
				} else {
					printf("Menor elemento: '%d'\n\n", inf->id);
				}
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
// 	createInfo: Função que aloca memória para um tipo Info, inicializando seus campos
//		Entrada: Inteiro
//		Saída: Ponteiro para tipo Info
Info *createInfo (int val, int place1, float place2)
{
	Info *inf = (Info *)malloc(sizeof(Info));

	if (inf) {
		inf->id = val;
        inf->idade = place1;
        inf->nota = place2;
	} else {
		printf("{ERRO 852}: Memória não alocada para elemento de informação!\n");
	}

	return inf;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 	PrimeiroMaiorQueSegundo: Função que analisa se o elemento do primeiro parâmetro
//  eh maior que o elemento do segundo parâmetro
//		Entrada: Ponteiro para void
//		Saída: Inteiro (1=True, 0=False)
int PrimeiroMaiorQueSegundo(void *elem1, void *elem2) {
    if (((Info *)elem1)->id > ((Info *)elem2)->id) {
        return 1;
    } else {
        return 0;
    }
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 	ImprimeValorPrimario: Função que imprime o valor primário
//  do elemento de informação recebido
//		Entrada: Ponteiro para void
//		Saída: Void
void ImprimeValorPrimario(void *elem1) {
	if (((Info *)elem1) != NULL) {
		printf("%d\n", ((Info *)elem1)->id);
	}
}
