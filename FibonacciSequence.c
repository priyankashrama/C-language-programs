// C Program to print the fibonacci series using loops
#include <stdio.h>

void printFib(int n) {
  
  	// If the number of terms is smaller than 1
    if (n < 1) {
        printf("Invalid Number of terms\n");
        return;
    }
  
  	// First two terms of the series
    int prev1 = 1;
    int prev2 = 0;

    // for loop that prints n terms of fibonacci series
    for (int i = 1; i <= n; i++) {
      	
      	// Print current term and update previous terms
        if (i > 2) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
            printf("%d ", curr);
        }
		else if (i == 1)
            printf("%d ", prev2);
        else if (i == 2)
            printf("%d ", prev1);
    }
}

int main() {
    int n = 9;
  
  	// Printing first n fibonacci terms
    printFib(n);
    return 0;
}

// Output
// 0 1 1 2 3 5 8 13 21 

// Time Complexity: O(n), where n is the number of terms to be printed.
// Space Complexity: O(1).
