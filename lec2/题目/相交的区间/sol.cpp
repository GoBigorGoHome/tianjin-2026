/**
 *    author:  zjs
 *    created: 31.07.2026 09:11:26
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
int l[maxn], r[maxn];

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> l[i] >> r[i];
  sort(r, r + n);

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += lower_bound(r, r + n, l[i]) - r;
  }
  cout << (long long) n * (n - 1) / 2 - ans;
  return 0;
}
