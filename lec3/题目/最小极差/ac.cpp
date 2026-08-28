#include <bits/stdc++.h>
#include <cassert>
using namespace std;

template<class T, size_t size = tuple_size<T>::value>
string to_debug(T, string s = "")
  requires(not ranges::range<T>);

string to_debug(auto x)
  requires requires(ostream &os) { os << x; }
{
  return static_cast<ostringstream>(ostringstream() << x).str();
}

string to_debug(ranges::range auto x, string s = "")
  requires(not is_same_v<decltype(x), string>)
{
  for (auto xi: x) {
    s += ", " + to_debug(xi);
  }
  return "[" + s.substr(s.empty() ? 0 : 2) + "]";
}

template<class T, size_t size>
string to_debug(T x, string s)
  requires(not ranges::range<T>)
{
  [&]<size_t... I>(index_sequence<I...>) { ((s += ", " + to_debug(get<I>(x))), ...); }(make_index_sequence<size>());
  return "(" + s.substr(s.empty() ? 0 : 2) + ")";
}
#ifdef LOCAL
#define debug(...) cerr << "(" #__VA_ARGS__ ") = " << to_debug(tuple(__VA_ARGS__)) << "\n"
#else
#define debug(...) 42
#endif

using namespace std;


template<typename T, typename U> bool chmin(T& a, U b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

const int mod = 998244353;

int inv(int x, int m) {
  int u = 0, v = 1;
  while (x) {
    int q = m / x;
    m -= q * x;
    u -= q * v;
    swap(u, v);
    swap(x, m);
  }
  assert(m == 1);
  return u;
}

int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  vector<long long> b(m);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  sort(b.begin(), b.end());
  vector<int> ptr(n);

  long long max_value = *max_element(a.begin(), a.end()) + b[0];
  min_pq<pair<long long,int>> next;
  set<pair<long long, int>> cur;

  for (int i = 0; i < n; i++) {
    while (ptr[i] < m && a[i] + b[ptr[i]] <= max_value) {
      ptr[i]++;
    }
    cur.insert({a[i] + b[ptr[i] - 1], i});
    if (ptr[i] < m)
      next.push({a[i] + b[ptr[i]], i});
  }

  long long ans = LLONG_MAX;

  while (1) {
    auto [v, i] = *cur.begin();
    chmin(ans, max_value - v);
    if (ptr[i] == m) // 最小值不可能变大
      break;
    max_value = a[i] + b[ptr[i]];

    while (!next.empty()) {
      auto [v, i] = next.top();
      if (v > max_value) break;
      next.pop();
      cur.erase({a[i] + b[ptr[i] - 1], i}); // 删除旧的
      while (ptr[i] < m && a[i] + b[ptr[i]] <= max_value) {
        ptr[i]++;
      }
      cur.insert({a[i] + b[ptr[i] - 1], i}); // 加入新的
      if (ptr[i] < m)
        next.push({a[i] + b[ptr[i]], i});
    }
    
  }
  cout << ans << '\n';
}
