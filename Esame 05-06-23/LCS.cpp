#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int lcs_memo(const string& X, const string& Y, int i, int j, vector<vector<int>>& memo) {
    if (memo[i][j] == -1) {
        if (i == 0 || j == 0) {
            memo[i][j] = 0;
        }
        else {
            if (X[i - 1] == Y[j - 1]) {
                memo[i][j] = 1 + lcs_memo(X, Y, i-1, j-1, memo);
            }
            else {
                memo[i][j] = max(
                    lcs_memo(X, Y, i-1, j, memo),
                    lcs_memo(X, Y, i, j-1, memo)
                );
            }
        }
    }

    return memo[i][j];
}

int lcs_top_down(const string& X, const string& Y) {
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> memo(m+1, vector<int>(n+1, -1));  // Inizializza a -1
    return lcs_memo(X, Y, m, n, memo);
}