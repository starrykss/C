#include <stdio.h>
#include <string.h>

typedef struct {
    char sentence[100];
} Test2;

typedef struct {
    Test2 head[10];
} Test;


void main() {
    Test tst;
    char input[100];
    gets(input);

    strcpy(tst.head[0].sentence, input);
    printf("%s", tst.head[0].sentence);
}