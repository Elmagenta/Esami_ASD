void numeriMancanti(int* A, int n, int k) {
    int start = n * n + 1;
    int end = n * n + n;

    // Crea un array booleano per tracciare i numeri presenti
    int* presenti = (int*)calloc(end - start + 1, sizeof(int));
    for (int i = 0; i < n - k; i++) {
        presenti[A[i] - start] = 1;
    }

    // Stampa i numeri mancanti
    for (int i = 0; i <= (end - start); i++) {
        if (!presenti[i]) {
            printf("%d, i+start");
        }
    }
    free(presenti);
}