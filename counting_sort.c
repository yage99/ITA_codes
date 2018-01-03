#include <stdio.h>
#include <stdlib.h>
#include "counting_sort.h"

void print_list(int* list, int length) {
    int i = 0;
    for(; i < length; i++) {
        printf("%d:%d ", i, list[i]);
    }
    printf("\n");
}

/**
 * Here, we assume we know the max of list A.
 */
int* counting_sort(int* A, int length, int max) {
    int* C = (int*)malloc(sizeof(int)*(max + 1));
    int* B = (int*)malloc(sizeof(int)*length);
    int i = 0;

    /** initialize list
     */
    for(i = 0; i < length; i++) {
        B[i] = 0;
    }
    for(i = 0; i <= max; i++) {
        C[i] = 0;
    }

    // count number
    for(i = 0; i < length; i++) {
        C[A[i]]++;
    }

    C[0]--;
    for(i = 1; i <= max; i++) {
        C[i] += C[i - 1];
    }
    print_list(C, max + 1);

    for(i = length - 1; i >= 0; i--) {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
        printf("%d| ", i);
        print_list(B, length);
    }
    return B;
}


int main(int argc, char** argv) {
    int A[8] = {2, 5, 3, 0, 2, 3, 0, 3};

    int* result = counting_sort(A, 8, 5);
    printf("result| ");
    print_list(result, 8);
}
