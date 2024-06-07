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
   string s;
   cin >> s;
   int cnt = count(all(s), '0');
   if (2 * cnt != sz(s)) return void (cout << "-1\n");
   int i = 0;
   vector<int> res;
   while (i < sz(s)) {
      if (s[i] == s[sz(s) - i - 1]) {
         if (s[i] == '1') {
            res.pb(i);
            s.insert(s.begin() + i, '1');
            s.insert(s.begin() + i, '0');
         } else {
            res.pb(sz(s)-i);
            s.insert(s.begin() + sz(s) - i, '0');
            s.insert(s.begin() + sz(s) - i, '1');
         }
      }
      ++i;
   }
   // cerr << s << "\n";
   cout << sz(res) << "\n";
   for (auto x : res) cout << x << " ";
   cout << "\n";
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