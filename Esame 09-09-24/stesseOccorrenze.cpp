#include <vector>

bool stesseOccorrenze(std::vector<int>& arr) {
    int i = 0, j = 0;
    bool ok = false;
    std::vector<int> occ(arr.size() + 1);
    if (arr.size() < 2)
        return false;
    mergesort(arr, 0, arr.size() - 1);
    while (i < arr.size() && !ok) {
        j = i + 1;
        while (j < arr.size() && arr[i] == arr[j]) 
            j++;
        if (occ[j - i] == 0) {
            occ[j - i] = 1;
            i = j;
        }
        else {
            ok = true;
        }
    }
    return ok;
}