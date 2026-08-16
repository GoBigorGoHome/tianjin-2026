/**
 *    author:  zjs
 *    created: 17.08.2026 00:17:57
**/
#include <bits/stdc++.h>
#include <cassert> // <bits/stdc++.h> does not include cassert since GCC 16.
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int L, S, T, m;

bool check(int x) {
    // 是否存在非负整数 k 使得
    // k * S <= x <= k * T
    int k = x / S;
    return x <= (long long) k * T;
}

int main() {
    cin >> L >> S >> T >> m;
    vector<int> p(m);
    for (int i = 0; i < m; i++)
        cin >> p[i];
    
    sort(p.begin(), p.end());
    // 令 K = p[m - 1]
    /* 我们需要知道 min(f[K], f[K+1], ..., f[K+T-1])
    为此我们求 f[K-1], f[K-2], ..., f[K-T]
    
    把 p[0], p[1], ..., p[m-1] 称为关键点
    对每个关键点 p[i]，我们枚举第一次到达或超过这个点的位置
    有 T 种可能 p[i], p[i]+1, ..., p[i]+T-1
    */
   const int INF = m + 1;
   vector<int> dp(T, INF);
   dp[0] = 0;
   debug(dp);
   // [2, 3, 4] ==> [1, 0, 5]
   // [3, 4, 5] ==> []
   int x = 0;
   for (int y : p) {
        vector<int> new_dp(T, INF);
        for (int i = 0; i < T; i++) {
            if (x + i >= y) {
                int ni = x + i - y;
                new_dp[ni] = min(new_dp[ni], dp[i] + (ni == 0));
                continue;
            }
            // case 2: x + i -*-> y - j --> y + k 
            for (int j = 1; j <= T; j++) {
                if (x + i <= y - j && check(y - j - (x + i))) {
                    for (int k = 0; k < T; k++) {
                        if (S <= k + j && k + j <= T) {
                            int v = dp[i] + (k == 0);
                            new_dp[k] = min(new_dp[k], v);
                        }
                    }              
                }
            }
        }
        dp = new_dp;
        x = y;
        debug(dp);
    }
    cout << *min_element(dp.begin(), dp.end()) << '\n';
}