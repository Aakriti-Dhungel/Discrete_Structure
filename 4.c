#include <stdio.h>
// Function to find the GCD using Euclidean algorithm
int euclideanGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
// Function to find the GCD and coefficients using Extended Euclidean algorithm
int extendedEuclidean(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}
int main() {
    int num1, num2;
    // Input two numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    // Find GCD using Euclidean algorithm
    int gcd = euclideanGCD(num1, num2);
    printf("GCD of %d and %d using Euclidean algorithm: %d\n", num1, num2, gcd);
    // Find GCD and coefficients using Extended Euclidean algorithm
    int x, y;
    int extendedGCD = extendedEuclidean(num1, num2, &x, &y);
    printf("GCD of %d and %d using Extended Euclidean algorithm: %d\n", num1, num2, extendedGCD);
  // printf("Coefficients (x, y) satisfying Bézout's identity: (%d, %d)\n", x, y);
    return 0;
}

