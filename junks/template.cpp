/*
  Code by: linvg
*/

#include <bits/stdc++.h>
#include <functional>

using namespace std;

// #define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
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

const int INF = 1e9;

unsigned int bit_ceil(unsigned int n) {
   unsigned int x = 1;
   while (x < (unsigned int)(n)) x *= 2;
   return x;
}

int countr_zero(unsigned int n) {
#ifdef _MSC_VER
   unsigned long index;
   _BitScanForward(&index, n);
   return index;
#else
   return __builtin_ctz(n);
#endif
}

constexpr int countr_zero_constexpr(unsigned int n) {
   int x = 0;
   while (!(n & (1 << x))) x++;
   return x;
}

template <class S, S(*op)(S, S), S(*e)()> struct segtree {
public:
   segtree() : segtree(0) {}
   explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
   explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
      size = (int)bit_ceil((unsigned int)(_n));
      log = countr_zero((unsigned int)size);
      d = std::vector<S>(2 * size, e());
      for (int i = 0; i < _n; i++) d[size + i] = v[i];
      for (int i = size - 1; i >= 1; i--) {
         update(i);
      }
   }

   void set(int p, S x) {
      assert(0 <= p && p < _n);
      p += size;
      d[p] = x;
      for (int i = 1; i <= log; i++) update(p >> i);
   }

   S get(int p) const {
      assert(0 <= p && p < _n);
      return d[p + size];
   }

   S prod(int l, int r) const {
      assert(0 <= l && l <= r && r <= _n);
      S sml = e(), smr = e();
      l += size;
      r += size;

      while (l < r) {
         if (l & 1) sml = op(sml, d[l++]);
         if (r & 1) smr = op(d[--r], smr);
         l >>= 1;
         r >>= 1;
      }
      return op(sml, smr);
   }

   S all_prod() const { return d[1]; }

   template <bool (*f)(S)> int max_right(int l) const {
      return max_right(l, [](S x) { return f(x); });
   }
   template <class F> int max_right(int l, F f) const {
      assert(0 <= l && l <= _n);
      assert(f(e()));
      if (l == _n) return _n;
      l += size;
      S sm = e();
      do {
         while (l % 2 == 0) l >>= 1;
         if (!f(op(sm, d[l]))) {
            while (l < size) {
               l = (2 * l);
               if (f(op(sm, d[l]))) {
                  sm = op(sm, d[l]);
                  l++;
               }
            }
            return l - size;
         }
         sm = op(sm, d[l]);
         l++;
      } while ((l & -l) != l);
      return _n;
   }

   template <bool (*f)(S)> int min_left(int r) const {
      return min_left(r, [](S x) { return f(x); });
   }
   template <class F> int min_left(int r, F f) const {
      assert(0 <= r && r <= _n);
      assert(f(e()));
      if (r == 0) return 0;
      r += size;
      S sm = e();
      do {
         r--;
         while (r > 1 && (r % 2)) r >>= 1;
         if (!f(op(d[r], sm))) {
            while (r < size) {
               r = (2 * r + 1);
               if (f(op(d[r], sm))) {
                  sm = op(d[r], sm);
                  r--;
               }
            }
            return r + 1 - size;
         }
         sm = op(d[r], sm);
      } while ((r & -r) != r);
      return 0;
   }

private:
   int _n, size, log;
   std::vector<S> d;

   void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

// op: operation (associative, commutative) op(a, b) => return value of combining a and b
// e: identity element of op

int op(int a, int b) {
   return max(a, b);
}

int e() {
   return -1;
}

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   int q;
   cin >> q;
   while (q--) {
      int l, r;
      cin >> l >> r;
      cout << st.prod(l, r) << '\n';
   }
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