/**
 *    author:  zjs
 *    created: 16.08.2026 15:12:53
**/
#include <bits/stdc++.h>
#include <cassert> // <bits/stdc++.h> does not include cassert since GCC 16.
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
const int mod = 1e9 + 7;
const int maxn = 205;
long long dp[maxn][maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[0][0] = 1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char delta;
        cin >> delta;
        for (int j = 0; j <= i; j++) {
            dp[i][j] %= mod;
            if (delta == '-') {
                dp[i + 1][j + 1] += dp[i][j];
            } else if (delta == 'U') {
                dp[i + 1][j + 1] += dp[i][j] * (i - j) % mod;
                dp[i + 1][j] += dp[i][j];
            } else {
                dp[i + 1][j + 1] += dp[i][j] * (i - j) % mod;
                dp[i + 1][j + 2] += dp[i][j] * (i - j) % mod * (i - j) % mod;
            }
        }
    }
    cout << dp[n][n] << '\n';
}