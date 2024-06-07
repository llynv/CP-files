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
#define LOCAL
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;

void solve()
{
   int n;
   cin >> n;
   std::vector<int> a(n);
   for (auto &c : a) cin >> c;

   int res = 0;
   vector<int> config(n), vis(n);
   for (int i = 0; i < n; ++i) {
      unordered_map<int, int> cnt;
      int nums = 0, tmpPos = -1;
      bool unique = true;
      int trash = -1;
      for (int j = i; j < n; ++j) {
         if (config[j]) {
            cnt[trash--] = true;
            continue;
         }
         if (cnt[a[j]]) {
            nums += (cnt[a[j]] == 1);
            if (a[j] == a[j-1] && tmpPos == -1) {
               tmpPos = j;
            }
         }
         if (nums == sz(cnt)) {
            vis[j] = i + 1;
            config[j] = true;
            unique = false;
            break;
         }
         cnt[a[j]]++;
      }
      if (unique) continue;
      dbg(i, config);
      // res ++;
   }
   dbg(config);
   for (int i = 1; i < n; ++i) vis[i] = max(vis[i], vis[i-1]);
   unordered_map<int, int> mp;
   for (auto &c : vis) {
      if (!c) continue;
      mp[c] = 1;
   }
   dbg(vis);
   cout << sz(mp) << "\n";
   dbg("END\n");
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