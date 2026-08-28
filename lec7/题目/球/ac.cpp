/**
 *    author:  zjs
 *    created: 05.08.2026 13:35:57
**/
#include <bits/stdc++.h>
#include <cassert> // <bits/stdc++.h> does not include cassert since GCC 16.
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

struct dsu {
    vector<int> ps; // parent or size
    dsu(int n) : ps(n, -1) {}
    int leader(int x) {
        return ps[x] < 0 ? x : ps[x] = leader(ps[x]);
    }
    int merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return x;
        if (ps[x] < ps[y])
            swap(x, y);
        ps[y] += ps[x];
        ps[x] = y;
        return y;
    }
    bool same(int x, int y) {
        return leader(x) == leader(y);
    }
    int size(int x) {
        return -ps[leader(x)];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    dsu g(n + q + 1);
    vector<int> real(n + 1);
    for (int i = 1; i <= n; i++)
        real[i] = i;
    int id = n;
    while (q--) {
        char op;
        cin >> op;
        if (op == 'M') {
            int x, y;
            cin >> x >> y;
            g.merge(real[x], real[y]);
        } else {
            int x;
            cin >> x;
            real[x] = ++id;
        }
    }
    vector<bool> vis(id + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = g.leader(real[i]);
        if (!vis[j]) {
            vis[j] = true;
            ans++;
        }
    }
    cout << ans << '\n';
}
