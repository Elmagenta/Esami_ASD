#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* creaNodo(int val) {
    Node* nuovo = (Node*)malloc(sizeof(Node));
    nuovo->val = val;
    nuovo->left = NULL;
    nuovo->right = NULL;
    return nuovo;
}

void aggiungiFigli(Node* root) {
    aggiungiFigliAux(root, 0);
}

void aggiungiFigliAux(Node* root, int somma) {
    if (root) {
        somma += root->val;
        // Se è una foglia, aggiungi il nuovo nodo
        if (!root->left && !root->right) {
            if (somma > 0)
                root->left = creaNodo(somma);
            else
                root->right = creaNodo(somma);
        }
        else {
            aggiungiFigliAux(root->left, somma);
            aggiungiFigliAux(root->right, somma);
        }
    }
        
}
