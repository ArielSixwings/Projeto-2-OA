#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "In_OutPuts.h"


int HowManyLines(char* name){
	int howmany = 0;
	FILE * fpoint;
	fpoint = fopen(name, "r");
	if(!fpoint){
		printf("Arquivo não Encontrado\n");
		return 0;
	}
	while(!feof(fpoint)){
		if(fgetc(fpoint) == '\n'){
			howmany++;
		}
	}
	fclose(fpoint);
	return howmany;
}

void BuildPrimaryKey(char* name_withoutext, int size){
	int i, j;
	FILE * read;
	FILE * write;
	char auxname[3];
	char auxmat[5];
	char* name = (char*) malloc(sizeof(name_withoutext)+4);
	sprintf(name, "%s.txt", name_withoutext);
	read = fopen(name, "r");
	char* auxfile = (char*) malloc(sizeof(name_withoutext)+10);
	sprintf(auxfile, "indice%s.ind", name_withoutext);
	write = fopen(auxfile, "w+");
	for(j = 0; j < size; j++){
		fseek(read, 55*j, 0);
		fread(auxname, sizeof(char), 3, read);
		for(i = 0; i < 3; i++){
			auxname[i] = toupper(auxname[i]);
		}
		fwrite(auxname, sizeof(char), 3, write);
		fseek(read, 38, 1);
		fread(auxmat, sizeof(char), 5, read);
		fwrite(auxmat, sizeof(char), 5, write);
		fprintf(write, " %02d\n", j);
	}
	fclose(write);
	fclose(read);
	free(name);
	free(auxfile);
}
