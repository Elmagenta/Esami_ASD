typedef struct Node {
    int key;
    Node* left;
    Node* right;
    Node* p;
}* PNode;

typedef struct Tree {
    PNode root;
}* PTree;

void rimuovi(PNode u) {
    if (u != nullptr) {
        rimuovi(u->left);
        rimuovi(u->right);
        delete u;
    }
}

void eliminaMaggioriK(PTree t, int k) {
    PNode iter, temp;
    iter = t->root;
    while (iter->key != k) {
        if (iter->key > k) {
            rimuovi(iter->right);
            iter->right = nullptr;
            temp = iter;
            transplant(t, iter, iter->left);
            iter = iter->left;
        }
        else
            iter = iter->right;
    }
    rimuovi(iter->right);
    iter->right = nullptr;
}