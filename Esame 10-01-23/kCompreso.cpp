bool kCompreso(PNode u, int k) {
    int sum = 0;

    return kCompresoAux(u, k, sum);
}

bool kCompresoAux(PNode u, int k, int& sum) {
    if (u == nullptr)
        return true;
    else {
        int sommasx = 0;
        int sommadx = 0;
        bool leftkContained = kCompresoAux(u->left, k, sommasx);
        bool rightkContained = kCompresoAux(u->right, k, sommadx);
        sum = sommasx + sommadx + u->key;
        bool ukContained = sum < k && sum > -k;

        return leftkContained && rightkContained && ukContained;
    }
}