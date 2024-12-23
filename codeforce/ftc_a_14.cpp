
/*
  Code by: linvg
  Created: 20.10.2024 08:53:19
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

int cmp(const string& a, const string& b) {
   if (sz(a) < sz(b)) return -1;
   if (sz(a) > sz(b)) return 1;
   for (int i = 0; i < sz(a); ++i) {
      if (a[i] < b[i]) return -1;
      if (a[i] > b[i]) return 1;
   }
   return 0;
}

bool comp(const string& a, const string& b) {
   if (sz(a) < sz(b)) return 1;
   if (sz(a) > sz(b)) return 0;
   for (int i = 0; i < sz(a); ++i) {
      if (a[i] < b[i]) return 1;
      if (a[i] > b[i]) return 0;
   }
   return 0;
}

bool isInc(const string& s) {
   int inc = 0;
   for (int i = 1; i < sz(s); ++i) {
      if (s[i] == s[i - 1]) return false;
      inc += (s[i] > s[i - 1] ? 1 : -1);
      if (inc > 1 || inc < 0) return false;
   }
   return true;
}

void solve()
{
   int a, b;
   cin >> a >> b;
   int kl = (to_string(a).size() + 1) / 2;
   int kr = (to_string(b).size() + 1) / 2;
   vector<string> nums;
   for (int i = kl; i <= kr; ++i) {
      int j = pow(10, i - 1);
      for (; j < pow(10, i); ++j) {
         string s = to_string(j);
         string x = s, tmp = s;
         reverse(all(x));
         s += x.substr(1);
         if (cmp(s, to_string(a)) >= 0 && cmp(s, to_string(b)) <= 0) nums.push_back(s);
         tmp += x.substr(0);
         if (cmp(tmp, to_string(a)) >= 0 && cmp(tmp, to_string(b)) <= 0) nums.push_back(tmp);
      }
   }
   sort(all(nums), comp);
   vector<string> res;
   for (auto& c : nums) {
      if (isInc(c)) res.push_back(c);
   }
   if (res.empty()) {
      cout << "0\n[]";
      return;
   }
   cout << sz(res) << '\n';
   cout << "[" << res.front();
   for (int i = 1; i < sz(res); ++i) {
      cout << ", " << res[i];
   }
   cout << ']';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}