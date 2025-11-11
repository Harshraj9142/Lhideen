#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Triple;

/* Function to convert matrix to sparse triplet form */
Triple* toSparse(int **mat, int m, int n, int *nonZeroCount) {
    int i, j, k = 1;
    *nonZeroCount = 0;

    /* Count non-zero elements */
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (mat[i][j] != 0)
                (*nonZeroCount)++;

    /* Allocate memory for sparse matrix (1 extra for header) */
    Triple *sparse = (Triple*)malloc((*nonZeroCount + 1) * sizeof(Triple));

    sparse[0].row = m;
    sparse[0].col = n;
    sparse[0].value = *nonZeroCount;

    /* Store non-zero elements */
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (mat[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = mat[i][j];
                k++;
            }
        }
    }
    return sparse;
}

/* Function to find transpose of a sparse matrix */
Triple* transposeSparse(Triple *sparse) {
    int m = sparse[0].row;
    int n = sparse[0].col;
    int t = sparse[0].value;

    Triple *trans = (Triple*)malloc((t + 1) * sizeof(Triple));
    int i, j, k = 1;

    trans[0].row = n;
    trans[0].col = m;
    trans[0].value = t;

    for (i = 0; i < n; i++) {  /* Column-wise traversal */
        for (j = 1; j <= t; j++) {
            if (sparse[j].col == i) {
                trans[k].row = sparse[j].col;
                trans[k].col = sparse[j].row;
                trans[k].value = sparse[j].value;
                k++;
            }
        }
    }

    return trans;
}

/* Function to display sparse triplet form */
void displaySparse(Triple *sparse) {
    int i;
    printf("\nRow\tCol\tValue\n");
    for (i = 0; i <= sparse[0].value; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

int main() {
    int m, n, i, j;
    int **matrix;
    int nonZeroCount;
    Triple *sparse, *transpose;

    printf("Enter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);

    /* Allocate memory for matrix */
    matrix = (int**)malloc(m * sizeof(int*));
    for (i = 0; i < m; i++)
        matrix[i] = (int*)malloc(n * sizeof(int));

    /* Input matrix */
    printf("\nEnter the matrix elements:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    /* Convert to sparse form */
    sparse = toSparse(matrix, m, n, &nonZeroCount);

    printf("\nSparse Representation (Triplet Format):");
    displaySparse(sparse);

    /* Find transpose */
    transpose = transposeSparse(sparse);
    printf("\nTranspose in Triplet Format:");
    displaySparse(transpose);

    /* Compare space */
    int normal_space = m * n * sizeof(int);
    int sparse_space = (nonZeroCount + 1) * sizeof(Triple);

    printf("\nMemory used by Normal Matrix: %d bytes", normal_space);
    printf("\nMemory used by Sparse Matrix: %d bytes\n", sparse_space);

    if (sparse_space < normal_space)
        printf("✅ Using Sparse Representation is Advantageous.\n");
    else
        printf("❌ Sparse Representation is NOT Advantageous.\n");

    /* Free memory */
    for (i = 0; i < m; i++)
        free(matrix[i]);
    free(matrix);
    free(sparse);
    free(transpose);

    return 0;
}
