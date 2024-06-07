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

const int INF = 1e12;
const int N = 2011;

struct Circle {
   int x, y, r;
};

vector<int> adj[N];
int vst[N];

void dfs (int u, vector<int> &res) {
   vst[u] = 1;
   for (int v : adj[u]) {
      if (!vst[v]) {
         dfs(v, res);
      }
   }
   res.push_back(u);
}

void solve()
{
   int n;
   cin >> n;
   vector<Circle> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i].x >> a[i].y >> a[i].r;
   }

   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         if (i == j) continue;
         int dx = abs(a[i].x - a[j].x);
         int dy = abs(a[i].y - a[j].y);
         int d = dx * dx + dy * dy;
         int r = a[i].r + a[j].r;
         // dbg(i, j, d, r * r);
         if (d == r * r) {
            adj[i].push_back(j);
         }
      }
   }

   vector<vector<int>> collapse;   

   for (int i = 0; i < n; ++i) {
      if (!vst[i]) {
         memset(vst, 0, sizeof(vst));
         vector<int> res;
         dfs(i, res);
         collapse.push_back(res);
      }
   }

   vector<vector<int>> dist(n, vector<int>(n, INF));

   for (int i = 0; i < n; ++i) {
      queue<int> q;
      q.push(i);
      dist[i][i] = 0;
      while (!q.empty()) {
         int u = q.front();
         q.pop();
         for (int v : adj[u]) {
            if (dist[i][v] == INF) {
               dist[i][v] = dist[i][u] + 1;
               q.push(v);
            }
         }
      }
   }

   vector<int> tag(n, 0); 
   for (auto &joins : collapse) {
      int maxOdd = 0;
      int maxFour = 0;
      for (int i = 0; i < joins.size(); ++i) {
         tag.assign(n, 0);
         int tmp = 1;
         tag[joins[i]] = 1;
         for (int j = 0; j < joins.size(); ++j) {
            if (i == j) continue;
            if (dist[joins[i]][joins[j]] % 2 == 0) {
               tag[joins[j]] = 1;
               ++tmp;
            }
         }
         bool ok = true;
         for (auto &j : joins) {
            for (auto nxt : adj[j]) {
               if (tag[j] == tag[nxt]) {
                  ok = false;
                  break;
               }
            }
            if (!ok) break;
         }

         if (ok) {
            maxOdd = max({maxOdd, tmp, sz(joins) - tmp});
         }
      }
      int des = maxOdd;
      int inc = sz(joins) - des;
      if (des > inc) {
         return void (cout << "YES\n");
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