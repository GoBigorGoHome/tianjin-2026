#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    vector<int> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = p - (long long) (p / i) * inv[p % i] % p;
    for (int i = 1; i <= n; i++)
        cout << inv[i] << '\n';
}