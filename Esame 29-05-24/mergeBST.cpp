#include <vector>

int maxBST(std::vector<int>& arr) {
    return arr.at(arr.size() - 1);
}

std::vector<int> mergeBST(std::vector<int>& arr1, std::vector<int>& arr2, int val) {
    std::vector<int> ris;
    ris.push_back(val);
    size_t sx = 0, j = 1, dx = 0;

    while (sx < arr1.size()) {
        size_t end = sx + j;
        while (sx < end) {
            ris.push_back(arr1[sx]);
            sx++;
        }
        while(dx < end) {
            ris.push_back(arr2[dx]);
            dx++;
        }
        j *= 2;
    }
    return ris;
}