
/*
  Code by: linvg
  Created: 02.11.2024 16:11:36
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T gcd(initializer_list<T> __l) { int a = 0; for (auto x : __l) { a = gcd(a, x); } return a; }
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


struct LCA
{
   vector<int> d;
   vector<vector<int>> f, adj;

   LCA(int n) : adj(n + 1), d(n + 1), f(n + 1, vector<int>(20)) {}

   LCA& addEdge(int u, int v)
   {
      adj[u].push_back(v);
      adj[v].push_back(u);
      return *this;
   }

   void dfs(int u, int p)
   {
      f[u][0] = p;
      for (int i = 1; i < 20; ++i)
      {
         f[u][i] = f[f[u][i - 1]][i - 1];
      }
      for (int v : adj[u])
      {
         if (v == p)
            continue;
         d[v] = d[u] + 1;
         dfs(v, u);
      }
   }

   int lca(int u, int v)
   {
      if (d[u] < d[v])
         swap(u, v);
      for (int i = 19; i >= 0; --i)
      {
         if (d[f[u][i]] >= d[v])
            u = f[u][i];
      }
      if (u == v)
         return u;
      for (int i = 19; i >= 0; --i)
      {
         if (f[u][i] != f[v][i])
         {
            u = f[u][i];
            v = f[v][i];
         }
      }
      return f[u][0];
   }

   int dist(int u, int v)
   {
      return d[u] + d[v] - 2 * d[lca(u, v)];
   }
};

const long double M_PI = 3.14159265358979323846;

void fft(vector<complex<long double>>& a)
{
   int n = a.size();
   if (n == 1)
      return;
   vector<complex<long double>> a0(n / 2), a1(n / 2);
   for (int i = 0; i < n / 2; ++i)
   {
      a0[i] = a[i * 2];
      a1[i] = a[i * 2 + 1];
   }
   fft(a0);
   fft(a1);
   long double ang = 2 * M_PI / n;
   complex<long double> w(1), wn(cos(ang), sin(ang));
   for (int i = 0; i < n / 2; ++i)
   {
      a[i] = a0[i] + w * a1[i];
      a[i + n / 2] = a0[i] - w * a1[i];
      w *= wn;
   }
}

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for (auto& c : a) cin >> c;
   LCA lca(n);
   for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      lca.addEdge(u, v);
   }
   lca.dfs(1, 0);
   vector<vector<long double>> A(n);
   for (int i = 0; i < n; ++i) {
      for (int j = 1; j <= n; ++j) {
         A[i].push_back(lca.dist(i + 1, j));
      }
      A[i].push_back(a[i]);
   }
   // Perform FFT on each row of A
   for (int i = 0; i < n; ++i) {
      int m = A[i].size();
      vector<complex<long double>> poly(m);
      for (int j = 0; j < m; ++j) {
         poly[j] = A[i][j];
      }
      // Perform FFT
      fft(poly);
      // Store the result back in A
      for (int j = 0; j < m; ++j) {
         A[i][j] = poly[j].real();
      }
   }
   // print the result
   for (int i = 0; i < n; ++i) {
      cout << fixed << setprecision(6) << A[i][n] << ' ';
   }
   cout << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}