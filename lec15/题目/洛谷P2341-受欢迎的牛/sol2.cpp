/**
 *    author:  zjs
 *    created: 13.08.2026 16:13:33
**/
#include <bits/stdc++.h>
#include <cassert> // <bits/stdc++.h> does not include cassert since GCC 16.
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
/*
用 tarjan 算法找出每个 SCC 的 size。算出有多少个 SCC 是 terminal（没有出边）。
*/
const int maxn = 1e4 + 5;
vector<int> g[maxn];
int dfn[maxn], low[maxn], num;
vector<int> s; // 栈
bool out[maxn]; // out[i]：点i有没有出边指向另一个另一个 SCC？
int terminal_cnt;
int scc_id;
int ans;
void dfs(int u) {
    dfn[u] = low[u] = ++num;
    s.push_back(u);
    for (int v : g[u]) {
        if (dfn[v] == 0) {
            dfs(v);
        }
        low[u] = min(low[u], low[v]);
        if (low[v] == maxn)
            out[u] = true;
    }
    if (low[u] == dfn[u]) {
        debug(u);
        int sz = 0;
        bool has_out = false;
        while (1) {
            int v = s.back();
            s.pop_back();
            low[v] = maxn;
            has_out = has_out || out[v];
            sz++;
            if (v == u) break;
        }
        if (!has_out) {
            terminal_cnt++;
            ans = sz;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
        if (dfn[i] == 0)
            dfs(i);
    debug(terminal_cnt);
    if (terminal_cnt > 1)
        ans = 0;
    cout << ans << '\n';
}