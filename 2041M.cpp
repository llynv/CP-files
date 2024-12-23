/*
  Code by: linvg
  Created: 24.11.2024 17:13:56
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize(" unroll-loops")
#pragma gcc optimize("Ofast")
#pragma GCC optimization("Ofast")
#pragma optimize(Ofast)

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
const int N = 1e6 + 7;

int a[N], f[20][N], g[20][N], best_pos[N], dp[N], max_left[N], min_right[N];
pair<int, int> pos[N];

void solve()
{
   int n;
   scanf("%lld", &n);
   for (int i = 0; i < n; ++i) {
      scanf("%lld", &a[i]);
      pos[i] = { a[i], i };
      min_right[i + 1] = INF;
      if (i > 0 && a[i] >= a[i - 1]) dp[i + 1] = dp[i] + 1;
      else dp[i + 1] = 1;
   }
   sort(pos, pos + n);
   if (n - dp[n] == 0) return void(cout << "0\n");
   int res = sqr(n);
   for (int i = 1; i <= n; ++i) max_left[i] = max(max_left[i - 1], a[i - 1]);
   min_right[n] = a[n - 1];
   for (int i = n - 1; i >= 1; --i) min_right[i] = min(min_right[i + 1], a[i - 1]);
   for (int i = 1; i <= n; ++i) {
      if (max_left[i] <= min_right[i + 1]) {
         int l = i + 1, r = n, ans = i;
         while (l <= r) {
            int mid = (l + r) >> 1;
            if (mid - dp[mid] <= i && max_left[mid] <= min_right[mid]) {
               l = mid + 1;
               ans = mid;
            }
            else {
               r = mid - 1;
            }
         }
         res = min(res, (i - dp[i] == 0 ? 0 : sqr(i)) + sqr(n - ans));
      }
   }
   for (int i = 0; i < n; ++i) {
      best_pos[i] = lower_bound(pos, pos + n, make_pair(a[i], i)) - pos + 1;
   }
   priority_queue<int, vector<int>, greater<int>> min_heap; // Min-heap
   vector<bool> removed(n + 1, false); // Track removed elements

   for (int i = 1; i <= n; ++i) min_heap.push(i);
   for (int i = 1; i < n; ++i) {
      removed[best_pos[i - 1]] = true;
      while (!min_heap.empty() && removed[min_heap.top()]) min_heap.pop();
      if (!min_heap.empty()) {
         int smallest = min_heap.top();
         res = min(res, sqr(n - smallest + 1) + sqr(i));
      }
   }

   priority_queue<int> max_heap; // Max-heap
   fill(removed.begin(), removed.end(), false); // Reset removed tracker

   for (int i = 1; i <= n; ++i) max_heap.push(i);
   for (int i = n; i > 1; --i) {
      removed[best_pos[i - 1]] = true;
      while (!max_heap.empty() && removed[max_heap.top()]) max_heap.pop();
      if (!max_heap.empty()) {
         int largest = max_heap.top();
         res = min(res, sqr(largest) + sqr(n - i + 1));
      }
   }

   printf("%lld", res);
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}