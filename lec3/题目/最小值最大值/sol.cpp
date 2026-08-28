/**
 *    author:  zjs
 *    created: 31.07.2026 09:59:48
**/
#include <bits/stdc++.h>
#include <cassert> // <bits/stdc++.h> does not include cassert since GCC 16.
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    int px = 0, py = 0, pb = 0;
    long long ans = 0;
    for (int r = 1; r <= n; r++) {
        int t;
        cin >> t;
        if (t == x) px = r;
        if (t == y) py = r;
        if (t > x || t < y) pb = r;
        // pb < l <= min(px, py)
        ans += max(0, min(px, py) - pb);
    }
}