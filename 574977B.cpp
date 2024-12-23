/*
  Code by: linvg
  Created: 20.12.2024 18:50:37
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

vector<int> z_function(string s) {
   int n = s.length();
   vector<int> z(n);
   for (int i = 1, l = 0, r = 0; i < n; ++i) {
      // khoi tao z[i] theo thuat toan toi uu
      if (i <= r)
         z[i] = min(r - i + 1, z[i - l]);
      // tinh z[i]
      while (i + z[i] < n && s[z[i]] == s[i + z[i]])
         ++z[i];
      // cap nhat doan [l,r]
      if (i + z[i] - 1 > r) {
         l = i;
         r = i + z[i] - 1;
      }
   }
   return z;
}

vector<int> string_matching(string s, string t) {
   string p = t + '#' + s;
   int m = t.length();
   int n = s.length();
   vector<int> z = z_function(p);
   vector<int> res;
   for (int i = m + 1; i <= m + n; ++i) {
      // tim duoc dap an va them vao vector res
      if (z[i] == m)
         res.push_back(i - m - 1);
   }
   return res;
}

bool check_s (int a, int b) {
   return (a & 1) != (b & 1);
}

void solve()
{
   string s, t;
   cin >> s >> t;
   if (sz(s) < sz(t)) return void (cout << "NO\n");
   vector<vector<int>> pos(26);
   for (int i = 0; i < sz(s); ++i) {
      pos[s[i] - 'a'].push_back(i);
   }

   for (int state = 0; state < 2; ++state) {
      int cur_p = lower_bound(all(pos[t[0] - 'a']), 0) - pos[t[0] - 'a'].begin();
      if (cur_p == pos[t[0] - 'a'].size()) break;
      if (state) {
         int prev = pos[t[0] - 'a'][cur_p];
         for (; cur_p < pos[t[0] - 'a'].size() && !check_s(prev, pos[t[0] - 'a'][cur_p]); ++cur_p) {}
      }
      if (cur_p == pos[t[0] - 'a'].size()) break;
      bool ok = true;
      cur_p = pos[t[0] - 'a'][cur_p];
      for (int i = 1; i < sz(t); ++i) {
         int p = upper_bound(all(pos[t[i] - 'a']), cur_p) - pos[t[i] - 'a'].begin();
         int j = p;
         for (; j < sz(pos[t[i] - 'a']) and !check_s(cur_p, pos[t[i] - 'a'][j]); ++j) {}
         if (j == sz(pos[t[i] - 'a'])) {
            ok = false;
            break;
         }
         cur_p = pos[t[i] - 'a'][j];
         dbg(cur_p);
      }
      if (ok) {
         if ((sz(s) - cur_p + 1) % 2 != 0) continue; 
         return void (cout << "YES\n");
      }
   }
   cout << "NO\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}