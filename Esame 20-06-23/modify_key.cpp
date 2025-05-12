#include <vector>

typedef struct Node {
    int key;
    Node* left;
    Node* right;
    Node* p;

    Node(int k, Node* padre, Node* sx = nullptr, Node* dx = nullptr) : key{k}, p{padre}, left{sx}, right{dx} {}
}* PNode;

typedef struct Tree {
    PNode root;

    Tree(PNode r = nullptr) : root{r} {}
}* PTree;

// Funzione di supporto per verificare se un sottoalbero è un BST
bool isBSTUtil(PNode node, int min, int max) {
    if (node == nullptr)
        return true;
    if (node->key < min || node->key > max)
        return false;
    return isBSTUtil(node->left, min, node->key - 1) && isBSTUtil(node->right, node->key + 1, max);
}

PTree Modify_key(PTree t, PNode x, int new_key) {
    if (t == nullptr || x == nullptr)
        return nullptr;

    int old_key = x->key;
    x->key = new_key; // Modifica temporanea
    bool valid = isBSTUtil(t->root, INT8_MIN, INT8_MAX);

    if (!valid) {
        x->key = old_key;
        return nullptr;
    }

    return t;
}