/*
  Code by: linvg
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;

void solve()
{
   int n;
   cin >> n;
   vector<int> a(1ll << n), pos (1ll << n + 1);
   for (int i = 0; i < (1ll << n); ++i) {
      cin >> a[i];
      pos[a[i]] = i;
   }

   dbg(a);
   vector<int> half(1ll << n + 1);

   auto sol = [&] (int l, int r, int t, auto&& sol) -> int {

      ordered_set s;
      for (int i = l; i <= r; ++i) s.insert(a[i]);
      
      int mid = (l + r) / 2;
      int num = *s.find_by_order(t);

      dbg(t, s, num, l, r);

      if (t == 0) return num;

      unordered_map<int, int> topHalf;
      for (int i = l; i <= r; ++i) {
         half[a[i]] = (i <= mid ? 1 : 2); 
         if (a[i] > num) {
            topHalf[half[a[i]]] ++;
         }
      } 

      if (topHalf.find(half[num]) != topHalf.end() && topHalf.size() == 1) {
         if (half[num] == 1) {
            int order = pos[num], choose = -1;
            for (int i = mid + 1; i <= r; ++i) {
               if (a[i] < num) {
                  choose = i;
                  swap (a[i], a[order]);
                  swap (pos[a[i]], pos[a[order]]);
                  dbg(1, a);
                  break;   
               }
            }
            dbg(1, a);
            return sol(mid + 1, r, t - 1, sol);
            if (choose != -1) {
               swap (a[choose], a[order]);
               swap (pos[a[choose]], pos[a[order]]);
            }
         }
         else {
            int order = pos[num], choose = -1;
            for (int i = l; i <= mid; ++i) {
               if (a[i] < num) {
                  choose = i;
                  swap (a[i], a[order]);
                  swap (pos[a[i]], pos[a[order]]);
                  dbg(2, a);
                  break;   
               }
            }
            dbg(2, a);
            return sol(l, mid, t - 1, sol);
            if (choose != -1) {
               swap (a[choose], a[order]);
               swap (pos[a[choose]], pos[a[order]]);
            }
         }
      } else if (topHalf.find(half[num]) != topHalf.end() && topHalf.size() == 2) {
         if (half[num] == 1) {
            int nxt = *s.find_by_order(t + 1);
            int order = pos[nxt], choose = -1;
            for (int i = mid + 1; i <= r; ++i) {
               if (a[i] < nxt) {
                  choose = i;
                  swap (a[i], a[order]);
                  swap (pos[a[i]], pos[a[order]]);
                  break;   
               }
            }
            dbg(3, a);
            return sol(mid + 1, r, t - 1, sol);
            if (choose != -1) {
               swap (a[choose], a[order]);
               swap (pos[a[choose]], pos[a[order]]);
            }
         } else {
            int nxt = *s.find_by_order(t + 1);
            int order = pos[nxt], choose = -1;
            for (int i = l; i <= mid; ++i) {
               if (a[i] < nxt) {
                  choose = i;
                  swap (a[i], a[order]);
                  swap (pos[a[i]], pos[a[order]]);
                  break;   
               }
            }
            dbg(4, a);
            return sol(l, mid, t - 1, sol);
            if (choose != -1) {
               swap (a[choose], a[order]);
               swap (pos[a[choose]], pos[a[order]]);
            }
         }
      } else {
         if (half[num] == 1) return sol(l, mid, t - 1, sol);
         else return sol(mid + 1, r, t - 1, sol);
      }
   };

   for (int i = 1; i <= n; ++i) {
      cout << sol(0, (1ll << n) - 1, i, sol) << " ";
   }
   cout << "\n";
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