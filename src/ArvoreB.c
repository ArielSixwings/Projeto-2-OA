#include <string.h>
#include "ArvoreB.h"

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

void splitChild(int i, NodeArvore_B* y, int ordem){
	int j;
	NodeArvore_B* aux = (NodeArvore_B*) malloc(sizeof(NodeArvore_B));
	InicializaNodeArvore(aux, (ordem / 2), y->folha);
	aux->numero_chaves = (ordem / 2);
	for(j = 0; j < (ordem / 2); j++){
		aux->chaves[j] = y->chaves[j + (ordem / 2)];
	}
	if(y->folha == false){
		for(j = 0; j < (ordem / 2); j++){
			aux->filhos[j] = y->filhos[j + (ordem / 2)];
		}
	}

	y->numero_chaves = (ordem / 2) - 1;

	for(j = y->numero_chaves; j > i + 1; j--){
		y->filhos[j + 1] = y->filhos[j];
	}

	y->filhos[i + 1] = aux;

	for(j = y->numero_chaves - 1; j >= i; j--){
		y->chaves[j + 1] = y->chaves[j];
	}

	y->numero_chaves = y->numero_chaves + 1;
	free(aux);
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
		if(Node->filhos[i + 1]->numero_chaves == ordem){
			splitChild(i + 1, Node->filhos[i + 1], ordem);
			if((strcmp(Node->chaves[i], k)) < 0){
				i++;
			}
		}
		InserirNode(Node->filhos[i + 1], k, ordem);
	}
}

void InserirArvore(Arvore_B* arvore, char* k){
	if(arvore->raiz == NULL){
		arvore->raiz = (NodeArvore_B*) malloc(sizeof(NodeArvore_B));
		arvore->raiz->chaves[0] = k;
		arvore->raiz->numero_chaves = 1;
	}else{
		if(arvore->raiz->numero_chaves == arvore->ordem){
			NodeArvore_B* aux = (NodeArvore_B*) malloc(sizeof(NodeArvore_B));
			InicializaNodeArvore(aux, (arvore->ordem / 2), false);
			aux->filhos[0] = arvore->raiz;

			splitChild(0, aux, arvore->ordem);

			int i = 0;
			if((strcmp(aux->chaves[0], k)) < 0){
				i++;
			}

			InserirNode(aux->filhos[i], k, arvore->ordem);

			arvore->raiz = aux;
			free(aux);
		}else{
			InserirNode(arvore->raiz, k, arvore->ordem);
		}
	}
}
