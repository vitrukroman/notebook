#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define RFOR(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define SZ(a) int(a.size())
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define F first
#define S second

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef double db;

const int MAX_N = 401;
VI dp(MAX_N, -1);
int n, K, a[MAX_N];

void solve() {
  freopen("snakes.in", "r", stdin);
  freopen("snakes.out", "w", stdout);
  cin >> n >> K;
  n++;
  dp[0] = 0;
  FOR(i, 1, n) cin >> a[i];
  FOR(k, 0, K + 1) {
    VI ndp(MAX_N, INT_MAX);
    FOR(l, k + 1, n) {
      if (dp[l - 1] == -1) continue;
      int mx = INT_MIN;
      int sum = 0;
      FOR(r, l, n) {
        sum += a[r];
        mx = max(mx, a[r]);
        ndp[r] = min(ndp[r], mx * (r - l + 1) - sum + dp[l - 1]);
      }
    }
    dp = ndp;
  }
  cout << dp[n - 1];
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
