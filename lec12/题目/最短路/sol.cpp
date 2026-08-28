/**
 *    author:  zjs
 *    created: 10.08.2026 10:07:16
**/
#include <bits/stdc++.h>
#include <cassert> // <bits/stdc++.h> does not include cassert since GCC 16.
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

// 带权有向图
struct Edge {
    int to;
    int w;
};
const int maxn = 5e5 + 5;
vector<Edge> g[maxn]; // 邻接表 
// 路径
struct Path {
    int to; // 终点
    int last; // 上一个点
    long long len; // 长度
};
bool operator<(Path a, Path b) {
    return a.len > b.len;
}
// 写法1
void dijkstra(int n, int s, int t) {
    vector<bool> vis(n); // vis[i]：从s到i的最短路是否已经确定
    vector<int> last(n); // last[i]：从s到i的最短路的上一个点
    long long dist; 
    priority_queue<Path> q;
    q.push({s, -1, 0});
    while (!q.empty()) {
        Path p = q.top();
        q.pop();
        if (到p.to第一条路径还没发现)
        if (到p.to的第二条路径已经发现) continue;
        if (到p.to的第一条最短路已经发现 && 路径 p 的起点所属国家 != 第一条路径的起点所属的国家) {
            p 是到 p.to 的第二条路径。
        }
        vis[p.to] = true;
        last[p.to] = p.last;
        if (p.to == t) {
            dist = p.len;
            break;
        }
        // 从 p.to 做一轮松弛操作
        for (Edge e : g[p.to]) {
            // 我们发现了一条从 s 沿着最短路到 p.to，然后从 p.to 走边 e 到 e.to 的路径，
            // 它的长度是 p.len + e.w,
            // 把这条路径丢进优先队列。
            q.push({e.to, p.to, p.len + e.w});
        }
    }
}
// 写法2
struct Path2 {
    int to; // 终点
    long long len; // 长度
};
bool operator<(Path2 a, Path2 b) {
    return a.len > b.len;
}
void dijkstra_2(int n, int s, int t) {
    vector<long long> dist(n, LLONG_MAX);
    vector<int> last(n);
    priority_queue<Path2> q;
    dist[s] = 0;
    last[s] = -1;
    q.push({s, 0});
    while (!q.empty()) {
        Path2 p = q.top();
        q.pop();
        if (p.len != dist[p.to]) continue;
        for (Edge e : g[p.to])
            if (dist[e.to] > p.len + e.w) {
                dist[e.to] = p.len + e.w;
                last[e.to] = p.to;
                q.push({e.to, dist[e.to]});
            }
    }

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
}