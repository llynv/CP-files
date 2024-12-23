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

#ifdef DBG
#include "debug.h"
#else
#define dbg(...)
#endif

const int INF = 0x3f3f3f3f3f;

void solve()
{
   int n, m, k;
   cin >> n >> m >> k;
   vector<int> a(n), b(m);
   for (auto &c : a) cin >> c;
   for (auto &c : b) cin >> c;
   sort(all(a));
   sort(all(b));
   map<int, int> mp;
   for (int i = 0; i < n and a[i] <= k; ++i) {
      mp[a[i]] = 1;
   }
   vector<int> res;
   map<int, int> mp2;
   for (int i = 0; i < m and b[i] <= k; ++i) {
      if (!mp2[b[i]] and !mp[b[i]] and sz(res) < k / 2) {
         res.pb(b[i]);
         mp2[b[i]] = 1;
      }
   }
   for (int i = 0; i < m and b[i] <= k; ++i) {
      if (sz(res) < k / 2 and !mp2[b[i]]) {
         res.pb(b[i]);
         mp2[b[i]] = 1;
      }
   }
   dbg(res);
   if (sz(res) != k / 2) return void(cout << "NO" << '\n');
   for (int i = 0; i < n and a[i] <= k; ++i) {
      if (!mp2[a[i]] and sz(res) < k) {
         res.pb(a[i]);
         mp2[a[i]] = 1;
      }
   }
   dbg(res);
   cout << (sz(res) == k ? "YES" : "NO") << '\n';
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