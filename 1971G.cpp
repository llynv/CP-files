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

const int INF = 0x3f3f3f3f3f;

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n); 
   for (auto &x : a) cin >> x;
   unordered_map<int, pair<vector<int>, vector<int>>> mp;
   for (int i = 0; i < n; ++i) {
      int id = (a[i] >> 2) << 2;
      mp[id].first.pb(i);
      mp[id].second.pb(a[i]);
   }
   vector<int> ans(n, 0);
   for (auto &x : mp) {
      auto &v = x.second.first;
      auto &w = x.second.second;
      sort(all(w));
      // dbg(v, w);
      int m = sz(v);
      for (int i = 0; i < m; ++i) {
         ans[v[i]] = w[i];
      }
   }
   for (auto &x : ans) cout << x << ' ';
   cout << '\n';
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