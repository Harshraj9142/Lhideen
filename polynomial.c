#include <stdio.h>

struct Term {
    int coeff;
    int pow;
};

void inputPoly(struct Term poly[], int n) {
    int i;
    printf("\nEnter the coefficient and power for each term (in descending order of power):\n");
    for (i = 0; i < n; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d%d", &poly[i].coeff, &poly[i].pow);
    }
}

void displayPoly(struct Term poly[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%dx^%d", poly[i].coeff, poly[i].pow);
        if (i != n - 1)
            printf(" + ");
    }
    printf("\n");
}

int addPoly(struct Term p1[], int n1, struct Term p2[], int n2, struct Term res[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (p1[i].pow > p2[j].pow) {
            res[k++] = p1[i++];
        } else if (p1[i].pow < p2[j].pow) {
            res[k++] = p2[j++];
        } else {
            res[k].pow = p1[i].pow;
            res[k].coeff = p1[i].coeff + p2[j].coeff;
            k++;
            i++;
            j++;
        }
    }

    while (i < n1)
        res[k++] = p1[i++];
    while (j < n2)
        res[k++] = p2[j++];

    return k;
}

int multiplyPoly(struct Term p1[], int n1, struct Term p2[], int n2, struct Term res[]) {
    int k = 0;
    int i, j;

    // Multiply each term
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            res[k].pow = p1[i].pow + p2[j].pow;
            res[k].coeff = p1[i].coeff * p2[j].coeff;
            k++;
        }
    }

    // Combine like terms (same powers)
    int x, y;
    for (x = 0; x < k; x++) {
        for (y = x + 1; y < k; y++) {
            if (res[x].pow == res[y].pow) {
                res[x].coeff += res[y].coeff;
                int z;
                for (z = y; z < k - 1; z++)
                    res[z] = res[z + 1];
                k--;
                y--;
            }
        }
    }
    return k;
}

int main() {
    struct Term poly1[10], poly2[10], sum[20], prod[50];
    int n1, n2, nsum, nprod;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    inputPoly(poly1, n1);

    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &n2);
    inputPoly(poly2, n2);

    printf("\nPolynomial 1: ");
    displayPoly(poly1, n1);

    printf("Polynomial 2: ");
    displayPoly(poly2, n2);

    nsum = addPoly(poly1, n1, poly2, n2, sum);
    printf("\nSum: ");
    displayPoly(sum, nsum);

    nprod = multiplyPoly(poly1, n1, poly2, n2, prod);
    printf("Product: ");
    displayPoly(prod, nprod);

    return 0;
}
