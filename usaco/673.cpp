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

const int mod = 1e9 + 9;

int add(int a, int b) {
  int c = a + b;
  if (c >= mod) c -= mod;
  return c;
}

const int MAX = 1001;
int n, m, K, a[MAX], b[MAX];
vector<VI> ps(MAX, VI(MAX, 1));

void solve() {
  freopen("team.in", "r", stdin);
  freopen("team.out", "w", stdout);
  cin >> n >> m >> K;
  n++, m++;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, m) cin >> b[i];
  FOR(k, 0, K) {
    vector<VI> nps(MAX, VI(MAX));
    FOR(i, 1, n) FOR(j, 1, m) if (a[i] > b[j])nps[i][j] = ps[i - 1][j - 1];
    FOR(i, 1, n) {
      int row = 0;
      FOR(j, 1, m) {
        int val = nps[i][j];
        nps[i][j] = add(add(nps[i][j], nps[i - 1][j]), row);
        row = add(row, val);
      }
    }
    ps = nps;
  }
  cout << ps[n - 1][m - 1];
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

