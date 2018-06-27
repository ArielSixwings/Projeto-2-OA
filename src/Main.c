#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ArvoreB.h"
#include "In_OutPuts.h"

int main(){
	BuildPrimaryKey(("lista1"), HowManyLines("lista1.txt"));
	
	Arvore_B teste;
	CriaArvore_B(&teste,6);
	DeletaNodeArvore(teste.raiz, 6);
	NodeArvore_B* teste2 = PesquisaArvoreB(teste.raiz, "jorge");
	printf("pesquisou certo\n");
	if(teste2 == NULL){
		printf("deu certo\n");
	}
	return 0;
}