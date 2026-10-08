#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define PB push_back

typedef pair<int, int> PII;
typedef long long LL;

const int MAX_N = 10'001;
int n, m, t;
array<vector<PII>, MAX_N> g;
array<int, MAX_N> dp;
int c[MAX_N], sz[MAX_N], p[MAX_N];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
stack<int> st;


void solve() {
  freopen("shortcut.in", "r", stdin);
  freopen("shortcut.out", "w", stdout);
  cin >> n >> m >> t;
  n++;
  FOR(i, 1, n) {
    dp[i] = INT_MAX;
    p[i] = INT_MAX;
  }
  dp[1] = 0;
  p[1] = 0;
  FOR(u, 1, n) cin >> c[u];
  FOR(i, 0, m) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].PB({v, w});
    g[v].PB({u, w});
  }
  pq.push({0, 0, 1});
  while (!pq.empty()) {
    auto [dist, pv, u] = pq.top();
    pq.pop();
    if (dist > dp[u] or dist == dp[u] and pv > p[u]) continue;
    st.push(u);
    for (auto [v, w]: g[u]) {
      int nDist = dist + w;
      if (nDist < dp[v] or nDist == dp[v] and u < p[v]) {
        p[v] = u;
        dp[v] = nDist;
        pq.push({nDist, p[v], v});
      }
    }
  }
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    sz[u] += c[u];
    if (p[u]) sz[p[u]] += sz[u];
  }

  LL best = 0;
  FOR(u, 2, n) {
    LL old = (LL) sz[u] * dp[u];
    LL diff = old - (LL) sz[u] * t;
    best = max(best, diff);
  }
  cout << best;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}

