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

const int mod = 1e9 + 7;
const int MAX = 500;
array<array<int, MAX>, MAX> a;

const int add(int a, int b) {
  int c = a + b;
  if (c >= mod) c -= mod;
  return c;
}


void solve() {
  int n;
  cin >> n;
  FOR(i, 0, n) {
    string s;
    cin >> s;
    FOR(j, 0, n) a[i][j] = s[j] - 'A';
  }
  vector<VI> dp(MAX, VI(MAX));
  if (a[0][0] == a[n - 1][n - 1]) dp[0][n - 1] = 1;
  FOR(d1, 1, n - 1) {
    vector<VI> ndp(MAX, VI(MAX));
    RFOR(r1, d1 + 1, 0) {
      int c1 = d1 - r1;
      RFOR (r2, n, n - d1 - 1) {
        int c2 = n * 2 - 2 - d1 - r2;
        if (a[r1][c1] != a[r2][c2]) continue;
        if (c1 > 0 and c2 < n - 1) ndp[r1][r2] = add(ndp[r1][r2], dp[r1][r2]);
        if (r1 > 0 and r2 < n - 1) ndp[r1][r2] = add(ndp[r1][r2], dp[r1 - 1][r2 + 1]);
        if (c1 > 0 and r2 < n - 1) ndp[r1][r2] = add(ndp[r1][r2], dp[r1][r2 + 1]);
        if (r1 > 0 and c2 < n - 1) ndp[r1][r2] = add(ndp[r1][r2], dp[r1 - 1][r2]);
      }
    }
    dp = ndp;
  }
  int ans = 0;
  RFOR(r, n, 0) {
    ans = add(ans, dp[r][r]);
    if (r > 0 and r < n - 1) ans = add(ans, dp[r - 1][r + 1]);
    if (r < n - 1) ans = add(ans, dp[r][r + 1]);
    if (r > 0) ans = add(ans, dp[r - 1][r]);
  }
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
