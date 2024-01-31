#include <stdio.h>
#include <stdlib.h>
#include "file.h"
int filesize(FILE* fd) {
    fseek(fd, 0, SEEK_END);
    int size = ftell(fd);
    rewind(fd);
    return size;
}
char* readfile(FILE* fd) {
    /* char c = fgetc(fd); */
    /* while(c != EOF) { */
    /*     printf("%c", c); */ 
    /*     c = fgetc(fd); */
    /* } */    
    int size = filesize(fd);
    char* buf = malloc(size * sizeof(char));
    if(buf == NULL) {
        printf("malloc failure");
        exit(1); 
    }
    fread(buf, sizeof(char), size, fd);
    fclose(fd);
    return buf;
}
