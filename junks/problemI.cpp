/*
  Code by: linvg
  Created: 29.09.2024 14:44:38
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
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
const int MOD = 1e9 + 7;

void solve()
{
   int n, m;
   cin >> n >> m;
   vector<int> a(n), b(m);
   for (auto &x : a) cin >> x;
   for (auto &x : b) cin >> x;

   int max_a = accumulate(all(a), 0LL);
   int max_b = accumulate(all(b), 0LL);
   int min_a = n, min_b = m;
   dbg(max_a, max_b, min_a, min_b);

   auto calc = [] (int x) -> int {
      if (x < 0) return 0LL;
      return x * (x + 1) / 2;
   };

   if (min_a >= max_b) {
      cout << "ALICE\n";
      return;
   }
   if (min_b >= max_a) {
      cout << "BOB\n";
      return;
   }

   int prob_a = 0, prob_b = 0;
   if (max_a > max_b) {
      prob_a += calc(max_b - min_b);
      prob_a += (max_b - min_b + 1) * (max_a - max_b);
      prob_b += calc(max_b - min_a) - calc(min_b - min_a - 1);
   } else {
      prob_b += calc(max_a - min_a);
      prob_b += (max_a - min_a + 1) * (max_b - max_a);
      prob_a += calc(max_a - min_b) - calc(min_a - min_b - 1);
   }
   dbg(prob_a, prob_b);
   cout << (prob_a == prob_b ? "TIED" : prob_a > prob_b ? "ALICE" : "BOB") << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}