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
   vector<int> a(n);
   vector<int> vals;
   for (auto &c : a) {
      cin >> c;
      vals.pb(c);
   }
   int mx = max_element(all(a)) - a.begin();
   sort(all(vals));
   vector<ii> step;
   for (int i = 1; i < n; ++i) {
      if (a[i] < a[i-1]) {
         int dist = abs(a[i] - a[i-1]) / a[mx];
         int pos = lower_bound(all(vals), abs(a[i] - a[i-1])) - vals.begin();
         if (pos == sz(vals)) pos--;
         if (dist == 0) {
            a[i] += vals[pos];
            step.push_back({i+1, pos+1});
         } else {
            if (abs(a[i] - a[i-1]) % a[mx] == 0) {
               a[i] += a[mx] * dist;
               for (int j = 0; j < dist; ++j) {
                  step.push_back({i+1, mx+1});
               }
               continue;   
            }
            a[i] += a[mx] * (dist - 1) + vals[pos];
            for (int j = 0; j < dist-1; ++j) {
               step.push_back({i+1, mx+1});
            }
            step.push_back({i+1, pos+1});
         }
      }
   }

   for (auto &c : a) cerr << c << ' ';
   cerr << '\n';

   cout << sz(step) << '\n';
   for (auto &c : step) {
      cout << c.fi << ' ' << c.se << '\n';
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