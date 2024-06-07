/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)

string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

// #define DBG

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int N = 1e6 + 7;

struct Fenwick
{
   vector<int> fw;
   Fenwick() {
      fw.assign(N, 0);
   }
   void add(int x, int v) {
      for (; x < N; x += x & -x) fw[x] += v;
   }
   int get(int x) {
      int res = 0;
      for (; x > 0; x -= x & -x) res += fw[x];
      return res;
   }
   int get(int l, int r) {
      return get(r) - get(l-1);
   }
};

void solve()
{
   Fenwick fenwick;

   int n, q;
   cin >> n >> q;
   vector<int> a(n);
   vector<int> pos(n+1);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      pos[a[i]] = i+1;
   }
   vector<vector<ii>> queries(n+1);
   for (int i = 0; i < q; ++i) {
      int l, r;
      cin >> l >> r;
      queries[l].push_back({r, i});
   }
   vector<int> dp(n+1), ans(n);
   for (int i = n; i >= 1; --i) {
      for (int x = a[i-1]; x <= n; x += a[i]) dp[x] = 0;
      dp[a[i-1]] = 1;
      for (int x = a[i-1]; x <= n; x += a[i]) {
         dbg(x, dp[x], pos[x]);
         fenwick.add(pos[x], dp[x]);
         for (int y = 2*x; y <= n; y += x) {
            if (pos[y] >= pos[x]) continue; 
            dp[y] += dp[x];
         }
      }
      for (auto [r, idx] : queries[i]) {
         ans[idx] += fenwick.get(r);
      }
   }
   for (int i = 0; i < q; ++i) {
      cout << ans[i] << " \n"[i == q-1];
   }
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}