#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


int main() {
    Vector vector;
    vectorInit(&vector);
    push(&vector, 5); // 0
    push(&vector, 8); // 1
    insertElem(&vector,2,777); // 2
    insertElem(&vector,4,778); // 3
    printf("====================\n");
    pop(&vector);
    printf("%d\n", vector.capacity);
    for (int i = 0; i < vector.size; ++i) {
        printf("%d\n", vectorGet(&vector,i));
    }



    vectorFree(&vector);
    return 0;
}
