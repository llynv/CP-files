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
#include "../debug.h"
#endif

const int INF = 0x3f3f3f3f3f;

struct Child
{
   int mask = -1, roll, choose;
   string path;
};


void solve()
{
   int n;
   cin >> n;
   string a;
   for (int i = 0; i < 9; ++i) {
      char c;
      cin >> c;
      a += c;
   }

   const int dir[4][4] = {
      {0, 1, 3, 4},
      {1, 2, 4, 5},
      {3, 4, 6, 7},
      {4, 5, 7, 8}
   };

   int corner[] = { 0, 2, 6, 8 };

   unordered_map<string, int> dist;

   dist[a] = 0;

   string res = "000000000";

   auto getBest = [&] (pair<string, int> x, pair<string, int> y) -> bool {
      int r1 = 0, r2 = 0;
      for (int i = 0; i < 9; ++i) {
         r1 += (x.fi[i]-'0');
         r2 += (y.fi[i]-'0');
      }
      return r1 > r2;
   };

   priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(getBest)> q(getBest);
   
   unordered_map<string, Child> par;

   q.push({ a, 0 });
   int cnt = 1000;
   while (!q.empty() && cnt --> 0) {
      auto [v, d] = q.top();
      q.pop();

      for (int mask = 0; mask < (1 << 4); ++mask) {
         vector<int> vis(9, 1);
         for (int i = 0; i < 4; ++i) {
            if (mask >> i & 1) {
               for (int j = 0; j < 4; ++j) {
                  vis[dir[i][j]] = 0;
               }
            }
         }
         for (int i = 1; i < n; ++i) {
            for (int choose = 0; choose < 4; ++choose) {
               string new_v = v;
               if (mask >> choose & 1) {
                  for (int j = 0; j < 9; ++j) {
                     if (!vis[j]) {
                        new_v[j] = ((v[j]-'0' + i) % n)+'0';
                     }
                  }
               } else {
                  new_v[corner[choose]] = ((v[corner[choose]]-'0' + i) % n)+'0';
               }

               if (dist.find(new_v) == dist.end()) {
                  dist[new_v] = d + 1;
                  par[new_v] = { mask, i, choose, v };
                  if (new_v == res) {
                     cout << "YES\n";
                     cout << d+1 << '\n';
                     vector<string> ans;
                     while (par[new_v].mask != -1) {
                        string path = "";
                        auto [mask, roll, choose, prev] = par[new_v];
                        for (int j = 0; j < 4; ++j) {
                           path += to_string(((mask >> j & 1) ? 1 : 0)) + ' ';
                        }
                        path += to_string(corner[choose]+1) + ' ';
                        path += to_string(roll);
                        ans.push_back(path);
                        new_v = prev;
                     }
                     reverse(all(ans));
                     for (auto &c : ans) {
                        cout << c << '\n';
                     }
                     return;
                  }
                  q.push({ new_v, d + 1 });
               }
            }
         }
      }
   }

   cout << "NO\n";
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