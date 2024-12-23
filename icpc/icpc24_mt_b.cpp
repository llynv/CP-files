
/*
  Code by: linvg
  Created: 22.10.2024 16:35:28
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

void solve()
{
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   for (auto &c : a) cin >> c;
   unordered_map<int, int> andPair, andThree;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         andPair[a[i] & a[j]]++;
      } 
   }
   int stt = 0;
   for (int i = 0; i < n; ++i) {
      for (auto [val, cnt] : andPair) {
         andThree[val & a[i]] += cnt;
      }
   }
   int first = 0, second = 0, third = 0, fourth = 0;
   vector<vector<int>> total(5, vector<int>(n + 1));
   unordered_map<int, int> sum;
   for (int i = 1; i <= n; ++i) {
      if (sum.find(a[i - 1]) != sum.end()) {
         total[4][i] = total[4][i - 1] + sum[a[i - 1]];
         continue;
      }
      int x = ((1 << 20) - 1) ^ a[i - 1];
      for (int state = x; state; state = (state - 1) & x) {
         sum[a[i - 1]] += andThree[state];
      }
      sum[a[i - 1]] += andThree[0];
      total[4][i] = total[4][i - 1] + sum[a[i - 1]];
      if (total[4][i] < k) first = i;
   }
   dbg(total[4]);
   if (total[4][n] < k) return void (cout << "-1\n");
   k -= total[4][first];
   // dbg(k);
   // dbg(first);
   for (int i = 1; i <= n; ++i) {
      int sum = 0;
      // for (int state = a[i - 1]; state; state = (state - 1) & a[i - 1]) {
      //    sum += andPair[state];
      // }
      for (auto [val, cnt] : andPair) {
         if ((val & a[i - 1] & a[first]) == 0) {
            sum += cnt;
         }
      }
      total[3][i] = total[3][i - 1] + sum;
      if (total[3][i] < k) second = i;
   }
   k -= total[3][second];
   // dbg(k);
   // dbg(second);
   for (int i = 1; i <= n; ++i) {
      int sum = 0;
      for (int j = 0; j < n; ++j) {
         if ((a[i - 1] & a[j] & a[first] & a[second]) == 0) {
            sum++;
         }
      }
      total[2][i] = total[2][i - 1] + sum;
      if (total[2][i] < k) third = i;
   }
   k -= total[2][third];
   // dbg(k);
   // dbg(third);
   for (int i = 1; i <= n; ++i) {
      k -= ((a[i - 1] & a[first] & a[second] & a[third]) == 0);
      if (k == 0) {
         fourth = i - 1;
         break;
      }
   }
   // dbg(total[4]);
   // dbg(total[3]);
   // dbg(total[2]);
   cout << first + 1 << ' ' << second + 1 << ' ' << third + 1 << ' ' << fourth + 1 << '\n';
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   clock_t start = clock();
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   // cout << 5000 << ' ' << rd() % (5000ll * 5000 * 5000 * 5000) + 10 << '\n';
   // for (int i = 0; i < 5000; ++i) {
   //    cout << rd() % 1000000 + 1 << ' ';
   // }
   solve();
   cerr << "Time: " << (clock() - start) / (double) CLOCKS_PER_SEC << '\n';
   return 0;
}  