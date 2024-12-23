/*
  Code by: linvg
  Created: 17.12.2024 17:51:01
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
   int n, m, q;
   cin >> n >> m >> q;
   vector<int> a(n), d(n), l(m);
   for (auto &c : a) cin >> c;
   for (auto &c : d) cin >> c;
   for (auto &c : l) cin >> c;
   vector<pair<int, int>> ques(q);
   for (int i = 0; i < q; ++i) {
      cin >> ques[i].first;
      ques[i].second = i;
   }
   sort(all(ques));
   vector<pair<int, int>> dueTime;
   for (int i = 0; i < n; ++i) dueTime.emplace_back(a[i], d[i]);
   sort(all(dueTime), [](auto &a, auto &b) {
      if (a.second == b.second) return a.first < b.first;
      return a.second < b.second;
   });
   dbg(dueTime);
   vector<int> res(q);
   int lastest = 0;
   int currentWork = 0, currentMovie = 0;
   for (int i = 0; i < q; ++i) {
      auto [due, id] = ques[i];
      currentMovie = 0, currentWork = 0, lastest = 0;
      while (true) {
         if (currentWork == n) {
            if (currentMovie < m && lastest + l[currentMovie] <= due) {
               lastest += l[currentMovie];
               ++currentMovie;
               continue;
            }
            break;
         }
         auto [duration, end] = dueTime[currentWork];
         dbg(lastest, currentWork, currentMovie, duration, end);
         int test = lastest + l[currentMovie];
         bool falseFlag = false;
         for (int j = currentWork; j < n; ++j) {
            test += dueTime[j].first;
            if (test > dueTime[j].second) {
               falseFlag = true;
               break;
            }
         }
         if (!falseFlag && lastest + l[currentMovie] <= due) {
            lastest += l[currentMovie] + duration;
            ++currentMovie;
            ++currentWork;
            continue;
         } else if (lastest <= due) {
            lastest += duration;
            ++currentWork;
            continue;
         }
         break;
      }   
      dbg(lastest, currentWork, currentMovie);
      res[id] = currentMovie;
   }
   for (auto c : res) cout << c << ' ';
   cout << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}