#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* readfile(FILE* stream);
int filesize(FILE* stream);
void line_edit(char* buf, int line, int size);
void save_file(char* buf, FILE* fd);
#endif
