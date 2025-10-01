// filename: armstrong.c
// Compile: gcc armstrong.c -o armstrong
// Run: ./armstrong 153

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }
    int num = atoi(argv[1]);
    int original = num, sum = 0, digits = 0, temp = num;

    while (temp > 0) { digits++; temp /= 10; }

    temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    if (sum == original)
        printf("%d is an Armstrong number.\n", original);
    else
        printf("%d is not an Armstrong number.\n", original);
    return 0;
}
