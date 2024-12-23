/*
  Code by: linvg
  Created: 21.09.2024 03:48:32
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

bool is_prime(int x) {
   if (x < 2) return false;
   if (x < 4) return true;
   if (x % 2 == 0 || x % 3 == 0) return false;
   for (int i = 5; i * i <= x; i += 6) {
      if (x % i == 0 || x % (i + 2) == 0) return false;
   }
   return true;
}

void solve()
{
   int n, m, k;
   cin >> n >> m >> k;
   vector<vector<int>> a(n, vector<int>(m));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> a[i][j];
      }
   }
   vector<string> s(n);
   for (int i = 0; i < n; ++i) cin >> s[i];
   int snow = 0, nor = 0;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         if (s[i][j] == '1') {
            nor += a[i][j];
         } else {
            snow += a[i][j];
         }
      }
   }

   if (k == 1) return void (cout << "YES\n");

   vector<vector<int>> pref(n + 1, vector<int>(m + 1));  
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + (s[i-1][j-1] == '1');
      }
   }
   auto get = [&] (int x1, int y1, int x2, int y2) {
      return pref[x2][y2] - pref[x1][y2] - pref[x2][y1] + pref[x1][y1];
   }; 
   
   vector<int> storage;
   for (int i = k; i <= n; ++i) {
      for (int j = k; j <= m; ++j) {
         int x = get(i, j, i - k, j - k);
         if (2 * x == k * k) continue;
         storage.push_back(abs(2 * x - k * k));
      }
   }

   
   if (nor == snow) return void (cout << "YES\n");
   if (storage.empty()) return void (cout << "NO\n");

   sort(all(storage));
   storage.resize(unique(all(storage)) - storage.begin());
   int minus = abs(nor - snow);
   dbg(nor, snow, minus);
   dbg(storage);

   int _gcd = 0;
   for (int i = 0; i < sz(storage); ++i) {
      _gcd = gcd(_gcd, storage[i]);
   }

   if (minus % _gcd == 0) return void (cout << "YES\n");
   
   cout << "NO\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}  