#include <string.h>
#include "ArvoreB.h"

void InicializaNodeArvore(NodeArvore_B* Node,int ordem){

	Node->numero_chaves = 0;
	Node->folha = true;
	Node->chaves = (char**)malloc((ordem-1)*sizeof(char**));
	for(int i = 0; i < ordem - 1; i++){
		Node->chaves[i] = (char*) malloc(8*sizeof(char*));
	} 
	Node->posicao_filhos = (int*)malloc(ordem*sizeof(int));
}

void CriaArvore_B(Arvore_B* aux_Arvore_B,int ordem){
	NodeArvore_B aux_Node;
	InicializaNodeArvore(&aux_Node,ordem);
	
	/*Escrever em disco aux_Node*/

	aux_Arvore_B->raiz = &aux_Node;

}
void DeletaNodeArvore(NodeArvore_B* Node){

	free(Node->chaves);
	free(Node->posicao_filhos);
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
