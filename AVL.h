#ifndef __AVL_H__
#define __AVL_H__

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

#endif // __AVL_H__
