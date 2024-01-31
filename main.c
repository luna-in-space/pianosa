#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int main(int argc, char** argv) {
    if(argc != 2){
        printf("err: usage\n");
        exit(1);
    }
    FILE* fd = fopen(argv[1], "r");
    if(fd == NULL) {
        printf("error: file open\n");
        exit(1);
    }
    int size = filesize(fd);
    char* buf = readfile(fd);
    printf("%s", buf);
    line_edit(buf, 2, size);
    fd = fopen(argv[1], "w");
    save_file(buf, fd);
    return 0;
}
