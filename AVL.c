#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

// 	Implementação das Funções de List

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 1.a) função que aloca memória para uma lista, inicializando seus campos
//		Entrada: void
//		Saída: ponteiro para uma lista
List *createList()
{
    List *lista = (List *)malloc(sizeof(List));
    
    if (lista) 
    {
        lista->size = 0;
        lista->first = NULL;
    }
    
    return lista;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 1.c) função que aloca memória para um elemento de informação Info, inicializando seus campos
//		Entrada: inteiro conteúdo do elemento de informação
//		Saída: ponteiro para um Info
InfoList *createInfoList(int i)
{
    InfoList *info = (InfoList *) malloc (sizeof(InfoList));
    
    if (info)
    {
       info->value = i; 
    }

    return info;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 1.b) função que aloca memória para um no, inicializando seus campos
//		Entrada: void
//		Saída: ponteiro para uma Node
NodeList *createNodeList()
{
    NodeList *no = (NodeList *) malloc (sizeof(NodeList));
    
    if (no)
    {
        no->next = NULL;
        no->info = NULL;
    }

    return no;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 1.d) função que libera todo o espaço de memória espaço de memória usado por uma lista
//		Entrada: ponteiro para uma lista
//		Saída: void
void freeList(List *lst)
{
    NodeList *ptr, *pptr;

    if (isEmptyList(lst))
    {
        free(lst);
        return;
    } else {
        ptr = lst->first;
        while (ptr != NULL)
        {
            pptr = ptr;
            ptr = ptr->next;
            free(pptr->info);     
            free(pptr);
        }
        free(lst);
    }
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 2.a) Função que verifica se uma list é vazia
//		Entrada: ponteiro para uma lista
//		Saída: bool (TRUE se a lista é vazia, FALSE caso contrário)
int isEmptyList(List * lst)
{
    if (lst==NULL || lst->size==0) {
        return 1;
    } else {
        return 0;
    }
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 3.b) Função que insere um elemento na última posição da lista
//		Entrada: ponteiro para uma lista
//		Saída: bool (TRUE se o elemento foi inserido, FALSE caso contrário
int insertLastList(List *lst, InfoList *inf)
{
    NodeList *ptr, *pptr;

    if (!(ptr=createNodeList()) || !lst) {
        return 0;
    }
    ptr->info = inf;
    if (lst->first == NULL) {
        lst->first = ptr;
    } else {
        pptr = lst->first;
        while (pptr->next != NULL) {
            pptr = pptr->next;
        }
        pptr->next = ptr;
    }
    lst->size++;

    return 1;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 3.c) Função que deleta o elemento da primeira posição da lista
//		Entrada: ponteiro para uma lista
//		Saída: ponteiro para Info com o elemento deletado
InfoList *deleteFirstList(List *lst)
{
	InfoList *inf;
    NodeList *ptr;

    if (isEmptyList(lst)) {
        return NULL;
    }
    inf =lst->first->info;
    ptr = lst->first;
    lst->first = ptr->next;
    free(ptr);
    lst->size--;

    return inf;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//
//
//
List * takeWhileList (List *lst, InfoList *inf)
{
	NodeList *ptr;
	List *auxLst = createList();
	InfoList *tempInfo;
	if (!auxLst) return NULL;

	for (ptr=lst->first; ptr && ptr->info->value != inf->value; ptr=ptr->next)
	{
		tempInfo = createInfoList(ptr->info->value);
		insertLastList(auxLst, tempInfo);
	}
	return auxLst;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//
//
//
List *dropWhileList (List *lst, InfoList *inf)
{
	NodeList *ptr;
	List *auxLst = createList();
	InfoList *tempInfo;
	if (!auxLst) return NULL;

	for (ptr=lst->first; ptr && ptr->info->value != inf->value; ptr=ptr->next);
	if (ptr) {
		for (ptr=ptr->next; ptr; ptr=ptr->next)
		{
			tempInfo = createInfoList(ptr->info->value);
			insertLastList(auxLst, tempInfo);
		}
	}
	return auxLst;
}
//



// 	Implementação das Funções de AVL

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 	createItem: Função que aloca memória para um tipo Info, inicializando seus campos
//		Entrada: Inteiro
//		Saída: Ponteiro para tipo Info
Info *createInfo (int val)
{
	Info *inf = (Info *)malloc(sizeof(Info));

	if (inf) {
		inf->value = val;
	} else {
		printf("{ERRO 852}: Memória não alocada para elemento de informação!\n");
	}

	return inf;
}
//
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
Node *createNodeAVL (Info *inf)
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
Info *rootAVL (AVL *avl)
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
AVL *searchAVL (AVL *avl, Info *inf)
{
	if (isEmptyAVL(avl) || !inf) return NULL;
	if (rootAVL(avl)->value == inf->value) {
		// Encontrei
		return avl;
	} else if (rootAVL(avl)->value > inf->value) {
		// Elemento menor que a raiz atual
		return searchAVL(leftAVL(avl), inf);
	} else {
		// Elemento maior que a raiz atual
		return searchAVL(rightAVL(avl), inf);
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
//	preOrderTraversalAVL: Função que percorre de forma pre-ordem uma AVL
//		Entrada: Ponteiro para AVL
//		Saída: Lista simplesmente encadeada com o percurso pre-ordem
List *preOrderTraversalAVL (AVL *avl)
{
	List *lst;
	InfoList *temp;

	if (isEmptyAVL(avl)) return NULL;
	if ((lst = createList()) == NULL) return NULL;
	if ((temp = createInfoList(avl->inf->value)) == NULL) {
		freeList(lst);
		return NULL;
	}

	insertLastList(lst, temp);
	auxPreOrderTraversalAVL(leftAVL(avl), lst);
	auxPreOrderTraversalAVL(rightAVL(avl), lst);

	return lst;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	auxPreOrderTraversalAVL: Função que auxilia o cálculo do caminho pre-ordem
//		Entrada: Ponteiro para AVL e ponteiro para List
//		Saída: Void
void auxPreOrderTraversalAVL (AVL *avl, List *lst)
{
	InfoList *temp;

	if (isEmptyAVL(avl) || lst == NULL) return;
	if ((temp = createInfoList(rootAVL(avl)->value)) == NULL) return;
	// Visita a raíz
	insertLastList(lst, temp);
	// Visita a esquerda
	auxPreOrderTraversalAVL(leftAVL(avl), lst);
	// Visita a direita
	auxPreOrderTraversalAVL(rightAVL(avl), lst);
	
	return;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	inOrderTraversalAVL: Função que percorre de forma em-ordem uma AVL
//		Entrada: Ponterio para AVL
//		Saída: Ponteiro para lista simplesmente encadeada com o percurso em-ordem
List *inOrderTraversalAVL (AVL *avl)
{
	List *lst;
	InfoList *temp;

	if (isEmptyAVL(avl)) return NULL;
	if ((lst = createList()) == NULL) return NULL;
	if ((temp = createInfoList(avl->inf->value)) == NULL) {
		freeList(lst);
		return NULL;
	}

	auxInOrderTraversalAVL(leftAVL(avl), lst);
	insertLastList(lst, temp);
	auxInOrderTraversalAVL(rightAVL(avl), lst);

	return lst;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	auxInOrderTRaversalAVL: Função que auxilia o cálculo do caminho em-ordem
//		Entrada: Ponteiro para AVL e ponteiro para List
//		Saída: Void
void auxInOrderTraversalAVL (AVL *avl, List *lst)
{
	InfoList *temp;

	if (isEmptyAVL(avl) || lst == NULL) return;
	if ((temp = createInfoList(rootAVL(avl)->value)) == NULL) return;
	// Visita a esquerda
	auxInOrderTraversalAVL(leftAVL(avl), lst);
	// Visita a raíz
	insertLastList(lst, temp);
	// Visita a direita
	auxInOrderTraversalAVL(rightAVL(avl), lst);

	return;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	postOrderTraversalAVL: Função que percorre de forma pos-ordem uma AVL
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para lista simplesmente encadeada com o percurso pos-ordem
List *postOrderTraversalAVL (AVL *avl)
{
	List *lst;
	InfoList *temp;

	if (isEmptyAVL(avl)) return NULL;
	if ((lst = createList()) == NULL) return NULL;
	if ((temp = createInfoList(avl->inf->value)) == NULL) {
		freeList(lst);
		return NULL;
	}

	auxPostOrderTraversalAVL(leftAVL(avl), lst);
	auxPostOrderTraversalAVL(rightAVL(avl), lst);
	insertLastList(lst, temp);

	return lst;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	auxPostOrderTraversalAVL: Função que auxlilia o cálculo do caminho pos-ordem
//		Entrada: Ponteiro para AVL e ponteiro para List
//		Saída: Void
void auxPostOrderTraversalAVL (AVL *avl, List *lst)
{
	InfoList *temp;

	if (isEmptyAVL(avl) || lst == NULL) return;
	if ((temp = createInfoList(rootAVL(avl)->value)) == NULL) return;

	// Visita a esquerda
	auxPostOrderTraversalAVL(leftAVL(avl), lst);
	// Visita a direita
	auxPostOrderTraversalAVL(rightAVL(avl), lst);
	// Visita a raíz
	insertLastList(lst, temp);

	return;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	levelOrderTraversalAVL: Função que percorre de forma por níveis uma AVL
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para lista simplesmente encadeada com o percurso por níveis
List *levelOrderTraversalAVL (AVL *avl)
{
	if (isEmptyAVL(avl)) return NULL;

	AVL *traverse;
	InfoList *temp;
	List *lst = createList();
	Queue *que = createQueue();

	if (lst == NULL || que == NULL) return NULL;

	insertQueue(que, avl);

	while(!isEmptyQueue(que)) {
		traverse = removeQueue(que);
		temp = createInfoList(traverse->inf->value);
		insertLastList(lst, temp);
		if (leftAVL(traverse) != NULL) insertQueue(que, leftAVL(traverse));
		if (rightAVL(traverse) != NULL) insertQueue(que, rightAVL(traverse));
	}
	freeQueue(que);
	return lst;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	treeFromInOrderPreOrderAVL: Função que reconstroi uma AVL a partir de dois caminhos
//		Entrada: Ponteiro para lista com caminho pre-ordem e em-ordem
//		Saída: Ponteiro para AVL
AVL *treeFromInOrderPreOrderAVL (List *preOrder, List *inOrder)
{
	AVL *avl;
	List *esq, *dir;
	Info *root;

	if (isEmptyList(preOrder) || isEmptyList(inOrder)) return NULL;
	root = (Info *)deleteFirstList(preOrder);

	if ((avl = createAVL(root)) == NULL) return NULL;

	esq = takeWhileList(inOrder, (InfoList *)(root));
	dir = dropWhileList(inOrder, (InfoList *)(root));

	avl->left = treeFromInOrderPreOrderAVL(preOrder, esq);
	avl->right = treeFromInOrderPreOrderAVL(preOrder, dir);

	return avl;
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
AVL *insertAVL (AVL *avl, Info *inf)
{
	// Poderia ser implementada em duas partes nas quais uma ia verificar se o elemento já esta na arvore
	// e a outro devidamente iria inserir o elemento.
	if (!inf) return avl;
	if (avl == NULL) {
		AVL *ptr = createNodeAVL(inf);
		if (!ptr) return avl;
		else return ptr;
	}
	if (inf->value < avl->inf->value){
		avl->left = insertAVL(leftAVL(avl), inf);
	} else {
		avl->right = insertAVL(rightAVL(avl), inf);
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
AVL *deleteAVL (AVL *avl, Info *inf)
{
	if (!inf || avl == NULL) {
		return avl;
	} else if (inf->value < rootAVL(avl)->value) {
		// Avança pela esquerda
		avl->left = deleteAVL(leftAVL(avl), inf);
	} else if (inf->value > rootAVL(avl)->value) {
		// Avança pela direita
		avl->right = deleteAVL(rightAVL(avl), inf);
	} else {
		if (leftAVL(avl) == NULL) {
			AVL *temp = avl->right;
			//free(avl->inf);
			free(avl);
			return temp;
		} else if (rightAVL(avl) == NULL) {
			AVL *temp = avl->left;
			//free(avl->inf);
			free(avl);
			return temp;
		}

		AVL *temp = largestElementAVL(leftAVL(avl));
		avl->inf = temp->inf;
		avl->left = deleteAVL(avl->left, temp->inf);
	}

	atualizaBalance(avl);

	return balanceio(avl);
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	printAVL: Função que imprime os elementos da AVL por níveis
//		Entrada: Ponteiro para AVL
//		Saída: Void
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
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	auxPrintAVL: Função que auxilia a imprissão dos elementos da AVL em profundidade
//		Entrada: Ponteiro para AVL
//		Saída: Void
void auxPrintAVL (AVL *avl)
{
	if (isEmptyAVL(avl)) return;

	printf("%d ", rootAVL(avl)->value);
	auxPrintAVL(leftAVL(avl));
	auxPrintAVL(rightAVL(avl));
	return;
}
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
int isOrderedAVL (AVL *avl)
{
	if (isEmptyAVL(avl)) return 1;
	// A raíz deveria ser maior que a esquerda e menor que a direita
	if (!isEmptyAVL(leftAVL(avl)) && (rootAVL(avl)->value < rootAVL(leftAVL(avl))->value)) return 0;
	if (!isEmptyAVL(rightAVL(avl)) && (rootAVL(avl)->value > rootAVL(rightAVL(avl))->value)) return 0;
	return (isOrderedAVL(leftAVL(avl)) && isOrderedAVL(rightAVL(avl)));
}
//

// 	Implementação das Funções de Queue

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	avl
//
//
Queue *createQueue ()
{
	Queue *ptr;
	if (ptr = (Queue *)malloc(sizeof(Queue))) {
		ptr->size = 0;
		ptr->first = ptr->last = NULL;
		return ptr;
	}

	return NULL;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//
//
//
int insertQueue (Queue *queue, AVL *avl)
{
	if (queue == NULL || isEmptyAVL(avl)) return 0;

	NodeQueue *ptr = (NodeQueue *)malloc(sizeof(NodeQueue));

	if (ptr == NULL) return 0;

	ptr->next = NULL;
	ptr->av = avl;

	if (queue->first == NULL) {
		queue->first = queue->last = ptr;
	} else {
		queue->last->next = ptr;
		queue->last = ptr;
	}
	queue->size += 1;
	return 1;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	isEmptyQueue: Função que verifica se uma fila está esta vazia
//		Entrada: Ponteiro para fila
//		Saída: Inteiro (1 = Vazia, 0 = Não vazia)
int isEmptyQueue (Queue *que)
{
	if (que == NULL || que->size == 0 || que->first == NULL) return 1;
	return 0;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	removeQueue: Função que retorna o primeiro elemento da fila
//		Entrada: Ponteiro para fila
//		Saída: Ponteiro para AVL;
AVL *removeQueue (Queue *que)
{
	if (isEmptyQueue(que)) return NULL;

	NodeQueue *ptr = que->first;
	AVL *avl = ptr->av;

	que->first = ptr->next;

	free(ptr);

	return avl;
}
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	freeQueue: Função que libera o espaço ocupado pela fila sem destruir a árvore
//		Entrada: Ponteiro para fila
//		Saída: Void
void freeQueue (Queue *que)
{
	if (que == NULL) return;

	NodeQueue *pptr = que->first;
	NodeQueue *ptr;
	while (pptr != NULL) {
		ptr = pptr;
		pptr = pptr->next;
		free(ptr);
	}
	free(que);

	return;
}
//
