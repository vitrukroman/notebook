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

const int MAX = 20;
const int MAX_MASK = 1 << MAX;
int n, cnt[MAX][MAX];
VI dp(MAX_MASK, INT_MAX);
unordered_map<char, int> freq;
string shortAlph = "abcfghjknopqstuvwxyz";
string others = "mildre";

int id = 0;
int pos[26];

void solve() {
  for (char c: shortAlph) pos[c - 'a'] = id++;
  string s;
  cin >> s;
  n = SZ(s);
  int eq = 0;
  FOR(i, 0, n) freq[s[i]]++;
  bool ok = true;
  for (char c: others) if (freq[c]) ok = false;
  FOR(i, 0, n - 1) {
    int c1, c2;
    if (ok) {
      c1 = pos[s[i] - 'a'];
      c2 = pos[s[i + 1] - 'a'];
    } else {
      c1 = s[i] - 'a';
      c2 = s[i + 1] - 'a';
    }
    if (c1 == c2) eq++;
    else cnt[c1][c2]++;
  }
  dp[0] = 0;
  FOR(mask, 0, MAX_MASK) {
    FOR(bit, 0, MAX) {
      if (mask & (1 << bit)) continue;
      int nMask = mask | (1 << bit);
      int tot = 0;
      FOR(bit2, 0, MAX) {
        if (nMask & (1 << bit2)) continue;
        tot += cnt[bit2][bit];
      }
      dp[nMask] = min(dp[nMask], dp[mask] + tot);
    }
  }
  cout << dp[MAX_MASK - 1] + 1 + eq;
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
