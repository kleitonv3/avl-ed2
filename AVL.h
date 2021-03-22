#ifndef __AVL_H__
#define __AVL_H__

//	Definicao da Estrutura de Dados AVL

typedef struct avl {
	struct avl *left;
	int balance;
	void *inf;
	struct avl *right;
} AVL;
typedef AVL Node;

typedef int FuncDoisParam (void *x, void *y);

//	Definicao das assinaturas das funcoes

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	createAVL: Funcao que cria uma AVL
//		Entrada: Void
//		Saida: Ponteiro para AVL
AVL *createAVL ();
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	createNodeAVL: Funcao que cria um no de AVL, inicializando seus campos
//		Entrada: Ponteiro para Info
//		Saida: Ponteiro para Node/AVL
Node *createNodeAVL (void *inf);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	leftAVL: Funcao que retorna um ponteiro para a subarvore esquerda
//		Entrada: Ponteiro para AVL
//		Saida: Ponteiro para AVL
AVL *leftAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rightAVL: Funcao que rotorna um ponteiro para a subarvore direita
//		Entrada: Ponteiro para AVL
//		Saida: Ponteiro para AVL
AVL *rightAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rootAVL: Funcao que retorna um ponteiro para o elemento de informacao da raiz/no de uma AVL
//		Entrada: Ponteiro para AVL
//		Saida: Ponteiro para Info
void *rootAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	isEmptyAVL: Funcao que verifica se e uma arvore vazia
//		Entrada: Ponteiro para AVL
//		Saida: Inteiro (1 = Vazia, 0 = NaoVazia)
int isEmptyAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	searchAVL: Funcao que procura um elemento de informacao na AVL
//		Entrada: Ponteiro para AVL e ponteiro para Info
//		Saida: Ponteiro para AVL (elemento procurado ou NULL quando nao existir)
AVL *searchAVL (AVL *avl, void *inf, FuncDoisParam *MaiorQue);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	destroyAVL: Funcao que libera memoria alocada para a AVL
//		Entrada: Ponteiro para AVL
//		Saida: Void
void destroyAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	heightAVL: Funcao que calcula a altura da AVL
//		Entrada: Ponteiro para AVL
//		Saida: Inteiro (altura)
int heightAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rightRotation: Funcao que devidamente realiza a rotacao (a antiga raiz se torna o filho 
// 	*direito* da nova raiz)
//		Entrada: Ponteiro para AVL
//		Saida: Ponteiro para AVL
AVL *rightRotation (AVL *av1);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	leftRotation: Funcao que devidamente realiza a rotacao (a antiga raiz se torna o filho 
// 	*esquerdo* da nova raiz)
//		Entrada: Ponteiro para AVL
//		Saida: Ponteiro para AVL
AVL *leftRotation (AVL *av1);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	leftLeft: Funcao que realiza a rotacao LL
//		Entrada: Ponteiro para AVL
//		Saida: Ponteiro para AVL
AVL *leftLeft (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	leftRight: Funcao que realiza a rotacao LR
//		Entrada: Ponteiro para AVL
//		Saida: Ponteiro para AVL
AVL *leftRight (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rightLeft: Funcao que realiza a rotacao RL
//		Entrada: Ponteiro para AVL
//		Saida: Ponteiro para AVL
AVL *rightLeft (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	rightRight: Funcao que realiza a rotacao RR
//		Entrada: Ponteiro para AVL
//		Saida: Ponteiro para AVL
AVL *rightRight (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	atualizaBalance: Funcao que atualiza o fator de balanco de um no
//		Entrada: Ponteiro para AVL
//		Saida: Void
void *atualizaBalance (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	balanceio: Funcao que determina se e qual rotacao deve ser feita na AVL
//		Entrada: Ponteiro para AVL
//		Saida: Ponteiro para AVL
AVL *balanceio (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	insertAVL: Funcao que insere um novo elemento na AVL
//		Entrada: Ponteiro para AVL e ponteiro para elemento de informacao
//		Saida: Ponteiro para AVL
AVL *insertAVL (AVL *avl, void *inf, FuncDoisParam *MaiorQue);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	largestElementAVL: Funcao que retorna o ponteiro para o maior elemento da AVL
//		Entrada: Ponteiro para AVL
//		Saida: Ponteiro para AVL
AVL *largestElementAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	smallestElementAVL: Funcao que retorna o ponteiro para o menor elemento da AVL 
//		Entrada: Ponteiro para AVL
//		Saida: Ponteiro para AVL
AVL *smallestElementAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	mirrorAVL: Funcao que espelha uma AVL (inverte todas as subarvores)
//		Entrada: Ponteiro para AVL
//		Saida: Ponteiro para AVL
AVL *mirrorAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	deleteAVL: Funcao que deleta um elemento da arvore, mantendo sua estrutura
//		Entrada: Ponteiro para AVL e ponteiro para elemento de informacao
//		Saida: Ponteiro para arvore AVL modificada;
AVL *deleteAVL (AVL *avl, void *inf, FuncDoisParam *MaiorQue);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	printAVL: Funcao que imprime os elementos da AVL em profundidade
//		Entrada: Ponteiro para AVL
//		Saida: Void
void printAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	auxPrintAVL: Funcao que auxilia a imprissao dos elementos da AVL em profundidade
//		Entrada: Ponteiro para AVL
//		Saida: Void
void auxPrintAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	weightAVL: Funcao que calcula o peso da arvore (numero de nos)
//		Entrada: Ponteiro para AVL
//		Saida: Inteiro representando o peso da arvore
int weightAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	totalExternalNodes: Funcao que calcula a quantidade de nos externos da AVL
//		Entrada: Ponteiro para AVL
//		Saida: Inteiro representando a quantidade de nos externos
int totalExternalNodes (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	totalInternalNodes: Funcao que calcula a quantidade de nos internos da AVL
//		Entrada: Ponteiro para AVL
//		Saida: Inteiro representando a quantidade de nos internos
int totalInternalNodes (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	isOrderedAVL: Funcao que verifica se uma AVL esta ordenada
//		Entrada: Ponteiro para AVL
//		Saida: Inteiro (1 = Ordenada, 0 = Nao ordenada)
int isOrderedAVL (AVL *avl, FuncDoisParam *MaiorQue);
//

#endif // __AVL_H__
