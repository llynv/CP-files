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
#include "../debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int N = 211;

void solve()
{
   int n;
   cin >> n;
   vector<vector<int>> res;
   int top = N;
   vector<int> v;
   unordered_map<int, int> mp;
   vector<bitset<N>> total;
   bitset<N> cur;
   for (int i = 1; i <= n; ++i) {
      v.push_back(i);
      mp[i] = 1;
      cur[i] = 1;
   }
   total.push_back(cur);
   res.push_back(v);
   bool flag = true;
   while (true) {
      vector<int> nxt;
      bitset<N> tmp;
      for (auto &c : total) {
         tmp ^= c;
      }
      dbg(tmp);
      int start = 0;
      for (int i = 1; i <= top; ++i) {
         if (tmp[i]) {
            start = i;
            break;
         }
      }
      nxt.push_back(start);
      bitset<N> now;
      now[start] = 1;
      int cnt = 1;
      for (int i = (start == top ? 1 : start + 1); cnt <= n; (i >= top ? 1 : i + 1)) {
         if (mp[i] == 0) {
            nxt.push_back(i);
            mp[i] = 1;
            ++cnt;
            now[i] = 1;
         }
      }
      total.push_back(now);
      res.push_back(nxt);
      if (flag && tmp.count() == n) {
         flag = false;
      }
      if (!flag && tmp.count() == n) {
         break;
      }
   }
   cout << sz(res) << '\n';
   for (auto &v : res) {
      for (auto &c : v) {
         cout << c << ' ';
      }
      cout << '\n';
   }
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}