int percorsoPiuLungo(int alture[], int n) {
    int dp[100];
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (alture[j] <= alture[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    // Trovo il massimo valore in dp[]
    int max_length = dp[0];
    for (int i = 1; i < n; i++) {
        if (dp[i] > max_length) {
            max_length = dp[i];
        }
    }

    return max_length;
}