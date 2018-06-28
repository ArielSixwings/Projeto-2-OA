#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ArvoreB.h"
#include "In_OutPuts.h"

int main(){
	BuildPrimaryKey(("lista1"), HowManyLines("lista1.txt"));
	
	Arvore_B teste;
	teste.raiz = NULL;
	teste.ordem = 6;
	NodeArvore_B* aux_Node = (NodeArvore_B*)malloc(sizeof(NodeArvore_B));

	CriaArvore_B(&teste,6);

	InserirArvore(&teste,"ana");
	InserirArvore(&teste,"breno");
	InserirArvore(&teste,"caio");
	InserirArvore(&teste,"debora");
	InserirArvore(&teste,"eduardo");
	InserirArvore(&teste,"fernando");


	//aux_Node = PesquisaArvoreB(teste.raiz, "fernando");
	if (aux_Node == teste.raiz)
	{
		printf("É o no certo\n");
	}
	//CriaArvore_B(&teste,6);
	free(aux_Node);
	return 0;
}