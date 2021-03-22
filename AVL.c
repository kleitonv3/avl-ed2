#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

// 	Implementação das Funções de AVL

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	createAVL: Função que cria uma AVL
//		Entrada: Void
//		Saída: Ponteiro para AVL
AVL *createAVL ()
{
	return NULL;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	createNodeAVL: Função que cria um no de AVL, inicializando seus campos
//		Entrada: Ponteiro para Info
//		Saída: Ponteiro para Node/AVL
Node *createNodeAVL (void *inf)
{
	Node *no = (Node *)malloc(sizeof(Node));

	if (!inf) {
		// Elemento de informação vazio
		printf("{ERRO 453}: Elemento de informação nulo! \n");
		free(no);
		return NULL;
	}	

	if (no) {
		no->inf = inf;
		no->balance = 0;
		no->left = no->right = NULL;
	}

	return no;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	leftAVL: Função que retorna um ponteiro para a subárvore esquerda
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *leftAVL (AVL *avl)
{
	if (!avl) {
		return NULL;
	}

	return avl->left;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rightAVL: Função que rotorna um ponteiro para a subárvore direita
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *rightAVL (AVL *avl)
{
	if (!avl) {
		return NULL;
	}

	return avl->right;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rootAVL: Função que retorna um ponteiro para o elemento de informação da raíz/no de uma AVL
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para Info
void *rootAVL (AVL *avl)
{
	if (!avl) {
		return NULL;
	}

	return avl->inf;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	isEmptyAVL: Função que verifica se é uma árvore vazia
//		Entrada: Ponteiro para AVL
//		Saída: Inteiro (1 = Vazia, 0 = NãoVazia)
int isEmptyAVL (AVL *avl)
{
	if (!avl) return 1;
	return 0;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	searchAVL: Função que procura um elemento de informação na AVL
//		Entrada: Ponteiro para AVL e ponteiro para Info
//		Saída: Ponteiro para AVL (elemento procurado ou NULL quando não existir)
AVL *searchAVL (AVL *avl, void *inf, FuncDoisParam *MaiorQue)
{
	if (isEmptyAVL(avl) || !inf) return NULL;
	if ((*MaiorQue) (avl->inf, inf)) {
        // Elemento menor que a raiz atual
        return searchAVL(leftAVL(avl), inf, MaiorQue);
    } else if ((*MaiorQue) (inf, avl->inf)) {
        // Elemento maior que a raiz atual
        return searchAVL(rightAVL(avl), inf, MaiorQue);
    } else {
        // Encontrei!
        return avl;
    }
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	destroyAVL: Função que libera memória alocada para a AVL
//		Entrada: Ponteiro para AVL
//		Saída: Void
void destroyAVL (AVL *avl)
{
	if (isEmptyAVL(avl)) return;
	destroyAVL(leftAVL(avl));
	destroyAVL(rightAVL(avl));
	free(rootAVL(avl));
	free(avl);
	return;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	heightAVL: Função que calcula a altura da AVL
//		Entrada: Ponteiro para AVL
//		Saída: Inteiro (altura)
int heightAVL (AVL *avl)
{
	int l, r;
	if (isEmptyAVL(avl)) return 0;
	l = 1 + heightAVL(leftAVL(avl));
	r = 1 + heightAVL(rightAVL(avl));

	if (l > r) {
		return l;
	} else {
		return r;
	}
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rightRotation: Função que devidamente realiza a rotação (a antiga raiz se torna o filho 
// 	*direito* da nova raiz)
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *rightRotation (AVL *av1)
{
	// Rotação
	AVL *av2 = av1->left;
	av1->left = av2->right;
	av2->right = av1;
	// Atualizando fatores de balanço
	atualizaBalance(av1);
	atualizaBalance(av2);
	// av2 é a nova raiz
	return av2;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	leftRotation: Função que devidamente realiza a rotação (a antiga raiz se torna o filho 
// 	*esquerdo* da nova raiz)
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *leftRotation (AVL *av1)
{
	// Rotação
	AVL *av2 = av1->right;
	av1->right = av2->left;
	av2->left = av1;
	// Atualizando fatores de balanço
	atualizaBalance(av1);
	atualizaBalance(av2);
	// av2 é a nova raiz
	return av2;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	leftLeft: Função que realiza a rotação LL
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *leftLeft (AVL *avl)
{
	return rightRotation(avl);
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	leftRight: Função que realiza a rotação LR
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *leftRight (AVL *avl)
{
	avl->left = leftRotation(avl->left);
	return rightRotation(avl);
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rightLeft: Função que realiza a rotação RL
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *rightLeft (AVL *avl)
{
	avl->right = rightRotation(avl->right);
	return leftRotation(avl);
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rightRight: Função que realiza a rotação RR
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *rightRight (AVL *avl)
{
	return leftRotation(avl);
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	atualizaBalance: Função que atualiza o fator de balanço de um nó
//		Entrada: Ponteiro para AVL
//		Saída: Void
void *atualizaBalance (AVL *avl)
{
	avl->balance = heightAVL(leftAVL(avl)) - heightAVL(rightAVL(avl));
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	balanceio: Função que determina se e qual rotação deve ser feita na AVL
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *balanceio (AVL *avl)
{
	if (avl->balance == 2) {
		// Arvore pesada para a esquerda
		if (leftAVL(avl)->balance >= 0) {
			return leftLeft(avl);
		} else {
			return leftRight(avl);
		}
	} else if (avl->balance == -2) {
		// Arvore pesada para a direita
		if (rightAVL(avl)->balance <= 0) {
			return rightRight(avl);
		} else {
			return rightLeft(avl);
		}
	}

	// Caso não seja necessário balancear
	return avl;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	insertAVL: Função que insere um novo elemento na AVL
//		Entrada: Ponteiro para AVL e ponteiro para elemento de informação
//		Saída: Ponteiro para AVL
AVL *insertAVL (AVL *avl, void *inf, FuncDoisParam *MaiorQue)
{
	// Poderia ser implementada em duas partes nas quais uma ia verificar se o elemento já esta na arvore
	// e a outro devidamente iria inserir o elemento.
	if (!inf) return avl;
	if (avl == NULL) {
		AVL *ptr = createNodeAVL(inf);
		if (!ptr) return avl;
		else return ptr;
	}
	if ((*MaiorQue) (avl->inf, inf)){
		avl->left = insertAVL(leftAVL(avl), inf, MaiorQue);
	} else {
		avl->right = insertAVL(rightAVL(avl), inf, MaiorQue);
	}
	atualizaBalance(avl);

	return balanceio(avl);
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	largestElementAVL: Função que retorna o ponteiro para o maior elemento da AVL
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *largestElementAVL (AVL *avl)
{
	if (isEmptyAVL(avl)) return NULL;
	if (isEmptyAVL(rightAVL(avl))) {
		return avl;
	} else {
		return largestElementAVL(rightAVL(avl));
	}
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	smallestElementAVL: Função que retorna o ponteiro para o menor elemento da AVL 
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *smallestElementAVL (AVL *avl)
{
	if (isEmptyAVL(avl)) return NULL;
	if (isEmptyAVL(leftAVL(avl))) {
		return avl;
	} else {
		return smallestElementAVL(leftAVL(avl));
	}
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	mirrorAVL: Função que espelha uma AVL (inverte todas as subárvores)
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *mirrorAVL (AVL *avl)
{
	AVL *aux1, *aux2;

	if (isEmptyAVL(avl)) return NULL;
	
	aux1 = mirrorAVL(rightAVL(avl));
	aux2 = mirrorAVL(leftAVL(avl));

	avl->left = aux1;
	avl->right = aux2;

	return avl;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	deleteAVL: Função que deleta um elemento da árvore, mantendo sua estrutura
//		Entrada: Ponteiro para AVL e ponteiro para elemento de informação
//		Saída: Ponteiro para árvore AVL modificada;
AVL *deleteAVL (AVL *avl, void *inf, FuncDoisParam *MaiorQue)
{
	if (!inf || avl == NULL) {
		return avl;
	} else if ((*MaiorQue) (avl->inf, inf)) {
		// Avança pela esquerda
		avl->left = deleteAVL(leftAVL(avl), inf, MaiorQue);
	} else if ((*MaiorQue) (inf, avl->inf)) {
		// Avança pela direita
		avl->right = deleteAVL(rightAVL(avl), inf, MaiorQue);
	} else {
		if (leftAVL(avl) == NULL) {
			AVL *temp = avl->right;
			free(avl->inf);
			free(avl);
			return temp;
		} else if (rightAVL(avl) == NULL) {
			AVL *temp = avl->left;
			free(avl->inf);
			free(avl);
			return temp;
		}

		AVL *temp = largestElementAVL(leftAVL(avl));
		avl->inf = temp->inf;
		avl->left = deleteAVL(avl->left, temp->inf, MaiorQue);
	}

	atualizaBalance(avl);

	return balanceio(avl);
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	printAVL: Função que imprime os elementos da AVL por níveis
//		Entrada: Ponteiro para AVL
//		Saída: Void
/*
void printAVL (AVL *avl)
{
	if (isEmptyAVL(avl)) return;

	// Visita a raíz
	printf("%d ", rootAVL(avl)->value);
	// Visita a esquerda
	auxPrintAVL(leftAVL(avl));
	// Visita a direita
	auxPrintAVL(rightAVL(avl));
	printf("\n");
}
*/
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	auxPrintAVL: Função que auxilia a imprissão dos elementos da AVL em profundidade
//		Entrada: Ponteiro para AVL
//		Saída: Void
/*
void auxPrintAVL (AVL *avl)
{
	if (isEmptyAVL(avl)) return;

	printf("%d ", rootAVL(avl)->value);
	auxPrintAVL(leftAVL(avl));
	auxPrintAVL(rightAVL(avl));
	return;
}
*/
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	weightAVL: Função que calcula o peso da árvore (número de nós)
//		Entrada: Ponteiro para AVL
//		Saída: Inteiro representando o peso da árvore
int weightAVL (AVL *avl)
{
	if (isEmptyAVL(avl)) return 0;
	else return (1 + weightAVL(leftAVL(avl)) + weightAVL(rightAVL(avl)));
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	totalExternalNodes: Função que calcula a quantidade de nós externos da AVL
//		Entrada: Ponteiro para AVL
//		Saída: Inteiro representando a quantidade de nós externos
int totalExternalNodes (AVL *avl)
{
	if (isEmptyAVL(avl)) return 0;
	if (leftAVL(avl) == NULL && rightAVL(avl) == NULL) return 1;
	return (totalExternalNodes(leftAVL(avl)) + totalExternalNodes(rightAVL(avl)));
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	totalInternalNodes: Função que calcula a quantidade de nós internos da AVL
//		Entrada: Ponteiro para AVL
//		Saída: Inteiro representando a quantidade de nós internos
int totalInternalNodes (AVL *avl)
{
	if (isEmptyAVL(avl)) return 0;
	if (leftAVL(avl) != NULL || rightAVL(avl) != NULL) {
		return (1 + totalInternalNodes(leftAVL(avl)) + totalInternalNodes(rightAVL(avl)));
	} else {
		return 0;
	}
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	isOrderedAVL: Função que verifica se uma AVL está ordenada
//		Entrada: Ponteiro para AVL
//		Saída: Inteiro (1 = Ordenada, 0 = Não ordenada)
int isOrderedAVL (AVL *avl, FuncDoisParam *MaiorQue)
{
	if (isEmptyAVL(avl)) return 1;
	// A raíz deveria ser maior que a esquerda e menor que a direita
	if (!isEmptyAVL(leftAVL(avl)) && ((*MaiorQue) (leftAVL(avl)->inf, avl->inf))) return 0;
	if (!isEmptyAVL(rightAVL(avl)) && ((*MaiorQue) (avl->inf, rightAVL(avl)->inf))) return 0;
	return (isOrderedAVL(leftAVL(avl), MaiorQue) && isOrderedAVL(rightAVL(avl), MaiorQue));
}
//
