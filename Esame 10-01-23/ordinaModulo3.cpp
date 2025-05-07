#include <vector>

void swap(std::vector<int>& A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void ordinaModulo3(std::vector<int>& A) {
    int n = A.size();
    // Prima partition: separa gli elementi con resto 0
    int k = 0; // Indice per elementi con resto 0
    for (int i = 0; i < n; i++) {
        if (A[i] % 3 == 0) {
            swap(A, k, i);
            k++;
        }
    }
    // Seconda partition: separa gli elementi con resto 1 da quelli con resto 2
    int j = k;
    for (int i = k; i < n; i++) {
        if (A[i] % 3 == 1) {
            swap(A, j, i);
            j++;
        }
    }
}