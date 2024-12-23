
/*
  Code by: linvg
  Created: 24.10.2024 22:08:18
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

int minSwapsToSortAsc(vector<int>& arr) {
   int n = arr.size();
   vector<pair<int, int>> arrPos(n);
   for (int i = 0; i < n; i++) {
      arrPos[i] = { arr[i], i };
   }
   sort(arrPos.begin(), arrPos.end());
   vector<bool> visited(n, false);
   int swaps = 0;
   for (int i = 0; i < n; i++) {
      if (visited[i] || arrPos[i].second == i) {
         continue;
      }
      int cycleSize = 0;
      int j = i;

      while (!visited[j]) {
         visited[j] = true;
         j = arrPos[j].second;
         cycleSize++;
      }
      if (cycleSize > 1) {
         swaps += (cycleSize - 1);
      }
   }
   return swaps;
}

int minSwapsToSortDesc(vector<int>& arr) {
   int n = arr.size();
   vector<pair<int, int>> arrPos(n);
   for (int i = 0; i < n; i++) {
      arrPos[i] = { arr[i], i };
   }
   sort(arrPos.rbegin(), arrPos.rend());
   vector<bool> visited(n, false);
   int swaps = 0;
   for (int i = 0; i < n; i++) {
      if (visited[i] || arrPos[i].second == i) {
         continue;
      }
      int cycleSize = 0;
      int j = i;

      while (!visited[j]) {
         visited[j] = true;
         j = arrPos[j].second;
         cycleSize++;
      }
      if (cycleSize > 1) {
         swaps += (cycleSize - 1);
      }
   }
   return swaps;
}

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for (auto& c : a) cin >> c;
   int res = 0, mx = 0, mn = INF, pre = 0;
   auto order = [&](int l, int r) {
      vector<int> b;
      for (int i = l; i <= r; ++i) {
         if (a[a[i] - 1] != i + 1 && a[i] != i + 1) b.push_back(a[i]);
      }
      return min(minSwapsToSortAsc(b), minSwapsToSortDesc(b));
   };
   cout << order(0, n - 1) << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}