struct NodeG {
    int key;
    NodeG* leftChild;
    NodeG* rightSib;
};
typedef NodeG* PNodeG;

bool isNonDec(PNodeG r) {
    if (r == nullptr)
        return true;
    // Controlla l'ordine dei figli del nodo corrente
    PNodeG child = r->leftChild;
    while (child != nullptr && child->rightSib != nullptr) {
        if (child->key > child->rightSib->key)
            return false;
        child = child->rightSib;
    }
    // Controlla ricorsivamente tutti i sottoalberi
    child = r->leftChild;
    while (child != nullptr) {
        if (!isNonDec(child))
            return false;
        child = child->rightSib;
    }
    return true;
}
