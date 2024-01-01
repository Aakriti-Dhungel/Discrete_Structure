#include <stdio.h>
// Function to evaluate the logical expression
int evaluate(int p, int q, int r) {
    // Replace this with the logical expression you want to test
    return (p || (q && r));
}

// Function to print the truth table
int p,q,r;
void printTruthTable() {
    printf("P\tQ\tR\tExpression\n");
    for ( p = 0; p <= 1; ++p) {
        for ( q = 0; q <= 1; ++q) {
            for ( r = 0; r <= 1; ++r) {
                printf("%d\t%d\t%d\t%d\n", p, q, r, evaluate(p, q, r));
            }
        }
    }
}
int main() {
    // Print the truth table
    printTruthTable();

    return 0;
}

