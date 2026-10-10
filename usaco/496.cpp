#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define SZ(a) int(a.size())

typedef long long LL;

int t, n;
multiset<LL, greater<>> ms;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("cowjog.in", "r", stdin);
  freopen("cowjog.out", "w", stdout);

  cin >> n >> t;
  FOR(i, 0, n) {
    int p0, v;
    cin >> p0 >> v;
    LL p = (LL) p0 + (LL) v * t;
    auto it = ms.upper_bound(p);
    if (it != ms.end()) ms.erase(it);
    ms.insert(p);
  }
  cout << SZ(ms);
}
