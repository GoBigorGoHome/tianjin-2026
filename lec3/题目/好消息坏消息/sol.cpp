/**
 *    author:  zjs
 *    created: 31.07.2026 11:07:09
**/
#include <bits/stdc++.h>
#include <cassert> // <bits/stdc++.h> does not include cassert since GCC 16.
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

const int maxn = 1e6 + 5;
int a[maxn];
int s[maxn];
int pref_min[maxn]; // pref_min[i] := min(s[1], ..., s[i])
// pref_min[0] = ??
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    s[0] = 0;
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
        pref_min[i] = min(pref_min[i - 1], s[i]);
    int suff_min = INT_MAX; // s 数组的后缀最小值
    int ans = 0;
    for (int k = n; k >= 1; k--) {
        suff_min = min(suff_min, s[k]);
        if (suff_min >= s[k-1] && pref_min[k - 1] >= s[k - 1] - s[n])
            ans++;
    }
    cout << ans << '\n';
}