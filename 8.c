#include <stdio.h>
// Function to calculate the truth value of a compound proposition
int evaluateProposition(int operand1, char operator, int operand2) {
    switch (operator) {
        case '&':
            return operand1 && operand2;
        case '|':
            return operand1 || operand2;
        case '!':
            return !operand1;
        default:
            return -1; // Invalid operator
    }
}
// Function to generate truth tables for a compound proposition
void generateTruthTable(char var[], int numVar, char proposition[]) {
    int numRows = 1 << numVar; // Number of rows in the truth table (2^n)
    int i,row;
    // Print table header
    printf("Truth Table for: %s\n", proposition);
    for (i = 0; i < numVar; ++i) {
        printf("%c ", var[i]);
    }
    printf("| %s\n", proposition);
    
    // Print separator line
    for (i = 0; i < numVar + 1; ++i) {
        printf("--");
    }
    printf("\n");
    
    // Generate and print truth table
    for ( row = 0; row < numRows; ++row) {
        int values[26]; // Assuming no more than 26 variables
        int currentRow = row;
        // Extract values for each variable
        for ( i = 0; i < numVar; ++i) {
            values[i] = currentRow % 2;
            currentRow /= 2;
        }  
        // Evaluate the proposition for the current variable values
        int result = 0;
        for ( i = 0; proposition[i] != '\0'; ++i) {
            if ('A' <= proposition[i] && proposition[i] <= 'Z') {
                result = values[proposition[i] - 'A'];
            } else if (proposition[i] == '&' || proposition[i] == '|' || proposition[i] == '!') {
                char operator = proposition[i];
                int nextOperand = (proposition[i + 1] == '!' ? !values[proposition[i + 2] - 'A'] : values[proposition[i + 1] - 'A']);
                result = evaluateProposition(result, operator, nextOperand);
                i += (proposition[i + 1] == '!' ? 2 : 1);
            }
        }
        
        // Print the row of the truth table
        for ( i = 0; i < numVar; ++i) {
            printf("%d ", values[i]);
        }
        printf("| %d\n", result);
    }
}
int main() {
    char var[26];
    char proposition[100];
    // Input variables
    printf("Enter the variables (e.g., ABC): ");
    scanf("%s", var);
    int numVar = 0;
    while (var[numVar] != '\0') {
        numVar++;
    }
    // Input compound proposition
    printf("Enter the compound proposition (use ! for NOT, & for AND, | for OR): ");
    scanf("%s", proposition);
    // Generate and print truth table
    generateTruthTable(var, numVar, proposition);

    return 0;
}

