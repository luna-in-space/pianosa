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
    char* buf = readfile(fd);
    printf("%s", buf);

    return 0;
}
