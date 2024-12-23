
/*
  Code by: linvg
  Created: 11.10.2024 16:31:32
*/

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T gcd(initializer_list<T> __l) { int a = 0; for (auto x : __l) { a = gcd(a, x); } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

// #define DBG

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int MOD = 1e9 + 7;

const int N = 1e6 + 7;

#define MAX 10000010

vector <int> f[MAX];

void gen(bool make_sorted = false) { /// sorting makes it 2x slower
   short sp[MAX];
   int i, j, k, c, l, v, lp[MAX];

   sp[1] = lp[1] = 1;
   for (i = 4; i < MAX; i++, i++) sp[i] = 2;

   for (i = 3; i * i < MAX; i += 2) {
      for (j = i * i; j < MAX && !sp[i]; j += 2 * i) {
         if (!sp[j]) sp[j] = i;
      }
   }

   for (i = 2; i < MAX; i++) {
      if (!sp[i]) lp[i] = i;
      else lp[i] = max((int)sp[i], lp[i / sp[i]]);
   }

   f[1].push_back(1);
   for (i = 2; i < MAX; i++) {
      c = 1, l = 0;
      for (k = i; k > 1 && lp[k] == lp[i]; c++) k /= lp[k];
      f[i].resize(c * f[k].size());

      for (v = 1, j = 0; j < c; j++, v *= lp[i]) {
         for (const auto d : f[k]) {
            f[i][l++] = d * v;
         }
      }
      if (make_sorted) sort(f[i].begin(), f[i].end());
   }
}

array<int, 2> min_val[MAX];
int a[N];

void solve()
{
   int n;
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      dbg(a[i], f[a[i]]);
      for (auto u : f[a[i]]) {
         if (min_val[u][0] == 0) {
            min_val[u][0] = i;
         } else if (min_val[u][1] == 0) {
            min_val[u][1] = i;
         } else {
            if (a[min_val[u][0]] > a[min_val[u][1]]) {
               if (a[i] < a[min_val[u][0]]) {
                  min_val[u][0] = i;
               }
            } else {
               if (a[i] < a[min_val[u][1]]) {
                  min_val[u][1] = i;
               }
            }
         }
      }
   }

   long long ans = LONG_LONG_MAX;
   int r_x = 0, r_y = 0;
   int tt = 0;

   for (int i = 1; i < MAX; ++i) {
      if (min_val[i][1] == 0) continue;
      if (ans > 1LL * a[min_val[i][0]] * a[min_val[i][1]] / i) {
         ans = 1LL * a[min_val[i][0]] * a[min_val[i][1]] / i;
         r_x = min_val[i][0];
         r_y = min_val[i][1];
      }
   }

   if (r_x > r_y) swap(r_x, r_y);
   cout << r_x << ' ' << r_y << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   clock_t start = clock();

   gen();
   solve();

   cerr << "Time elapsed: " << (double)(clock() - start) / CLOCKS_PER_SEC << '\n';
   return 0;
}