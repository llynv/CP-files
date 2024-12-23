/*
  Code by: linvg
  Created: 26.11.2024 22:13:30
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

const int dx[] = { 0, 1 };
const int dy[] = { 1, 0 };

struct custom_hash {
   size_t operator()(uint64_t x) const {
      static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
      x ^= FIXED_RANDOM;
      return x ^ (x >> 16);
   }
};

void solve()
{
   int n, a, b;
   cin >> n >> a >> b;

   int save_x, save_y;
   for (int i = 1; i <= n; ++i) {
      if (__gcd(i, a) == 1) save_x = i;
      if (__gcd(i, b) == 1) save_y = i;
   }
   int ans = 0;
   for (int i = 1; i <= save_x; ++i) {
      ans += 1;
      ans += __gcd(i, a);
   }
   for (int i = 2; i <= save_y; ++i) {
      ans += 1;
      ans += __gcd(i, b);
   }
   priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
   unordered_map<int, int, custom_hash> dist;
   q.push({ 0, save_x, save_y });
   dist[save_x * n + save_y] = 0;
   while (!q.empty()) {
      auto [d, x, y] = q.top();
      q.pop();
      if (x == n && y == n) break;
      if (dist[x * n + y] < d) continue;
      for (int i = 0; i < 2; ++i) {
         int nx = dx[i] + x;
         int ny = dy[i] + y;
         if (nx > n || ny > n) continue;
         if (dist.count(nx * n + ny) == 0 || dist[nx * n + ny] > d + gcd(nx, a) + gcd(ny, b)) {
            dist[nx * n + ny] = d + gcd(nx, a) + gcd(ny, b);
            q.push({ d + gcd(nx, a) + gcd(ny, b), nx, ny });
         }
      }
   }
   cout << ans + dist[n * n + n] << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}