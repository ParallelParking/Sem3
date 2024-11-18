//recursive function group file

#include <stdlib.h>
#include <stdio.h>
#define N 5

//factorial
int factorial(int n) {
    if (n == 1) return 1;

    return n * factorial(n - 1);
}

//multiplying 2 natural numbers
int multiply(int m, int n) {
    if (n == 0) return 0;

    return m + multiply(m, n - 1);
}

//fibonacci sequence
int fibonacci(int n) {
    if (n == 1 || n == 0) return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

//binary search
int binsearch(int a[], int x, int b, int e) {
    if (b > e) return -1;
    
    int m = (b + e) / 2;
    if (a[m] == x) return m;

    if (a[m] < x) return binsearch(a, x, b + 1, e);
    if (a[m] > x) return binsearch(a, x, b, e - 1);
}

//length of string using static
int strlength(char* s) {
    static int l = 0;
    if (*s == '\0') return l;
    l += 1;
    return strlength(s + 1);
} 

//String palindrome test
int isPalindrome(char* s, int b, int e) {
    if (b > e) return 1;
    if (s[b] != s[e]) return 0;

    return isPalindrome(s, b + 1, e - 1);
}

//Copy one string to another
void copy(char* s, char* t, int i) {
    //copy t into s
    s[i] = t[i];
    if (t[i] == '\0') return;
    copy(s, t, i + 1);
}

int main() {
    printf("N = %d\n", N);
    printf("Factorial: %d\n", factorial(N));
    printf("N * 4 = %d\n", multiply(N, 4));
    printf("Fibonacci term: %d\n", fibonacci(N));

    int a[] = {1,2,3,4,5};
    printf("{1,2,3,4,5}, found 2 at index: %d\n", binsearch(a, 2, 0, 4));

    char s[] = "MALAYALAM";
    printf("String = %s\n", s);
    int l = strlength(s);
    printf("Length of string: %d\n", l);
    printf("Is palindrome?: %d\n", isPalindrome(s, 0, l - 1));
    copy(s, "TEST", 0);
    printf("Copied 'TEST' to string: %s", s);

    return 0;
}