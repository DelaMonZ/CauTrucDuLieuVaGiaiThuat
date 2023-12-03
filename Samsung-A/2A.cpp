#include <iostream>
#include <vector>
using namespace std;

int countGraphs(int V, int E) {
    if (E > V * (V - 1) / 2) {
        return 0;
    }

    if (E == 0) {
        return 1;
    }

    if (V == 0) {
        return 0;
    }

    vector<vector<bool>> dp(V + 1, vector<bool>(E + 1, false));

    dp[0][0] = true;

    for (int i = 1; i <= V; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= E; j++) {
            dp[i][j] = dp[i - 1][j];

            if (j >= i) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - i];
            }
        }
    }

    return dp[V][E];
}

int main() {
    int V = 4; // Số đỉnh
    int E = 3; // Số cạnh

    cout << "Số đồ thị vô hướng khác nhau có " << V << " đỉnh và " << E << " cạnh là: " << countGraphs(V, E) << endl;

    return 0;
}

