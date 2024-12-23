/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

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

struct Node
{
   int val = -1;
   Node* left = nullptr, *right = nullptr;

   Node() : val(0), left(nullptr), right(nullptr) {}

   Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

const int S = log2(1e5) + 1;

int gilbertOrder(int x, int y) {
   int d = 0;
   for (int s = 1 << (S - 1); s; s >>= 1) {
      bool rx = x & s, ry = y & s;
      d = d << 2 | rx * 3 ^ static_cast<int>(ry);
      if (!ry) {
         if (rx) {
            x = (1 << S) - x;
            y = (1 << S) - y;
         }
         swap(x, y);
      }
   }
   return d;
}

struct Query {
   int l, r, idx;
   int ord;

   void calcOrder() {
      ord = gilbertOrder(l, r);
   }
};

bool operator<(const Query& a, const Query& b) {
   return a.ord < b.ord;
}

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   
   for (auto& c : a) cin >> c;

   int q;
   cin >> q;
   vector<Query> queries(q);
   for (int i = 0; i < q; ++i) {
      cin >> queries[i].l >> queries[i].r;
      queries[i].l--;
      queries[i].r--;
      queries[i].idx = i;
      queries[i].calcOrder();
   }

   sort(all(queries));

   vector<int> ans(q);

   int l = 0, r = -1;

   map<int, int> mp;

   for (auto& query : queries) {
      int 
      while (r < query.r) {
         r++;
         mp[a[r]]++;
         if (mp[a[r]] > 1) {
            
         }
         s.insert(a[r]);
      }
      while (r > query.r) {
         s.erase(s.find(a[r]));
         auto it = s.lower_bound(a[r]);
         if (it != s.end()) mn.erase(mn.find(abs(a[r] - (*it))));
         if (sz(s) && it != s.begin() && prev(it) != s.begin()) mn.erase(mn.find(abs(a[r] - (*prev(it)))));
         r--;
      }
      while (l < query.l) {
         s.erase(s.find(a[l]));
         auto it = s.lower_bound(a[l]);
         if (it != s.end()) mn.erase(mn.find(abs(a[l] - (*it))));
         if (sz(s) && it != s.begin() && prev(it) != s.begin()) mn.erase(mn.find(abs(a[l] - (*prev(it)))));
         l++;
      }
      while (l > query.l) {
         l--;
         auto it = s.lower_bound(a[l]);
         int x = INF;
         if (it != s.end()) x = min(x, abs(a[l] - (*it)));
         if (sz(s) && it != s.begin()) x = min(x, abs(a[l] - (*prev(it))));
         mn.insert(x);
         s.insert(a[l]);
      }
   }

   for (auto& c : ans) cout << c << '\n';
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}