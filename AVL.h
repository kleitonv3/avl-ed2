#ifndef __AVL_H__
#define __AVL_H__

//	Definição da Estrutura de Dados List

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

//	Definição das assinaturas das funções de List

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 1.a) função que aloca memória para uma lista, inicializando seus campos
//		Entrada: void
//		Saída: ponteiro para uma lista
List *createList();
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 1.c) função que aloca memória para um elemento de informação Info, inicializando seus campos
//		Entrada: inteiro conteúdo do elemento de informação
//		Saída: ponteiro para um Info
InfoList *createInfoList(int i);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 1.b) função que aloca memória para um no, inicializando seus campos
//		Entrada: void
//		Saída: ponteiro para uma Node
NodeList *createNodeList();
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 1.d) função que libera todo o espaço de memória espaço de memória usado por uma lista
//		Entrada: ponteiro para uma lista
//		Saída: void
void freeList(List *lst);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 2.a) Função que verifica se uma list é vazia
//		Entrada: ponteiro para uma lista
//		Saída: bool (TRUE se a lista é vazia, FALSE caso contrário)
int isEmptyList(List * lst);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 3.b) Função que insere um elemento na última posição da lista
//		Entrada: ponteiro para uma lista
//		Saída: bool (TRUE se o elemento foi inserido, FALSE caso contrário
int insertLastList(List *lst, InfoList *inf);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 3.c) Função que deleta o elemento da primeira posição da lista
//		Entrada: ponteiro para uma lista
//		Saída: ponteiro para Info com o elemento deletado
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

//	Definição da Estrutura de Dados AVL

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

//	Definição das assinaturas das funções

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// 	createItem: Função que aloca memória para um tipo Info, inicializando seus campos
//		Entrada: Inteiro
//		Saída: Ponteiro para tipo Info
Info *createInfo (int val);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	createAVL: Função que cria uma AVL
//		Entrada: Void
//		Saída: Ponteiro para AVL
AVL *createAVL ();
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	createNodeAVL: Função que cria um no de AVL, inicializando seus campos
//		Entrada: Ponteiro para Info
//		Saída: Ponteiro para Node/AVL
Node *createNodeAVL (Info *inf);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	leftAVL: Função que retorna um ponteiro para a subárvore esquerda
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *leftAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rightAVL: Função que rotorna um ponteiro para a subárvore direita
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *rightAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rootAVL: Função que retorna um ponteiro para o elemento de informação da raíz/no de uma AVL
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para Info
Info *rootAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	isEmptyAVL: Função que verifica se é uma árvore vazia
//		Entrada: Ponteiro para AVL
//		Saída: Inteiro (1 = Vazia, 0 = NãoVazia)
int isEmptyAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	searchAVL: Função que procura um elemento de informação na AVL
//		Entrada: Ponteiro para AVL e ponteiro para Info
//		Saída: Ponteiro para AVL (elemento procurado ou NULL quando não existir)
AVL *searchAVL (AVL *avl, Info *inf);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	destroyAVL: Função que libera memória alocada para a AVL
//		Entrada: Ponteiro para AVL
//		Saída: Void
void destroyAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	heightAVL: Função que calcula a altura da AVL
//		Entrada: Ponteiro para AVL
//		Saída: Inteiro (altura)
int heightAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	preOrderTraversalAVL: Função que percorre de forma pre-ordem uma AVL
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para lista simplesmente encadeada com o percurso pre-ordem
List *preOrderTraversalAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	auxPreOrderTraversalAVL: Função que auxilia o cálculo do caminho pre-ordem
//		Entrada: Ponteiro para AVL e ponteiro para List
//		Saída: Void
void auxPreOrderTraversalAVL (AVL *avl, List *lst);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	inOrderTraversalAVL: Função que percorre de forma em-ordem uma AVL
//		Entrada: Ponterio para AVL
//		Saída: Ponteiro para lista simplesmente encadeada com o percurso em-ordem
List *inOrderTraversalAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	auxInOrderTRaversalAVL: Função que auxilia o cálculo do caminho em-ordem
//		Entrada: Ponteiro para AVL e ponteiro para List
//		Saída: Void
void auxInOrderTraversalAVL (AVL *avl, List *lst);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	postOrderTraversalAVL: Função que percorre de forma pos-ordem uma AVL
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para lista simplesmente encadeada com o percurso pos-ordem
List *postOrderTraversalAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	auxPostOrderTraversalAVL: Função que auxlilia o cálculo do caminho pos-ordem
//		Entrada: Ponteiro para AVL e ponteiro para List
//		Saída: Void
void auxPostOrderTraversalAVL (AVL *avl, List *lst);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	levelOrderTraversalAVL: Função que percorre de forma por níveis uma AVL
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para lista simplesmente encadeada com o percurso por níveis
List *levelOrderTraversalAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	treeFromInOrderPreOrderAVL: Função que reconstroi uma AVL a partir de dois caminhos
//		Entrada: Ponteiro para lista com caminho pre-ordem e em-ordem
//		Saída: Ponteiro para AVL
AVL *treeFromInOrderPreOrderAVL (List *preOrder, List *inOrder);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rightRotation: Função que devidamente realiza a rotação (a antiga raiz se torna o filho 
// 	*direito* da nova raiz)
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *rightRotation (AVL *av1);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	leftRotation: Função que devidamente realiza a rotação (a antiga raiz se torna o filho 
// 	*esquerdo* da nova raiz)
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *leftRotation (AVL *av1);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	leftLeft: Função que realiza a rotação LL
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *leftLeft (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	leftRight: Função que realiza a rotação LR
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *leftRight (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rightLeft: Função que realiza a rotação RL
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *rightLeft (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rightRight: Função que realiza a rotação RR
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *rightRight (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	atualizaBalance: Função que atualiza o fator de balanço de um nó
//		Entrada: Ponteiro para AVL
//		Saída: Void
void *atualizaBalance (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	balanceio: Função que determina se e qual rotação deve ser feita na AVL
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *balanceio (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	insertAVL: Função que insere um novo elemento na AVL
//		Entrada: Ponteiro para AVL e ponteiro para elemento de informação
//		Saída: Ponteiro para AVL
AVL *insertAVL (AVL *avl, Info *inf);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	largestElementAVL: Função que retorna o ponteiro para o maior elemento da AVL
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *largestElementAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	smallestElementAVL: Função que retorna o ponteiro para o menor elemento da AVL 
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *smallestElementAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	mirrorAVL: Função que espelha uma AVL (inverte todas as subárvores)
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *mirrorAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	deleteAVL: Função que deleta um elemento da árvore, mantendo sua estrutura
//		Entrada: Ponteiro para AVL e ponteiro para elemento de informação
//		Saída: Ponteiro para árvore AVL modificada;
AVL *deleteAVL (AVL *avl, Info *inf);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	printAVL: Função que imprime os elementos da AVL em profundidade
//		Entrada: Ponteiro para AVL
//		Saída: Void
void printAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	auxPrintAVL: Função que auxilia a imprissão dos elementos da AVL em profundidade
//		Entrada: Ponteiro para AVL
//		Saída: Void
void auxPrintAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	weightAVL: Função que calcula o peso da árvore (número de nós)
//		Entrada: Ponteiro para AVL
//		Saída: Inteiro representando o peso da árvore
int weightAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	totalExternalNodes: Função que calcula a quantidade de nós externos da AVL
//		Entrada: Ponteiro para AVL
//		Saída: Inteiro representando a quantidade de nós externos
int totalExternalNodes (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	totalInternalNodes: Função que calcula a quantidade de nós internos da AVL
//		Entrada: Ponteiro para AVL
//		Saída: Inteiro representando a quantidade de nós internos
int totalInternalNodes (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	isOrderedAVL: Função que verifica se uma AVL está ordenada
//		Entrada: Ponteiro para AVL
//		Saída: Inteiro (1 = Ordenada, 0 = Não ordenada)
int isOrderedAVL (AVL *avl);
//

//	Definição da Estrutura de Dados Queue

typedef struct tqueue {
	struct tqueue *next;
	AVL *av;
} NodeQueue;
typedef struct {
	int size;
	NodeQueue *first, *last;
} Queue;

//	Definição das assinaturas das funções de Queue

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	createQueue: Função que cria uma cabeça de fila inicializando seus campos
//		Entrada: Void
//		Saída: Ponteiro para fila
Queue *createQueue ();
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	insertQueue: Função que insere um elemento na fila, atualizando seus campos
//		Entrada: Ponteiro para fila e ponteiro para AVL
//		Saída: Inteiro (1 = Inserido com sucesso, 0 = Não inserido)
int insertQueue (Queue *queue, AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	isEmptyQueue: Função que verifica se uma fila está esta vazia
//		Entrada: Ponteiro para fila
//		Saída: Inteiro (1 = Vazia, 0 = Não vazia)
int isEmptyQueue (Queue *que);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	removeQueue: Função que retorna o primeiro elemento da fila
//		Entrada: Ponteiro para fila
//		Saída: Ponteiro para AVL;
AVL *removeQueue (Queue *que);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	freeQueue: Função que libera o espaço ocupado pela fila sem destruir a árvore
//		Entrada: Ponteiro para fila
//		Saída: Void
void freeQueue (Queue *que);
//


#endif // __AVL_H__
