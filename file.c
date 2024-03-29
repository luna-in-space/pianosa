#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int filesize(FILE* stream) {
    fseek(stream, 0, SEEK_END);
    int size = ftell(stream);
    rewind(stream);
    return size;
}
/* Returns a char pointer to a buffer that is the same size as the file */
char* readfile(FILE* stream) { 
    int size = filesize(stream);
    char* buf = malloc(size * sizeof(char));
    if(buf == NULL) {
        printf("malloc failure");
        exit(1); 
    }
    fread(buf, sizeof(char), size, stream);
    fclose(stream);
    return buf;
}
/*size is the size of the new line, if the size is wrong the string will truncate*/
/*TODO: Fix memory leak*/
void line_edit(char* buf, int line, int size) {
    char* temp = malloc(strlen(buf) * sizeof(char));
    for(int i = 0; i<line; i++) {
        buf = strchr(buf, '\n') + 1; 
    }
    strcpy(temp, buf);
    temp = strchr(temp, '\n') + 1;
    /* printf("temp: %s \n", temp); */
    /* printf("buf:  %s \n", buf); */
    fgets(buf, size, stdin); //how can the user know the size ahead of time? needs to be fixed
    /* printf("temp: %s \n", temp); */
    /* printf("buf:  %s \n", buf); */
    strcpy(buf + strlen(buf), temp);
}
void save_file(char* buf, FILE* fd) {
    fwrite(buf, strlen(buf), 1, fd);
    fclose(fd);
    return;
}
