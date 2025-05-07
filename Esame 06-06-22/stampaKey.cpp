#include <iostream>

void stampaKey(Node u) {
    stampaAux(u);
}

int stampaAux(Node u) {
    if (u == nullptr)
        return 0;
    else {
        int fsx = stampaAux(u->left);
        int fdx = stampaAux(u->right);

        if (fsx > fdx)
            std::cout << u->key;
        
        return fsx+fdx+1;
    }
}