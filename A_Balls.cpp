#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }

    for (int length = 2; length <= n; length++) {
        for (int i = 1; i <= n-length + 1; i++) {
            int j = i + length - 1;

            dp[i][j] = 1 + dp[i+1][j];

            for (int k = i+1; k <= j; k++) {
                if (v[i] == v[k]) {
                    int currentCost = dp[i+1][k-1] + dp[k+1][j];
                    dp[i][j] = min(dp[i][j], currentCost);
                }
            }
        }
    }

    cout << dp[1][n] << endl;
    return 0;
}