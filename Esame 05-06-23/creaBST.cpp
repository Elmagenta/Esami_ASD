#include <iostream>
#include <vector>

typedef struct Node {
    int key;
    Node* left;
    Node* right;
    Node* p;

    Node(int k, Node* padre = nullptr, Node* sx = nullptr, Node* dx = nullptr) : key{k}, p{padre}, left{sx}, right{dx} {}
}* PNode;

typedef struct Tree {
    PNode root;

    Tree(PNode r = nullptr) : root{r} {}
}* PTree;

// Algoritmo visto a lezione. Complessità:  T(n) = Theta(n)
PNode buildBST(std::vector<int> v, int inf, int sup, PNode padre) {
    if (inf > sup)
        return nullptr;

    int med;
    PNode root;

    med = (inf + sup) / 2;
    root = new Node(v[med], padre);
    root->left = buildBST(v, inf, med - 1, root);
    root->right = buildBST(v, med + 1, sup, root);

    return root;
}

// Aggiungo le chiavi dell'intervallo all'interno di un vettore. Visito tutto l'albero, T(n) = O(n)
void collectKeys(PNode u, int lower, int upper, std::vector<int>& keys) {
    if (u) {
        if (u->key > upper)
            collectKeys(u->left, lower, upper, keys);
        else if (u->key < lower)
            collectKeys(u->right, lower, upper, keys);
        else {
            collectKeys(u->left, lower, upper, keys);
            keys.push_back(u->key);
            collectKeys(u->right, lower, upper, keys);
        }
    }
}

PTree creaBSTInterval(PTree t, int k) {
    if (!t || !t->root)
        return new Tree();

    std::vector<int> keys;
    int lower;
    
    lower = t->root->key; // Estremo inferiore: chiave della radice di T
    collectKeys(t->root, lower, k, keys);

    PTree ris = new Tree();
    if (!keys.empty()) 
        ris->root = buildBST(keys, 0, keys.size() - 1, nullptr);

    return ris;
}