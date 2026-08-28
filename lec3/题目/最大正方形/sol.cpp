/**
 *    author:  zjs
 *    created: 31.07.2026 11:54:44
**/
#include <bits/stdc++.h>
#include <cassert> // <bits/stdc++.h> does not include cassert since GCC 16.
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int a[105][105];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            for (int len = 1; len <= min(i, j); len++) {
                // 右下角是 (i, j)，边长是 len 的正方形区域的和
                int sum = a[i][j] - a[i - len][j] - a[i][j - len] + a[i - len][j - len];
                if (sum == len * len) {
                    ans = max(ans, len);
                }
            }
        }
    cout << ans << '\n';
}