#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ArvoreB.h"
#include "In_OutPuts.h"

int main(){
	BuildPrimaryKey(("lista1"), HowManyLines("lista1.txt"));
	
	Arvore_B teste;
	CriaArvore_B(&teste,6);	
	DeletaNodeArvore(teste.raiz);
	return 0;
}