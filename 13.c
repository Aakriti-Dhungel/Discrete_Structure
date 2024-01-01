#include <stdio.h>
int i,j,k;
void inputRelation(int matrix[10][10], int rows, int cols) {
    printf("Enter the relation matrix (%dx%d):\n", rows, cols);
    for ( i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
}
void displayRelation(int matrix[10][10], int rows, int cols) {
    printf("Relation matrix (%dx%d):\n", rows, cols);
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int isReflexive(int matrix[10][10], int size) {
    for ( i = 0; i < size; ++i) {
        if (matrix[i][i] != 1) {
            return 0;
        }
    }
    return 1;
}

int isSymmetric(int matrix[10][10], int size) {
    for ( i = 0; i < size; ++i) {
        for ( j = 0; j < size; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}
int isTransitive(int matrix[10][10], int size) {
    for ( i = 0; i < size; ++i) {
        for ( j = 0; j < size; ++j) {
            for ( k = 0; k < size; ++k) {
                if (matrix[i][j] && matrix[j][k] && !matrix[i][k]) {
                    return 0;
                }
            }
        }
    }
    return 1;
}
int isEquivalence(int matrix[10][10], int size) {
    return isReflexive(matrix, size) && isSymmetric(matrix, size) && isTransitive(matrix, size);
}
int main() {
    int rows, cols;
    printf("Enter the number of rows and columns for the relation matrix: ");
    scanf("%d %d", &rows, &cols);

    int relationMatrix[10][10];
    inputRelation(relationMatrix, rows, cols);
    displayRelation(relationMatrix, rows, cols);

    if (isReflexive(relationMatrix, rows)) {
        printf("The relation is reflexive.\n");
    } else {
        printf("The relation is not reflexive.\n");
    }

    if (isSymmetric(relationMatrix, rows)) {
        printf("The relation is symmetric.\n");
    } else {
        printf("The relation is not symmetric.\n");
    }

    if (isTransitive(relationMatrix, rows)) {
        printf("The relation is transitive.\n");
    } else {
        printf("The relation is not transitive.\n");
    }

    if (isEquivalence(relationMatrix, rows)) {
        printf("The relation is an equivalence relation.\n");
    } else {
        printf("The relation is not an equivalence relation.\n");
    }

    return 0;
}

