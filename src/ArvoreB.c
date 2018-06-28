#include <string.h>
#include "ArvoreB.h"

int MenorParImpar(int ordem){
	if(ordem%2 == 0){
		return (ordem / 2) - 1;
	}else{
		return (ordem / 2);
	}
}
	
void InicializaNodeArvore(NodeArvore_B* Node,int ordem, int leaf){
	int i;
	Node->numero_chaves = 0;
	Node->folha = leaf;
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
	InicializaNodeArvore(aux_Node, ordem, true);
	
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

void splitChild(int i, NodeArvore_B* x, int ordem){
	int j;
	NodeArvore_B* z = (NodeArvore_B*) malloc(sizeof(NodeArvore_B));
	NodeArvore_B* y = x->filhos[i] ;
	InicializaNodeArvore(z, ordem, y->folha);
	z->numero_chaves = MenorParImpar(ordem);
	for(j = 0; j < MenorParImpar(ordem); j++){
		z->chaves[j] = y->chaves[j + MenorParImpar(ordem)+1];
	}
	if(y->folha == false){
		for(j = 0; j < (MenorParImpar(ordem) + 1); j++){
			z->filhos[j] = y->filhos[j + MenorParImpar(ordem)+1];
		}
	}

	y->numero_chaves = MenorParImpar(ordem);

	for(j = (x->numero_chaves + 1); j > (i + 1); j--){
		x->filhos[j + 1] = x->filhos[j];
	}

	x->filhos[i + 1] = z;

	for(j = x->numero_chaves; j >= i; j--){
		x->chaves[j + 1] = x->chaves[j];
	}

	x->chaves[i] = y->chaves[MenorParImpar(ordem) + 1];
	x->numero_chaves = x->numero_chaves + 1;
}

void InserirNode(NodeArvore_B* Node, char* k, int ordem){
	int i = Node->numero_chaves;

	if(Node->folha == true){
		while(i >= 0 && (strcmp(Node->chaves[i], k)) > 0){
			Node->chaves[i + 1] = Node->chaves[i];
			i--;
		}

		Node->chaves[i + 1] = k;
		Node->numero_chaves = Node->numero_chaves + 1;
	}else{
		while(i >= 0 && (strcmp(Node->chaves[i], k)) > 0){
			i--;
		}
		i++;
		if(Node->filhos[i]->numero_chaves == (ordem-1)){
			splitChild(i, Node->filhos[i], ordem);
			if((strcmp(Node->chaves[i], k)) < 0){
				i++;
			}
		}
		InserirNode(Node->filhos[i], k, ordem);
	}
}

void InserirArvore(Arvore_B* arvore, char* k){
	NodeArvore_B* auxraiz = arvore->raiz;
	if(auxraiz->numero_chaves == ((arvore->ordem) - 1)){
		NodeArvore_B* aux = (NodeArvore_B*) malloc(sizeof(NodeArvore_B));
		arvore->raiz = aux;
		aux->folha = false;
		aux->numero_chaves = 0;
		aux->filhos[0] = auxraiz;
		splitChild(0, aux, arvore->ordem);

		InserirNode(aux, k, arvore->ordem);
	}else{
		InserirNode(auxraiz, k, arvore->ordem);
	}
}