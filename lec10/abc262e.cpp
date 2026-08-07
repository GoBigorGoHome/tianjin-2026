#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353; //是素数
int inverse(long long x) {
    if (x == 1) return 1;
    return mod - mod / x * inverse(mod % x) % mod;
}

const int maxn = 2e5 + 5;
int deg[maxn]; // 度
long long f[maxn]; // 阶乘

long long choose(int n, int m) { // 组合数
    if (m < 0 || m > n) return 0;
    return f[n] * inverse(f[m] * f[n - m] % mod) % mod;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    while (m--) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    int odd = 0;
    for (int i = 1; i <= n; i++)
        if (deg[i] % 2)
            odd++;
    
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] * i % mod;

    long long ans = 0;
    for (int i = 0; i <= min(odd, k); i += 2)
        ans += choose(odd, i) * choose(n - odd, k - i) % mod;
    cout << ans % mod << '\n';
}