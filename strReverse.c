#include <stdio.h>

#define SIZE 100

int strLen(char str[]) {
    int index = 0;
    for ( ; str[index] != '\0'; index++ );
    return index;
}

void strReverse(char str[], int size) {
    for ( int index = 0, reverse = size - 1; index < reverse; index++, reverse-- ) {
        char buff = str[index];
        str[index] = str[reverse];
        str[reverse] = buff;
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    if (!in || !out) {
        fprintf(stderr, "File open error\n");
        return 1;
    }

    char str[SIZE + 1];
    int size;
    
    fgets(str, SIZE, in);
    
    size = strLen(str);
    strReverse(str, size);
    fprintf(out, "%s\n", str);
    
    fclose(in);
    fclose(out);
    return 0;
}
