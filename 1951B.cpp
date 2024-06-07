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


template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

// #define DBG

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;

void solve()
{
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   for (auto &c : a) cin >> c;
   int pos = 0, mx = -1;
   int init = 0;
   for (int i = 1; i < n; ++i) {
      if (i == k-1) {
         if (a[0] > a[k-1]) break;
         init++;
         continue;
      }
      if (a[i] > a[k-1]) break;
      init++;
   }
   for (int i = 0; i < k-1; ++i) {
      if (a[i] > a[k-1]) {
         swap(a[i], a[k-1]);
         pos = i;
         break;
      }
      mx = max(mx, a[i]);
   }
   dbg(pos, mx);
   int res = (mx != -1 && a[pos] > mx ? 1 : 0);
   for (int i = pos+1; i < n; ++i) {
      if (a[i] > a[pos]) break;
      res++;
   }
   cout << max(res, init) << '\n';
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