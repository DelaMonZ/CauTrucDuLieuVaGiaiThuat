#include <iostream>
#include <vector>

int LCS(std::vector<int> a, std::vector<int> b) {
    int m = a.size();
    int n = b.size();

    std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    std::vector<int> a = {3, 4, 5, 6, 7, 8};
    std::vector<int> b = {2, 4, 5, 7, 8, 9, 10};

    int length = LCS(a, b);
    std::cout << "Length of the longest common subsequence: " << length << std::endl;

    return 0;
}

