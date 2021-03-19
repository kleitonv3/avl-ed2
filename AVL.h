#ifndef __AVL_H__
#define __AVL_H__

//	Defini��o da Estrutura de Dados List

typedef struct
{
	int value;
}InfoList;
typedef struct tnode
{
	struct tnode *next;
	InfoList *info;
}NodeList;
typedef struct
{
	int size;
	NodeList *first;
}List;

//	Defini��o das assinaturas das fun��es de List

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 1.a) fun��o que aloca mem�ria para uma lista, inicializando seus campos
//		Entrada: void
//		Sa�da: ponteiro para uma lista
List *createList();
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 1.c) fun��o que aloca mem�ria para um elemento de informa��o Info, inicializando seus campos
//		Entrada: inteiro conte�do do elemento de informa��o
//		Sa�da: ponteiro para um Info
InfoList *createInfoList(int i);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 1.b) fun��o que aloca mem�ria para um no, inicializando seus campos
//		Entrada: void
//		Sa�da: ponteiro para uma Node
NodeList *createNodeList();
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 1.d) fun��o que libera todo o espa�o de mem�ria espa�o de mem�ria usado por uma lista
//		Entrada: ponteiro para uma lista
//		Sa�da: void
void freeList(List *lst);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 2.a) Fun��o que verifica se uma list � vazia
//		Entrada: ponteiro para uma lista
//		Sa�da: bool (TRUE se a lista � vazia, FALSE caso contr�rio)
int isEmptyList(List * lst);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 3.b) Fun��o que insere um elemento na �ltima posi��o da lista
//		Entrada: ponteiro para uma lista
//		Sa�da: bool (TRUE se o elemento foi inserido, FALSE caso contr�rio
int insertLastList(List *lst, InfoList *inf);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 3.c) Fun��o que deleta o elemento da primeira posi��o da lista
//		Entrada: ponteiro para uma lista
//		Sa�da: ponteiro para Info com o elemento deletado
InfoList *deleteFirstList(List *lst);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//
//
//
List *takeWhileList (List *lst, InfoList *inf);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//
//
//
List *dropWhileList (List *lst, InfoList *inf);
//

//	Defini��o da Estrutura de Dados AVL

typedef struct {
	int value;
} Info;
typedef struct avl {
	struct avl *left;
	int balance;
	Info *inf;
	struct avl *right;
} AVL;
typedef AVL Node;

//	Defini��o das assinaturas das fun��es

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 	createItem: Fun��o que aloca mem�ria para um tipo Info, inicializando seus campos
//		Entrada: Inteiro
//		Sa�da: Ponteiro para tipo Info
Info *createInfo (int val);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	createAVL: Fun��o que cria uma AVL
//		Entrada: Void
//		Sa�da: Ponteiro para AVL
AVL *createAVL ();
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	createNodeAVL: Fun��o que cria um no de AVL, inicializando seus campos
//		Entrada: Ponteiro para Info
//		Sa�da: Ponteiro para Node/AVL
Node *createNodeAVL (Info *inf);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	leftAVL: Fun��o que retorna um ponteiro para a sub�rvore esquerda
//		Entrada: Ponteiro para AVL
//		Sa�da: Ponteiro para AVL
AVL *leftAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rightAVL: Fun��o que rotorna um ponteiro para a sub�rvore direita
//		Entrada: Ponteiro para AVL
//		Sa�da: Ponteiro para AVL
AVL *rightAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rootAVL: Fun��o que retorna um ponteiro para o elemento de informa��o da ra�z/no de uma AVL
//		Entrada: Ponteiro para AVL
//		Sa�da: Ponteiro para Info
Info *rootAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	isEmptyAVL: Fun��o que verifica se � uma �rvore vazia
//		Entrada: Ponteiro para AVL
//		Sa�da: Inteiro (1 = Vazia, 0 = N�oVazia)
int isEmptyAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	searchAVL: Fun��o que procura um elemento de informa��o na AVL
//		Entrada: Ponteiro para AVL e ponteiro para Info
//		Sa�da: Ponteiro para AVL (elemento procurado ou NULL quando n�o existir)
AVL *searchAVL (AVL *avl, Info *inf);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	destroyAVL: Fun��o que libera mem�ria alocada para a AVL
//		Entrada: Ponteiro para AVL
//		Sa�da: Void
void destroyAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	heightAVL: Fun��o que calcula a altura da AVL
//		Entrada: Ponteiro para AVL
//		Sa�da: Inteiro (altura)
int heightAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	preOrderTraversalAVL: Fun��o que percorre de forma pre-ordem uma AVL
//		Entrada: Ponteiro para AVL
//		Sa�da: Ponteiro para lista simplesmente encadeada com o percurso pre-ordem
List *preOrderTraversalAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	auxPreOrderTraversalAVL: Fun��o que auxilia o c�lculo do caminho pre-ordem
//		Entrada: Ponteiro para AVL e ponteiro para List
//		Sa�da: Void
void auxPreOrderTraversalAVL (AVL *avl, List *lst);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	inOrderTraversalAVL: Fun��o que percorre de forma em-ordem uma AVL
//		Entrada: Ponterio para AVL
//		Sa�da: Ponteiro para lista simplesmente encadeada com o percurso em-ordem
List *inOrderTraversalAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	auxInOrderTRaversalAVL: Fun��o que auxilia o c�lculo do caminho em-ordem
//		Entrada: Ponteiro para AVL e ponteiro para List
//		Sa�da: Void
void auxInOrderTraversalAVL (AVL *avl, List *lst);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	postOrderTraversalAVL: Fun��o que percorre de forma pos-ordem uma AVL
//		Entrada: Ponteiro para AVL
//		Sa�da: Ponteiro para lista simplesmente encadeada com o percurso pos-ordem
List *postOrderTraversalAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	auxPostOrderTraversalAVL: Fun��o que auxlilia o c�lculo do caminho pos-ordem
//		Entrada: Ponteiro para AVL e ponteiro para List
//		Sa�da: Void
void auxPostOrderTraversalAVL (AVL *avl, List *lst);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	levelOrderTraversalAVL: Fun��o que percorre de forma por n�veis uma AVL
//		Entrada: Ponteiro para AVL
//		Sa�da: Ponteiro para lista simplesmente encadeada com o percurso por n�veis
List *levelOrderTraversalAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	treeFromInOrderPreOrderAVL: Fun��o que reconstroi uma AVL a partir de dois caminhos
//		Entrada: Ponteiro para lista com caminho pre-ordem e em-ordem
//		Sa�da: Ponteiro para AVL
AVL *treeFromInOrderPreOrderAVL (List *preOrder, List *inOrder);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rightRotation: Fun��o que devidamente realiza a rota��o (a antiga raiz se torna o filho 
// 	*direito* da nova raiz)
//		Entrada: Ponteiro para AVL
//		Sa�da: Ponteiro para AVL
AVL *rightRotation (AVL *av1);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	leftRotation: Fun��o que devidamente realiza a rota��o (a antiga raiz se torna o filho 
// 	*esquerdo* da nova raiz)
//		Entrada: Ponteiro para AVL
//		Sa�da: Ponteiro para AVL
AVL *leftRotation (AVL *av1);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	leftLeft: Fun��o que realiza a rota��o LL
//		Entrada: Ponteiro para AVL
//		Sa�da: Ponteiro para AVL
AVL *leftLeft (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	leftRight: Fun��o que realiza a rota��o LR
//		Entrada: Ponteiro para AVL
//		Sa�da: Ponteiro para AVL
AVL *leftRight (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rightLeft: Fun��o que realiza a rota��o RL
//		Entrada: Ponteiro para AVL
//		Sa�da: Ponteiro para AVL
AVL *rightLeft (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rightRight: Fun��o que realiza a rota��o RR
//		Entrada: Ponteiro para AVL
//		Sa�da: Ponteiro para AVL
AVL *rightRight (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	atualizaBalance: Fun��o que atualiza o fator de balan�o de um n�
//		Entrada: Ponteiro para AVL
//		Sa�da: Void
void *atualizaBalance (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	balanceio: Fun��o que determina se e qual rota��o deve ser feita na AVL
//		Entrada: Ponteiro para AVL
//		Sa�da: Ponteiro para AVL
AVL *balanceio (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	insertAVL: Fun��o que insere um novo elemento na AVL
//		Entrada: Ponteiro para AVL e ponteiro para elemento de informa��o
//		Sa�da: Ponteiro para AVL
AVL *insertAVL (AVL *avl, Info *inf);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	largestElementAVL: Fun��o que retorna o ponteiro para o maior elemento da AVL
//		Entrada: Ponteiro para AVL
//		Sa�da: Ponteiro para AVL
AVL *largestElementAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	smallestElementAVL: Fun��o que retorna o ponteiro para o menor elemento da AVL 
//		Entrada: Ponteiro para AVL
//		Sa�da: Ponteiro para AVL
AVL *smallestElementAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	mirrorAVL: Fun��o que espelha uma AVL (inverte todas as sub�rvores)
//		Entrada: Ponteiro para AVL
//		Sa�da: Ponteiro para AVL
AVL *mirrorAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	deleteAVL: Fun��o que deleta um elemento da �rvore, mantendo sua estrutura
//		Entrada: Ponteiro para AVL e ponteiro para elemento de informa��o
//		Sa�da: Ponteiro para �rvore AVL modificada;
AVL *deleteAVL (AVL *avl, Info *inf);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	printAVL: Fun��o que imprime os elementos da AVL em profundidade
//		Entrada: Ponteiro para AVL
//		Sa�da: Void
void printAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	auxPrintAVL: Fun��o que auxilia a impriss�o dos elementos da AVL em profundidade
//		Entrada: Ponteiro para AVL
//		Sa�da: Void
void auxPrintAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	weightAVL: Fun��o que calcula o peso da �rvore (n�mero de n�s)
//		Entrada: Ponteiro para AVL
//		Sa�da: Inteiro representando o peso da �rvore
int weightAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	totalExternalNodes: Fun��o que calcula a quantidade de n�s externos da AVL
//		Entrada: Ponteiro para AVL
//		Sa�da: Inteiro representando a quantidade de n�s externos
int totalExternalNodes (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	totalInternalNodes: Fun��o que calcula a quantidade de n�s internos da AVL
//		Entrada: Ponteiro para AVL
//		Sa�da: Inteiro representando a quantidade de n�s internos
int totalInternalNodes (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	isOrderedAVL: Fun��o que verifica se uma AVL est� ordenada
//		Entrada: Ponteiro para AVL
//		Sa�da: Inteiro (1 = Ordenada, 0 = N�o ordenada)
int isOrderedAVL (AVL *avl);
//

//	Defini��o da Estrutura de Dados Queue

typedef struct tqueue {
	struct tqueue *next;
	AVL *av;
} NodeQueue;
typedef struct {
	int size;
	NodeQueue *first, *last;
} Queue;

//	Defini��o das assinaturas das fun��es de Queue

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	createQueue: Fun��o que cria uma cabe�a de fila inicializando seus campos
//		Entrada: Void
//		Sa�da: Ponteiro para fila
Queue *createQueue ();
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	insertQueue: Fun��o que insere um elemento na fila, atualizando seus campos
//		Entrada: Ponteiro para fila e ponteiro para AVL
//		Sa�da: Inteiro (1 = Inserido com sucesso, 0 = N�o inserido)
int insertQueue (Queue *queue, AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	isEmptyQueue: Fun��o que verifica se uma fila est� esta vazia
//		Entrada: Ponteiro para fila
//		Sa�da: Inteiro (1 = Vazia, 0 = N�o vazia)
int isEmptyQueue (Queue *que);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	removeQueue: Fun��o que retorna o primeiro elemento da fila
//		Entrada: Ponteiro para fila
//		Sa�da: Ponteiro para AVL;
AVL *removeQueue (Queue *que);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	freeQueue: Fun��o que libera o espa�o ocupado pela fila sem destruir a �rvore
//		Entrada: Ponteiro para fila
//		Sa�da: Void
void freeQueue (Queue *que);
//


#endif // __AVL_H__
