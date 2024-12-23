/*
  Code by: linvg
  Created: 08.10.2024 10:42:52
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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

// #ifdef ONLINE_JUDGE
// #define dbg(...)
// #else
// #include "debug.h"
// #endif

const int N = 2e5 + 5;

int a[N], b[N];
int pref_gcd_a[N], suf_gcd_a[N], pref_gcd_b[N], suf_gcd_b[N];

template <typename T, typename F>
class DisjointSparseTable {
 public:
  int n;
  vector<vector<T>> mat;
  F func;
 
  DisjointSparseTable(const vector<T>& a, const F& f) : n(int(a.size())), func(f) {
    mat.push_back(a);
    for (int p = 1; (1 << p) < n; p++) {
      mat.emplace_back(n);
      for (int mid = 1 << p; mid < n; mid += 1 << (p + 1)) {
        mat[p][mid - 1] = a[mid - 1];
        for (int j = mid - 2; j >= mid - (1 << p); j--) {
          mat[p][j] = func(a[j], mat[p][j + 1]);
        }
        mat[p][mid] = a[mid];
        for (int j = mid + 1; j < min(n, mid + (1 << p)); j++) {
          mat[p][j] = func(mat[p][j - 1], a[j]);
        }
      }
    }
  }
 
  T Query(int l, int r) const {
    assert(0 <= l && l < r && r <= n);
    if (r - l == 1) {
      return mat[0][l];
    }
    int p = bit_width(unsigned(l ^ (r - 1))) - 1;
    return func(mat[p][l], mat[p][r - 1]);
  }
};

void solve()
{
   int n;
   scanf("%d", &n);
   for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
   }

   for (int i = 0; i < n; ++i) {
      scanf("%d", &b[i]);
   }

   DisjointSparseTable<int, function<int(int, int)>> dst_a(vector<int>(a, a + n), [](int x, int y) { return __gcd(x, y); });
   DisjointSparseTable<int, function<int(int, int)>> dst_b(vector<int>(a, a + n), [](int x, int y) { return __gcd(x, y); });

   suf_gcd_a[n] = suf_gcd_b[n] = 0;
   for (int i = n - 1; i >= 0; --i) {
      suf_gcd_a[i] = __gcd(suf_gcd_a[i + 1], a[i]);
      suf_gcd_b[i] = __gcd(suf_gcd_b[i + 1], b[i]);
   }
   for (int i = 0; i < n; ++i) {
      pref_gcd_a[i + 1] = __gcd(pref_gcd_a[i], a[i]);
      pref_gcd_b[i + 1] = __gcd(pref_gcd_b[i], b[i]);
   }

   long long ans = 0, cnt = 0;
   for (int i = 0; i < n; ++i) {
      int cur = i, middle_a = a[i], middle_b = b[i];
      while (cur < n) {
         middle_a = __gcd(middle_a, a[cur]);
         middle_b = __gcd(middle_b, b[cur]);
         int l = cur, r = n - 1, target = n;
         int final = gcd({ pref_gcd_a[i], suf_gcd_a[cur + 1], middle_b }) + gcd({ pref_gcd_a[i], suf_gcd_b[cur + 1], middle_a });
         while (l <= r) {
            int m = (l + r) / 2;
            // int top = get_a(i, m), bot = get_b(i, m);
            int top = dst_a.Query(i, m), bot = dst_b.Query(i, m);
            if (top != middle_a || bot != middle_b || gcd({ pref_gcd_a[i], suf_gcd_a[m + 1], bot }) + gcd({ pref_gcd_b[i], suf_gcd_b[m + 1], top }) != final) {
               r = m - 1;
            }
            else {
               target = m;
               l = m + 1;
            }
         }
         if (ans < final) {
            ans = final;
            cnt = target - cur + 1;
         }
         else if (ans == final) {
            cnt += target - cur + 1;
         }
         cur = target + 1;
      }
   }

   printf("%lld %lld\n", ans, cnt);
}


int32_t main() {
   int t;
   scanf("%d", &t);
   while (t--)
      solve();
   return 0;
}