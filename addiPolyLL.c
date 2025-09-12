#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;


Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}


Node* insertTerm(Node* head, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (head == NULL || head->exp < exp) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    Node* prev = NULL;

    while (current != NULL && current->exp > exp) {
        prev = current;
        current = current->next;
    }

    if (current != NULL && current->exp == exp) {
        current->coeff += coeff;
        free(newNode);
    } else {
        newNode->next = current;
        if (prev != NULL) {
            prev->next = newNode;
        }
    }

    return head;
}


Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* p1 = poly1;
    Node* p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0)
                result = insertTerm(result, sumCoeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            result = insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            result = insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }


    while (p1 != NULL) {
        result = insertTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = insertTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}


void printPolynomial(Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        if (current->coeff > 0 && current != head) printf("+");

        if (current->exp == 0)
            printf("%d", current->coeff);
        else if (current->exp == 1)
            printf("%dx", current->coeff);
        else
            printf("%dx^%d", current->coeff, current->exp);

        current = current->next;
    }
    printf("\n");
}


void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    int n, coeff, exp;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    printf("Enter terms (coefficient exponent) in descending order of exponent:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        poly1 = insertTerm(poly1, coeff, exp);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    printf("Enter terms (coefficient exponent) in descending order of exponent:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        poly2 = insertTerm(poly2, coeff, exp);
    }

    printf("First polynomial: ");
    printPolynomial(poly1);

    printf("Second polynomial: ");
    printPolynomial(poly2);

    Node* sum = addPolynomials(poly1, poly2);

    printf("Sum of polynomials: ");
    printPolynomial(sum);

    freeList(poly1);
    freeList(poly2);
    freeList(sum);

    return 0;
}

