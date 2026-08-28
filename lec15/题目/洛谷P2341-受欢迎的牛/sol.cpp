/**
 *    author:  zjs
 *    created: 13.08.2026 15:39:30
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
给你一个有向图G，判断上面有没有点能到所有点。如果有，求这样的点有多少个。
解法：对图G进行DFS。最后一次DFS的起点一定是一个拓扑序极小的 SCC 的 leader。
判断能否从这个点到达所有点。若不能，则不存在能到所有点的点。否则这个 leader 所在的 SCC 里的每个点都能到所有点。
*/
const int maxn = 1e4 + 4;
bool vis[maxn];
int cnt;
void init() {
    cnt = 0;
    memset(vis, 0, sizeof vis);
}
void dfs(int u, vector<int>* g) {
    if (vis[u]) return;
    vis[u] = true;
    ++cnt;
    for (int v : g[u])
        dfs(v, g);
}

vector<int> g[maxn], g2[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // a 喜欢 b
        g[b].push_back(a);
        g2[a].push_back(b);
    }
    int leader = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            dfs(i, g);
            leader = i;
        }
    init();
    dfs(leader, g);
    if (cnt != n) {
        cout << 0 << '\n';
        return 0;
    }
    init();
    dfs(leader, g2);
    cout << cnt << '\n';
}