#include <stdlib.h>

bool check(int preorder[], int n) {
    int stack[n];
    int top = -1;
    int root = INT8_MIN;

    for (int i = 0; i < n; i++) {
        // Se troviamo un valore minimo della radice corrente, non è un BST
        if (preorder[i] < root)
            return false;
        // Pop dallo stack finché non troviamo il genitore corretto
        while (top >= 0 && preorder[i] > stack[top]) {
            root = stack[top--];
        }
        // Push del nodo corrente nello stack
        stack[++top] = preorder[i];
    }
    return true;
}