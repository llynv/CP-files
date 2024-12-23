
/*
  Code by: linvg
  Created: 26.10.2024 16:29:59
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
const int N = 4e6 + 7;

struct Trie {
   struct Node
   {
      Node* child[2];
      int cnt;
      Node() {
         child[0] = child[1] = nullptr;
         cnt = 0;
      }
   };
   Node* root;
   Trie() {
      root = new Node();
   }
   void insert(int x) {
      Node* cur = root;
      for (int i = 30; i >= 0; --i) {
         int bit = (x >> i) & 1;
         if (!cur->child[bit]) {
            cur->child[bit] = new Node();
         }
         cur = cur->child[bit];
         cur->cnt++;
      }
   }
   // find value that x and value == 0, if not found return -1
   int find(int x) {
      Node* cur = root;
      int ans = find(cur, x, 30, 0);
      return ans;
   }

   int find(Node* cur, int x, int i, int value) {
      if (i < 0) return value;
      int bit = (x >> i) & 1;
      if (!bit) {
         int x = find(cur->child[bit], x, i - 1, value);
         x = max(x, find(cur->child[bit ^ 1], x, i - 1, value | (1 << i)));
         return x;
      }
      if (cur->child[bit] && cur->child[bit]->cnt > 0) {
         return find(cur->child[bit], x, i - 1, value);
      } else {
         return find(cur->child[bit ^ 1], x, i - 1, value | (1 << i));
      }
   }
};

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   Trie trie;
   for (auto &c : a) {
      cin >> c;
      trie.insert(c);
   }
   for (int i = 0; i < n; ++i) {
      int ans = trie.find(a[i]);
      cout << ans << ' ';
   }
   int ans = 0;
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}