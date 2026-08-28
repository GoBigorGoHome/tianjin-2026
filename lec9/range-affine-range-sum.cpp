/**
 *    author:  zjs
 *    created: 06.08.2026 11:28:47
**/
#include <bits/stdc++.h>
#include <cassert> // <bits/stdc++.h> does not include cassert since GCC 16.
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


const int maxn = 5e5 + 5;
const int mod = 998244353;
struct F { // 操作
    long long cheng = 1, jia = 0;
};
F id() { // 恒等操作
    return {1, 0};
}
// a 后，b 先
F composite(F a, F b) { // 操作的合成
    return {a.cheng * b.cheng % mod, (a.cheng * b.jia + a.jia) % mod};
}
vector<F> lz;
void apply_all(F a, int x) { // 把操作 a 作用在节点x上
    lz[x] = composite(a, lz[x]);
}
void push(int x) { //下传节点x的标记
    apply_all(lz[x], x * 2);
    apply_all(lz[x], x * 2 + 1);
    lz[x] = id();
}

F query(int x, int l, int r, int p) {
    if (l == r) return lz[x];
    int m = (l + r) / 2;
    F f;
    if (p <= m)
        f = query(x * 2, l, m, p);
    else
        f = query(x * 2 + 1, m + 1, r, p);
    return composite(lz[x], f);
}

void apply(int x, int l, int r, int ql, int qr, F f) {
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        apply_all(f, x);
        return;
    }
    push(x);
    int m = (l + r) / 2;
    apply(x * 2, l, m, ql, qr, f);
    apply(x * 2 + 1, m + 1, r, ql, qr, f);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    lz.resize(4 * n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int l, r, b, c;
            cin >> l >> r >> b >> c;
            apply(1, 0, n - 1, l, r - 1, {b, c});
        } else {
            int p;
            cin >> p;
            F f = query(1, 0, n - 1, p);
            cout << (f.cheng * a[p] + f.jia) % mod << '\n';
        }
    }
}