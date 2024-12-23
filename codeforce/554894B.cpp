/*
  Code by: linvg
  Created: 02.10.2024 17:14:32
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

void solve()
{
   int n, U, R, D, L;
   cin >> n >> U >> R >> D >> L;
   if ((U == n || D == n) && (L == 0 || R == 0)) return void (cout << "NO\n");
   if ((L == n || R == n) && (U == 0 || D == 0)) return void (cout << "NO\n");
   if ((U == n && D == n) && (L <= 1 || R <= 1)) return void (cout << "NO\n");
   if ((L == n && R == n) && (U <= 1 || D <= 1)) return void (cout << "NO\n");
   if ((U == n && D == n - 1) || (U == n - 1 && D == n)) {
      if (L <= 1 && R <= 1) return void (cout << "NO\n");
   }
   if ((L == n && R == n - 1) || (L == n - 1 && R == n)) {
      if (U <= 1 && D <= 1) return void (cout << "NO\n");
   }
   if ((U == n - 1 || D == n - 1) && (L == 0 && R == 0)) return void (cout << "NO\n");
   if ((L == n - 1 || R == n - 1) && (U == 0 && D == 0)) return void (cout << "NO\n");
   if ((U == n - 1 && D == n - 1) && (L + R < 2)) return void (cout << "NO\n");
   if ((L == n - 1 && R == n - 1) && (U + D < 2)) return void (cout << "NO\n");
   cout << "YES\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}