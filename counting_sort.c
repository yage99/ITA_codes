#include <stdio.h>

void print_list(int* list, int length) {
    int i = 0;
    for(; i < length; i++) {
        printf("%d:%d ", i, list[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    int A[8] = {2, 5, 3, 0, 2, 3, 0, 3};
    int C[6] = {0, 0, 0, 0, 0, 0};
    int B[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int i=0;

    for(i=0; i < 8; i++) {
        C[A[i]]++;
    }

    for(i = 1; i < 6; i++) {
        C[i] += C[i - 1];
    }
    for(i = 0; i < 6; i++) {
        C[i]--;
    }
    print_list(C, 6);

    for(i = 7; i >= 0; i--) {
        B[C[A[i]]] = A[i];
        C[A[i]] -= 1;
        printf("%d| ", i);
        print_list(B, 8);
    }
    print_list(B, 8);
}
