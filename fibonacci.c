// filename: fibonacci.c
// Compile: gcc fibonacci.c -o fibonacci
// Run: ./fibonacci 10
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
 if (argc != 2) {
 printf("Usage: %s <n>\n", argv[0]);
 return 1;
 }
 int n = atoi(argv[1]);
 int a = 0, b = 1, c;
 printf("Fibonacci series up to %d terms:\n", n);
 for (int i = 0; i < n; i++) {
 printf("%d ", a);
 c = a + b;
 a = b;
 b = c;
 }
 printf("\n");
 return 0;
}
