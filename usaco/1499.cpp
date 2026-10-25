#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)

typedef vector<int> VI;

const int MAX = 16;
const int MAX_MASK = 1 << MAX;
int n, m, adj[MAX], inside[MAX_MASK];
VI dp(MAX_MASK, INT_MAX);

void solve() {
  cin >> n >> m;
  FOR(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u] |= 1 << v;
    adj[v] |= 1 << u;
  }
  FOR(mask, 1, MAX_MASK) {
    int u = __builtin_ctz(mask);
    int pmask = mask ^ (1 << u);
    inside[mask] = inside[pmask] + __builtin_popcount(adj[u] & mask);
  }
  dp[0] = 0;
  FOR(mask, 1, 1 << n) {
    for (int subMask = mask; subMask > 0; subMask = (subMask - 1) & mask) {
      int subSet = mask - subMask;
      int szSubMask = __builtin_popcount(subMask);
      int szSubSet = __builtin_popcount(subSet);
      dp[mask] = min(dp[mask],
                     inside[subMask] + szSubMask * szSubSet - (inside[mask] - inside[subMask] - inside[subSet]) +
                     dp[subSet]);
    }
  }
  cout << dp[(1 << n) - 1];
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
