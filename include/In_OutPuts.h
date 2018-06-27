#ifndef IN_OUTPUTS_H
#define IN_OUTPUTS_H

#include <stdbool.h>

int HowManyLines(char* name);
char RemoveAccent(char C);
void BuildPrimaryKey(char* name, int size);
bool Occurance(char** List, char* comparison, int size);
void BuildSecondaryTable(char* name_withoutext, int size);
int HowManyInCourse(char* name_withoutext, int size, char* course);
void BuildSecondaryIndex(char* tablename, int tablesize, char* name_withoutext, int listsize);

#endif //IN_OUTPUTS_H