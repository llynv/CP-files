/*
  Code by: linvg
*/

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

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;

void solve()
{
   int l, r;
   cin >> l >> r;

   auto count = [&](int x) -> int {
      if (x == 0) return 0ll;
      int len = (to_string(x).size() + 1) / 2;
      string r1 = to_string(x).substr(0, len);
      string r2 = to_string(x).substr(len - (to_string(x).size() % 2 != 0));
      reverse(all(r2));
      r1 = min(r1, r2);
      if (r1[0] == '0') {
         if (r1.size() == 1) r1 = "0";
         else r1 = string(sz(r1) - 1, '9');
      }
      dbg(r1, r2);
      int ans = stoll(r1);
      int num = (int) ceil(pow(10, to_string(x).size() - 1)) - 1;
      while (num) {
         int l = (to_string(num).size() + 1) / 2;
         string rr = to_string(num).substr(0, l);
         ans += stoll(rr);
         num /= 10;
      }
      return ans;
   };

   cout << count(r) - count(l-1) << '\n';
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