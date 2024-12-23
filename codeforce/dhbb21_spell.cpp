
/*
  Code by: linvg
  Created: 23.10.2024 18:31:40
*/

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T gcd(initializer_list<T> __l) { int a = 0; for (auto x : __l) { a = gcd(a, x); } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

const int INF = 2e9;
const int MOD = 1e9 + 7;

void solve()
{
   int n, m, k;
   cin >> n >> m >> k;
   vector<vector<char>> a(n, vector<char>(m));
   vector<char> s(k + 1);
   for (int i = 1; i <= k; ++i) cin >> s[i];
   vector<vector<pair<int, int>>> pos(26);
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> a[i][j];
         pos[a[i][j] - 'A'].push_back({ i, j });
      }
   }
   vector<vector<int>> dp(k + 1);
   for (int i = 1; i <= k; ++i) {
      dp[i].assign(pos[s[i] - 'A'].size(), (i == 1 ? 1 : INF));
   }
   for (int i = 2; i <= k; ++i) {
      for (int j = 0; j < sz(pos[s[i] - 'A']); ++j) {
         if (s[i] == s[i - 1]) {
            
         }

         for (int l = 0; l < sz(pos[s[i - 1] - 'A']); ++l) {
            dp[i][j] = min(dp[i][j], dp[i - 1][l] + abs(pos[s[i] - 'A'][j].first - pos[s[i - 1] - 'A'][l].first) + abs(pos[s[i] - 'A'][j].second - pos[s[i - 1] - 'A'][l].second));
         }
      }
   }
   cout << *min_element(all(dp[k])) << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}