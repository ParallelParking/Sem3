// Program that constructs a ragged array in pattern
// 1
// 2 3
// 4 5 6
// ...

#include <stdio.h>
#include <stdlib.h>

#define ROWS 5

int main() {
    //initial row alloc
    int** a = malloc(ROWS * sizeof(int*));
    int n = 1;

    //allocing columns
    for (int i = 0; i < ROWS; i++) {
        a[i] = malloc((i + 1) * sizeof(int));
        for (int j = 0; j <= i; j++) {
            a[i][j] = n++;
        }
    }

    //printing ragged array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}