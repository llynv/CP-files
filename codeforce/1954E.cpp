
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
const int N = 1e5 + 7;

void add(int i, int x, vector<int> &fw) {
   for (; i < N; i += i & -i) {
      fw[i] += x;
   }
}

int get(int i, vector<int> &fw) {
   int res = 0;
   for (; i; i -= i & -i) {
      res += fw[i];
   }
   return res;
}

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for (auto &c : a) cin >> c;
   int mx = *max_element(all(a));
   a.insert(a.begin(), 0);
   a.push_back(0);
   vector<vector<int>> pos(mx+1);
   for (int i = 1; i <= n; ++i) {
      pos[a[i]].push_back(i);
   }
   int joins = 0;
   vector<int> res(mx+1);
   for (int i = mx; i >= 1 ; --i) {
      for (auto &c : pos[i]) {
         a[c] -= i;
      }
      for (auto &c : pos[i]) {
         if (a[c-1] && a[c+1]) joins++;
      }
      res[i] += joins;
   }
   dbg(res);
}

int32_t main() {

#ifdef ONLINE_JUDGE
#else
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   auto time = clock();
   solve();
   cerr << "Time elapsed: " << (double)(clock() - time) / CLOCKS_PER_SEC << "s\n";
   return 0;
}