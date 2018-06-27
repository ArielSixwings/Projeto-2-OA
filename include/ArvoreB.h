#ifndef BTREE
#define BTREE

#include <stdio.h>
#include <stdlib.h>

#define ORDER 5
#define bool int
#define true 1
#define false 0

typedef struct nodeArvore_B{
	char **chaves;
	struct nodeArvore_B **filhos;
	int numero_chaves;
	bool folha;
}NodeArvore_B;

typedef struct Arvore_B{
	NodeArvore_B* raiz;
}Arvore_B;

void InicializaNodeArvore(NodeArvore_B* Node,int ordem);

void CriaArvore_B(Arvore_B* aux_Arvore_B,int ordem);

void DeletaNodeArvore(NodeArvore_B* Node);

NodeArvore_B* PesquisaArvoreB(NodeArvore_B* arvore, char* k);

#endif