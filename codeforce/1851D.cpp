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

#ifdef DBG
#include "debug.h"
#else
#define dbg(...)
#endif

const int INF = 0x3f3f3f3f3f;

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n - 1);
   for (auto& c : a) cin >> c;
   vector<bool> used(n + 1);
   bool isDup = false;
   int dup = 0;
   int total = n * (n + 1) / 2, cnt = 0;
   if (a[0] > n) {
      isDup = true;
      dup = a[0];
   } else {
      total -= a[0];
      used[a[0]] = true;
      cnt++;
   }
   for (int i = 1; i < n - 1; ++i) {
      if (a[i] - a[i-1] > n) {
         if (isDup) return void(cout << "NO\n");
         isDup = true;
         dup = a[i] - a[i-1];
         continue;
      }
      if (used[a[i] - a[i-1]]) {
         if (isDup) return void(cout << "NO\n");
         isDup = true;
         dup = a[i] - a[i-1];
         continue;
      }
      total -= a[i] - a[i-1];
      used[a[i] - a[i-1]] = true;
      cnt++;
   }
   if (cnt < n - 2) return void(cout << "NO\n");
   // dbg(dup, a);
   if (cnt == n-1) return void(cout << (total <= n && total >= 1 && !used[total] ? "YES\n" : "NO\n"));
   for (int i = 1; i <= n; ++i) {
      if (i == dup-i) continue;
      if (!used[i] && dup - i <= n && dup - i >= 1 && !used[dup - i]) return void(cout << "YES\n");
   }
   cout << "NO\n";
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