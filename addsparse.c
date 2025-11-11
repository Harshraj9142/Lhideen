#include <stdio.h>
#include <stdlib.h>

#define MAX 50   /* Maximum number of non-zero elements */

/* Function to read a sparse matrix in triplet form */
void readSparse(int sparse[MAX][3]) {
    int rows, cols, n, i;
    printf("Enter number of rows, columns and non-zero elements: ");
    scanf("%d %d %d", &rows, &cols, &n);

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = n;

    printf("Enter row, column and value for each non-zero element:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d %d %d", &sparse[i][0], &sparse[i][1], &sparse[i][2]);
    }
}

/* Function to display sparse matrix */
void displaySparse(int sparse[MAX][3]) {
    int i, n = sparse[0][2];
    printf("\nRow\tCol\tVal\n");
    for (i = 0; i <= n; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

/* Function to add two sparse matrices */
void addSparse(int a[MAX][3], int b[MAX][3], int result[MAX][3]) {
    int i = 1, j = 1, k = 1;
    int n1 = a[0][2], n2 = b[0][2];

    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        printf("Matrix dimensions do not match. Addition not possible.\n");
        result[0][2] = 0;
        return;
    }

    result[0][0] = a[0][0];
    result[0][1] = a[0][1];

    while (i <= n1 && j <= n2) {
        if (a[i][0] < b[j][0] ||
           (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2];
            i++; k++;
        }
        else if (b[j][0] < a[i][0] ||
                (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            result[k][0] = b[j][0];
            result[k][1] = b[j][1];
            result[k][2] = b[j][2];
            j++; k++;
        }
        else {
            /* Same position */
            int sum = a[i][2] + b[j][2];
            if (sum != 0) {
                result[k][0] = a[i][0];
                result[k][1] = a[i][1];
                result[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }

    /* Copy remaining elements */
    while (i <= n1) {
        result[k][0] = a[i][0];
        result[k][1] = a[i][1];
        result[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= n2) {
        result[k][0] = b[j][0];
        result[k][1] = b[j][1];
        result[k][2] = b[j][2];
        j++; k++;
    }

    result[0][2] = k - 1; /* total non-zero count */
}

int main() {
    int a[MAX][3], b[MAX][3], sum[MAX][3];

    printf("Enter first sparse matrix:\n");
    readSparse(a);

    printf("Enter second sparse matrix:\n");
    readSparse(b);

    printf("\nFirst Sparse Matrix:");
    displaySparse(a);

    printf("\nSecond Sparse Matrix:");
    displaySparse(b);

    addSparse(a, b, sum);

    if (sum[0][2] > 0) {
        printf("\nResultant Sparse Matrix after Addition:");
        displaySparse(sum);
    }

    return 0;
}
