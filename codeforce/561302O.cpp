
/*
  Code by: linvg
  Created: 25.10.2024 20:04:28
*/

#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
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

bool compare (string a, string b) {
   if (a.size() != b.size()) return a.size() < b.size();
   return a < b;
}

bool compare (int a, string b) {
   return compare(to_string(a), b);
}

int nineth [18] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 9999999999, 99999999999, 999999999999, 9999999999999, 99999999999999, 999999999999999, 9999999999999999, 99999999999999999};

int mul_of_ditgits (int n) {
   if (n == 0) return 0;
   int ans = 1;
   while (n) {
      ans *= n % 10;
      n /= 10;
   }
   return ans;
}

int concat (int a, int b) {
   string st = to_string(a);
   while (st.size() && st.front() == '0') st.erase(st.begin());
   if (st.empty()) return b;
   if (b == 0) return stoull(st);
   return stoull(st + to_string(b));
}

int calc (int kth, int current, string l, string r) {
   if (kth == sz(r)) {
      return current;
   }
   int x = calc(kth + 1, current * 10 + (r[kth] - '0'), l, r);
   int t = concat(current * 10 + (r[kth] - '0') - 1, nineth[sz(r) - kth - 1]);
   dbg(x, t);
   if (mul_of_ditgits(x) > mul_of_ditgits(t) || t < stoull(l) || t > stoull(r)) {
      return x;
   }
   return t;
}

void solve()
{
   string l, r;
   cin >> l >> r;
   cout << calc(0, 0, l, r) << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}