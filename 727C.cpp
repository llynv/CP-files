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

   auto ask = [&] (int i, int j) {
      cout << "? " << i << ' ' << j << '\n';
      cout.flush();
      int x;
      cin >> x;
      return x;
   };

   vector<int> a(n+1);
   int sum1 = ask(1, 2);
   int sum2 = ask(2, 3);
   int sum3 = ask(1, 3);
   a[2] = (sum1 + sum2 - sum3) / 2;
   a[1] = sum1 - a[2];
   a[3] = sum2 - a[2];
   
   for (int i = 4; i <= n; ++i) {
      int x = ask(2, i);
      a[i] = x - a[2];
   }
   cout << "! ";
   for (int i = 1; i <= n; ++i) {
      cout << a[i] << ' ';
   }
   cout << '\n';
   cout.flush();
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
   solve();
   return 0;
}