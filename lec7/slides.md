---
marp: true
math: mathjax
paginate: true
theme: lecture
title: 并查集
---

# 并查集

## Disjoint Set Union

---

```cpp
struct dsu {
    // parent or size.
    // 若 x 是根，那么 p[x] 等于 x 所在的集合的大小乘以 -1
    vector<int> p; 
    //构造函数
    dsu(int n) : p(n, -1) {} //元素是 0,...,n-1
     // 返回元素x所在的集合的代表元素
    int leader(int x) {
        return p[x] < 0 ? x : p[x] = leader(p[x]);   
    }
     // 将x所在的集合与y所在的集合合并，返回并集的代表元
    int merge(int x, int y) {
        int rx = leader(x);
        int ry = leader(y);
        if (rx == ry) return rx;
        // small-to-large 合并
        if (p[rx] < p[ry]) swap(rx, ry);
        // 以 rx 为根的树小
        p[ry] += p[rx];
        p[rx] = ry;
        return ry;
    }
    int size(int x) { //x 所在的集合的大小
        return -p[leader(x)];
    }
};
```
