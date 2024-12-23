
/*
  Code by: linvg
  Created: 14.10.2024 11:43:57
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
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

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int infinity = (int)1e9 + 42;
const int64_t llInfinity = (int64_t)1e18 + 256;
const int module = (int)1e9 + 7; 
const long double eps = 1e-8;
 
mt19937_64 randGen(std::chrono::_V2::system_clock().now().time_since_epoch().count());
 
inline void raiseError(string errorCode) {
   cerr << "Error : " << errorCode << endl;
   exit(42);
}
 
inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
   if (pow == 0) {
      return 0;
   }
   int hpow = 1 << (pow-1);
   int seg = (x < hpow) ? (
      (y < hpow) ? 0 : 3
   ) : (
      (y < hpow) ? 1 : 2
   );
   seg = (seg + rotate) & 3;
   const int rotateDelta[4] = {3, 0, 0, 1};
   int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
   int nrot = (rotate + rotateDelta[seg]) & 3;
   int64_t subSquareSize = int64_t(1) << (2*pow - 2);
   int64_t ans = seg * subSquareSize;
   int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
   ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
   return ans;
}
 
struct Query {
   int l, r, idx;
   int64_t ord;
 
   inline void calcOrder() {
      ord = gilbertOrder(l, r, 21, 0);
   }
};
 
inline bool operator<(const Query &a, const Query &b) {
   return a.ord < b.ord;
}

void solve()
{
   int n, m, k;
   cin >> n >> m >> k;
   vector<int> a(n);
   for (auto &c : a) cin >> c;
   vector<Query
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}