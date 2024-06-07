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
   int n, k, m;
   cin >> n >> k >> m;
   string s;
   cin >> s;
   vector<int> cnt(26);
   for (auto &c : s) cnt[c-'a']++;
  
   vector<vector<int>> pref(m+1, vector<int>(26)), suff(m+1, vector<int>(26));

   for (int i = 0; i < m; ++i) {
      for (int j = 0; j < 26; ++j) {
         pref[i+1][j] = pref[i][j];
      }
      pref[i+1][s[i]-'a']++;
   }

   for (int i = m-1; i >= 0; --i) {
      for (int j = 0; j < 26; ++j) {
         suff[i][j] = suff[i+1][j];
      }
      suff[i][s[i]-'a']++;
   }

   // dbg(pref);
  
   for (int j = 0; j < k; ++j) {
      int c = cnt[j];
      if (c < n) {
         cout << "NO\n";
         for (int i = 0; i < n; ++i) cout << (char)('a' + j);
         cout << "\n";
         return;
      }
   }

   for (int j = 0; j < k; ++j) {
      int c = 0;
      for (int i = 0; i < sz(s); ++i) {
         if (c == s[i-1]-'a') {
            s[i-1] = ' ';
            ++c;
         }
      }
      if (c != k) {
         cout << "NO\n";
         for (int i = 0; i < n; ++i) cout << (char)('a' + j);
         cout << "\n";
         return;
      }
   }

   cout << "YES\n";
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