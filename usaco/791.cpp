#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)

typedef long long LL;
const int mod = 1e9 + 7;

int add(int a, int b) {
  int c = a + b;
  if (c >= mod) c -= mod;
  return c;
}

int sub(int a, int b) {
  int c = a - b;
  if (c < 0) c += mod;
  return c;
}

int mult(int a, int b) {
  return (LL) a * b % mod;
}

void solve() {
  freopen("spainting.in", "r", stdin);
  freopen("spainting.out", "w", stdout);
  int n, m, k, ans = 1, s;
  queue<int> q;
  cin >> n >> m >> k;
  s = m;
  FOR(i, 0, n) ans = mult(ans, m);
  FOR(i, 0, k - 1) q.push(0);
  q.push(m);
  FOR(i, 0, n - 1) {
    int cnt1 = mult(s, m - 1);
    q.push(cnt1);
    s = add(s, cnt1);
    q.pop();
    s = sub(s, q.front());
  }

  ans = sub(ans, s);
  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
//  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
