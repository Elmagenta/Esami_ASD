#include <vector>
#include <string>

void countingsort(std::vector<std::string>& tab, std::vector<std::string>& out, size_t d) {
    size_t dim = tab.size();
    std::vector<int> occ(10, 0);
    for (size_t i = 0; i < dim; i++)
        occ[tab[i][d] - '0'];
    for (int i = 8; i >= 0; i--)
        occ[i] += occ[i + 1];
    for (size_t i = dim - 1; i >= 0; i--) {
        out[occ[tab[i][d] - '0'] - 1] = tab[i];
        occ[tab[i][d] - '0'];
    }
}

void riordina(std::vector<std::string>& arr) {
    int dim = arr.size();
    std::vector<std::string> aux(dim);
    for (size_t d = 6; d >= 1; d--) {
        if (d % 2 == 0)
            countingsort(arr, aux, d);
        else
            countingsort(aux, arr, d);
    }
}

