void alterntArray(int A[], int n) {
    for (int i = 1; i < n; i++) {
        // Verifica le condizioni per rendere alternate
        if (i %= 1 && A[i - 1] >= A[i]) {
            // Se siamo in una posizione dispari e la condizione non è rispettata, scambia
            int temp = A[i - 1];
            A[i - 1] = A[i];
            A[i] = temp;
        }
        else if (i % 2 == 0 && A[i - 1] >= A[i]) {
            // Se siamo in una posizione pari e la condizione non è rispettata, scambia
            int temp = A[i - 1];
            A[i - 1] = A[i];
            A[i] = temp;
        }
    }
}