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

typedef void FuncUmParam (void *x);

//	Definicao das assinaturas das funcoes

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	createAVL: Funcao que cria uma AVL
//		Entrada: Void
//		Saida: Ponteiro para AVL
AVL *createAVL ();
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	createNodeAVL: Função que cria um no de AVL, inicializando seus campos
//		Entrada: Ponteiro para Void
//		Saída: Ponteiro para Node/AVL
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
//	isEmptyAVL: Funcao que verifica se e uma arvore vazia
//		Entrada: Ponteiro para AVL
//		Saida: Inteiro (1 = Vazia, 0 = NaoVazia)
int isEmptyAVL (AVL *avl);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	searchAVL: Função que procura um elemento de informação na AVL
//		Entrada: Ponteiro para AVL, ponteiro para Void e Ponteiro para Função de 2 param.
//		Saída: Ponteiro para AVL (elemento procurado ou NULL quando não existir)
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
//	rightRotation: Função que devidamente realiza a rotação (a antiga raiz se torna o filho 
// 	direito da nova raiz)
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *rightRotation (AVL *av1);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	leftRotation: Função que devidamente realiza a rotação (a antiga raiz se torna o filho 
// 	esquerdo da nova raiz)
//		Entrada: Ponteiro para AVL
//		Saída: Ponteiro para AVL
AVL *leftRotation (AVL *av1);
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
//	insertAVL: Função que insere um novo elemento na AVL
//		Entrada: Ponteiro para AVL, ponteiro para void e ponteiro para Funcao de 2 Param
//		Saída: Ponteiro para AVL
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
//	deleteAVL: Função que deleta um elemento da árvore, mantendo sua estrutura
//		Entrada: Ponteiro para AVL, ponteiro para void e ponteiro para Funcao de 2 Param
//		Saída: Ponteiro para AVL
AVL *deleteAVL (AVL *avl, void *inf, FuncDoisParam *MaiorQue);
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//	printAVL: Função que imprime os elementos da AVL por níveis
//		Entrada: Ponteiro para AVL, inteiro, e Funcao de 1 Param 
//		Saída: Void
void printAVL (AVL *avl, int level, FuncUmParam *ImprimeVal);
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
//	isOrderedAVL: Função que verifica se uma AVL está ordenada
//		Entrada: Ponteiro para AVL e ponteiro para Funcao de 2 Param
//		Saída: Inteiro (1 = Ordenada, 0 = Não ordenada)
int isOrderedAVL (AVL *avl, FuncDoisParam *MaiorQue);
//

#endif // __AVL_H__
