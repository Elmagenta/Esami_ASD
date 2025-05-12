#include <vector>
#include <iostream>

void countingsort(std::vector<int>& arr, int exp, int n) {
    std::vector<int> output(n);
    std::vector<int> count(n, 0);
    // Conta le occorrenze di ogni cifra
    for (int i = 0; i < n; i++) {
        int index = (arr[i] / exp) % n;
        count[index]++;
    }
    for (int i = 1; i < n; i++) {
        count[i] += count[i + 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % n;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void ordina(std::vector<int>& arr) {
    int n = arr.size();
    if (n > 1) {
        // Poiché i numeri vanno da 0 a n^4 - 1 abbiamo bisogno di 4 passi
        // Perché n^4 - 1 può essere rappresentato con 4 cifre in base n
        for (int exp = 1; exp <= pow(n, 3); exp *= n)
            countingsort(arr, exp, n);
    }
}