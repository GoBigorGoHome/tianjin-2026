#include <bits/stdc++.h>
using namespace std;

int inverse(int x, int p) {
    return x == 1 ? 1 : p - (long long)(p / x) * inverse(p % x, p) % p;
}

int p;
unsigned long long q; // q = -1ull / p + 1; 

int mod(long long x) {
    int r = x - ((__int128) x * q >> 64) * p; 
    if (r < 0) r += p;
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> p >> k;
    q = -1ull / p + 1;

    long long sum = 0, t = 1, prod = 1;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        prod = mod(prod * k);
        sum = mod(sum * a + t * prod);
        t = t * a % p;
    }
    
    cout << sum * inverse((int)t, p) % p << '\n';
}