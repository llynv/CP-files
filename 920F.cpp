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

int f[N];

void sieve() {
   for (int i = 1; i * i < N; ++i) {
      for (int j = i; j * i < N; ++j) {
         f[i * j] ++;
         f[i * j] += (i != j);
      }
   }
}

const int MxN = 3e5 + 7;

int fw[MxN];

void add(int i, int x) {
   for (; i < MxN; i += i & -i) fw[i] += x;
}

int get(int i) {
   int res = 0;
   for (; i; i -= i & -i) res += fw[i];
   return res;
}

void solve()
{
   int n, q;
   cin >> n >> q;
   vector<int> a(n + 1);
   for (int i =1; i <= n; ++i) cin >> a[i];
   set<int> pos;
   for (int i = 1; i <= n; ++i) {
      if (f[a[i]] != a[i]) pos.insert(i);
      add(i, a[i]);
   }
   while (q--) {
      int t, l, r;
      cin >> t >> l >> r;
      if (t == 1) {
         auto x = pos.lower_bound(l);
         while (x != pos.end() && *x <= r) {
            int val = *x;
            add(*x, -a[*x]);
            add(*x, f[a[*x]]);
            a[*x] = f[a[*x]];
            if (f[a[*x]] == a[*x]) pos.erase(x);
            x = pos.upper_bound(val);
         }
      } else {
         cout << get(r) - get(l - 1) << '\n';
      }
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
   sieve();
   solve();
   return 0;
}