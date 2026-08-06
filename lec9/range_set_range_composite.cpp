#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
const int mod = 998244353;

long long power(long long x, int n) {
    long long res = 1;
    while (n > 1) {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

struct Tag {
    long long c, d;
};

struct S {
    long long a, b;  
};

S op(S x, S y) {
    S res;
    res.a = x.a * y.a % mod;
    res.b = (y.a * x.b + y.b) % mod;
    return res;
}

S apply(Tag t, int len) {
    if (t.c == 1) {
        return {power(1, t.d * len % mod)};
    }
    long long p = power(t.c, len);
    return {p, (p - 1) *  }
}

Tag tag[maxn << 2];
S node[maxn << 2];

void set(int x, int l, int r, int ql, int qr, Tag t) {
    if (ql <= l && r <= qr) {
        
    }
}
int main() {
    int n, q;
    cin >> n >> q;
    
}