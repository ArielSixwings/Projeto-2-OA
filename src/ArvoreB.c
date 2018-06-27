#include <string.h>
#include "ArvoreB.h"

void InicializaNodeArvore(NodeArvore_B* Node,int ordem){
	int i;
	Node->numero_chaves = 0;
	Node->folha = true;
	Node->chaves = (char**)malloc((ordem-1)*sizeof(char*));
	for(i = 0; i < (ordem - 1); i++){
		Node->chaves[i] = (char*) malloc(8*sizeof(char));
	} 
	Node->filhos = (NodeArvore_B**)malloc(ordem*sizeof(NodeArvore_B*));
	for(i = 0; i < ordem; i++){
		Node->filhos[i] = (NodeArvore_B*) malloc(ordem*sizeof(NodeArvore_B));
	}
}

void CriaArvore_B(Arvore_B* aux_Arvore_B,int ordem){
	NodeArvore_B* aux_Node = (NodeArvore_B*)malloc(sizeof(NodeArvore_B));
	InicializaNodeArvore(aux_Node,ordem);
	
	/*Escrever em disco aux_Node*/

	aux_Arvore_B->raiz = aux_Node;
}

void DeletaNodeArvore(NodeArvore_B* Node, int ordem){
	int i;
	for(i = 0; i < (ordem - 1); i++){
		free(Node->chaves[i]);
	}
	free(Node->chaves);
	for(i = 0; i < ordem; i++){
		free(Node->filhos[i]);
	}
	free(Node->filhos);
	free(Node);
}

NodeArvore_B* PesquisaArvoreB(NodeArvore_B* arvore, char* k){
	int i = 0;
	while(i < arvore->numero_chaves && (strcmp(k, arvore->chaves[i])) > 0){
		i++;
	}
	if(arvore->chaves[i] == k){
		return arvore;
	}
	if(arvore->folha == true){
		return NULL;
	}
	return PesquisaArvoreB(arvore->filhos[i], k);
}

void splitChild(int i, NodeArvore_B* y, int ordem){
	NodeArvore_B* aux = ()
}
