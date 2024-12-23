
/*
  Code by: linvg
  Created: 04.10.2024 23:11:35
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
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
const int MOD = 1e9 + 7;

const int N = 1e5 + 7;
vector<int> factors[N];

void sieve() {
   for (int i = 1; i * i < N; ++i) {
      for (int j = i * i; j < N; j += i) {
         factors[j].push_back(i);
         if (j / i != i) factors[j].push_back(j / i);
      }
   }
}

void solve()
{
   int n, m;
   cin >> n >> m;
   vector<int> a(n);
   for (auto &c : a) cin >> c;
   sort(all(a));
   int total = 0, res = INF;
   int l = 0, r = 0;
   vector<int> used(m + 1);
   while (r < n) {
      dbg(l, r, total);
      int mx = a[r];
      while (r < n && total < m) {
         mx = a[r];
         for (auto &c : factors[a[r]]) {
            if (c <= m) {
               used[c]++;
               total += used[c] == 1;
            }
         }
         ++r;
      }
      while (l < r && total == m) {
         dbg(l, r, mx, total);
         res = min(res, mx - a[l]);
         for (auto &c : factors[a[l]]) {
            if (c <= m) {
               used[c]--;
               total -= used[c] == 0;
            }
         }
         ++l;
      }
   }
   cout << (res == INF ? -1 : res) << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   sieve();
   
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}