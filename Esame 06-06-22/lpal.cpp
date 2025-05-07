#include <iostream>
#include <vector>

int lpal(std::vector<char> s) {
    int maxlung = s.size();
    std::vector<int>  mat[maxlung][maxlung];
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            mat[i][j] = -1;
        }
    }
    return lpaux(s, mat, 0, s.size());
}

int lpaux(std::vector<char> s, std::vector<int> mat, int i, int j) {
    if (mat[i][j] == -1) {
        if (i > j)
            mat[i][j] = 0;
        else {
            if (i == j)
                mat[i][j] = 1;
            else {
                int val;
                if (s[i] == s[j] && (val = lpaux(s, mat, i + 1, j - 1)) == j - i -1)
                    mat[i][j] = val + 2;
                else {
                    int v1 = lpaux(s, mat, i + 1, j);
                    int v2 = lpaux(s, mat, i, j - 1);
                    mat[i][j] = (v1 >= v2 ? v1 : v2);
                }
            }
        }
    }
}