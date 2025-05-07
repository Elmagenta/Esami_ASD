typedef struct Node {
    int key;
    Node* left;
    Node* right;
    Node* p;

    Node(int k, Node* padre = nullptr, Node* sx = nullptr, Node* dx = nullptr) {
        key = k;
        p = padre;
        left = sx;
        right = dx;
    }
}* PNode;

typedef struct Tree {
    PNode root;

    Tree(PNode r = nullptr) {
        root = r;
    }
}* PTree;

void tree_insert(PTree t, PNode z) {
    // POST: Inserisco il nodo z nell'albero t
    PNode y = nullptr;
    PNode x = t->root;

    while (x != nullptr) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->p = y;
    if (y == nullptr)
        t->root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
}

void transplant(PTree T, PNode u, PNode z) {
    if (u->p == nullptr)
        T->root = z;
    else {
        if (u->p->left == u)
            u->p->left = z;
        else
            u->p->right = z;
    }
    if (z != nullptr)
        z->p = u->p;
}

// Soluzione 1
PTree mergeBST(PTree T1, PTree T2) {
    PTree ris;
    if (T1->root == nullptr)
        return T2;
    if (T2->root == nullptr)
        return T1;
    PNode iter;
    iter = T1->root;
    while (iter->right != nullptr)
        iter = iter->right;
    iter->right = T2->root;
    T2->root->p = iter;
    delete(T2);
    return T1;
}

// Soluzione 2
PTree mergeBST2(PTree T1, PTree T2) {
    PTree ris;
    if (T1->root == nullptr)
        return T2;
    if (T2->root == nullptr)
        return T1;
    PNode iter;
    iter = T1->root;
    while (iter->right != nullptr)
        iter = iter->right;
    if (iter == T1->root)
        ris = T1;
    else {
        transplant(T1, iter, iter->left);
        ris = new Tree{iter};
        iter->p = nullptr;
        iter->left = T1->root;
        T1->root->p = iter;
        delete T1;
    }
    iter->right = T2->root;
    T2->root->p = iter;
    delete T2;
    return ris;
}