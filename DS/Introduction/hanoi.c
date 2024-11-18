//prints tower of hanoi transfers

#include <stdlib.h>
#include <stdio.h>
#define N 5

void hanoi(int n, char source, char buffer, char destination) {
    static int moveCounter = 0;

    if (n == 0) return;

    hanoi(n - 1, source, destination, buffer);
    printf("%d. Moved disk %d from %c to %c\n", ++moveCounter, n, source, destination);
    hanoi(n - 1, buffer, source, destination);
}

int main() {
    hanoi(N, 'A', 'B', 'C');

    return 0;
}