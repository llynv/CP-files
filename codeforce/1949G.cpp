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
   int n;
   cin >> n;
   vector<char> valid(n), order(n);
   for (auto& x : valid) cin >> x;
   vector<int> blank;
   vector<vector<int>> wrong(3);
   unordered_map<char, int> id;
   id['C'] = 0;
   id['M'] = 1;
   id['-'] = 2;
   for (int i = 0; i < n; ++i) {
      cin >> order[i];
      if (order[i] != valid[i]) {
         if (order[i] == '-') wrong[id[valid[i]]].insert(wrong[id[valid[i]]].begin(), i);
         else wrong[id[valid[i]]].push_back(i);
         if (valid[i] == '-') blank.push_back(i);
      }
   }

   vector<string> scoops;

   // dbg(scoops);

   int start = -1;

   for (auto& pos : blank) {
      start = -1;
      while (true) {
         char teacher = (start == -1 ? order[pos] : order[start]);
         // dbg(teacher);
         if (sz(wrong[id[teacher]]) == 0) break;
         int target = wrong[id[teacher]].back();
         // dbg(wrong[id[teacher]]);
         wrong[id[teacher]].pop_back();
         if (start == -1) {
            scoops.push_back("DRIVE " + to_string(pos + 1));
            scoops.push_back("PICKUP");
            scoops.push_back("DRIVE " + to_string(target + 1));
            scoops.push_back("DROPOFF");
         }
         else {
            scoops.push_back("PICKUP");
            scoops.push_back("DRIVE " + to_string(target + 1));
            scoops.push_back("DROPOFF");
         }
         start = target;
         if (order[target] == '-') break;
         // dbg(wrong[id[order[target]]], order[target]);
         // dbg(target);
      }
   }


   // dbg(scoops);
   cout << sz(scoops) << '\n';
   for (auto& scoop : scoops) cout << scoop << '\n';
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