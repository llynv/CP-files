/*
  Code by: linvg
  Created: 20.09.2024 22:19:00
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
   int n;
   cin >> n;
   vector<int> a(n);
   for (auto& c : a) cin >> c;
   int l = 0, r = 1e12;
   while (l <= r) {
      int mid = (l + r) >> 1;
      int bonus = 0;
      bool isOk = true;
      for (int i = n - 1; i >= 0; --i) {
         if (a[i] < mid) {
            bonus += mid - a[i];
         }
         else {
            bonus -= a[i] - mid;
         }
         if (bonus < 0) {
            isOk = false;
            break;
         }
      }
      if (isOk) {
         r = mid - 1;
      }
      else {
         l = mid + 1;
      }
   }

   dbg(l, a);

   priority_queue<int, vector<int>, greater<int>> pq;
   int bonus = 0;
   bool first_max = false;
   for (int i = n - 1; i >= 0; --i) {
      if (a[i] < l) {
         pq.push(a[i]);
      }
      else {
         if (!first_max) {
            first_max = true;
            int xx = a[i] - l;
            while (!pq.empty() && xx > 0 && pq.top() < l) {
               int x = pq.top();
               pq.pop();
               x++;
               xx--;
               pq.push(x);
            }
            continue;
         }
         int xx = a[i];
         while (!pq.empty() && pq.top() < a[i] - 1) {
            int x = pq.top();
            pq.pop();
            x++;
            a[i]--;
            pq.push(x);
         }
      }
   }
   dbg(a);
   if (pq.empty()) {
      cout << 0 << '\n';
      return;
   }
   dbg(pq.top());
   cout << l - pq.top() << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}