/*
  Code by: linvg
  Created: 25.11.2024 14:07:16
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize(" unroll-loops")
#pragma gcc optimize("Ofast")
#pragma GCC optimization("Ofast")

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
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

unordered_map<char, int> mapped;

#define MAXLEN 1000010
constexpr uint64_t mod = (1ULL << 61) - 1;
const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (mod / 3) + (mod / 3);
uint64_t base_pow[MAXLEN];
int64_t modmul(uint64_t a, uint64_t b) {
   uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
   uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
   uint64_t ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
   ret = (ret & mod) + (ret >> 61);
   ret = (ret & mod) + (ret >> 61);
   return ret - 1;
}
void init() {
   base_pow[0] = 1;
   for (int i = 1; i < MAXLEN; i++) {
      base_pow[i] = modmul(base_pow[i - 1], base);
   }
}
struct PolyHash {
   /// Remove suff vector and usage if reverse hash is not required for more speed
   vector<int64_t> pref, suff;
   PolyHash() {}
   template <typename T>
   PolyHash(const vector<T>& ar) {
      if (!base_pow[0]) init();
      int n = ar.size();
      assert(n < MAXLEN);
      pref.resize(n + 3, 0), suff.resize(n + 3, 0);
      for (int i = 1; i <= n; i++) {
         pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
         if (pref[i] >= mod) pref[i] -= mod;
      }
      for (int i = n; i >= 1; i--) {
         suff[i] = modmul(suff[i + 1], base) + ar[i - 1] + 997;
         if (suff[i] >= mod) suff[i] -= mod;
      }
   }
   PolyHash(const char* str)
      : PolyHash(vector<char>(str, str + strlen(str))) {
   }
   uint64_t get_hash(int l, int r) {
      int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
      return h < 0 ? h + mod : h;
   }
   uint64_t rev_hash(int l, int r) {
      int64_t h = suff[l + 1] - modmul(base_pow[r - l + 1], suff[r + 2]);
      return h < 0 ? h + mod : h;
   }
   bool is_palindrome(int l, int r) {
      return get_hash(l, r) == rev_hash(l, r);
   }
};

// compare two strings (1: s < t, 0: s == t, -1: s > t)
int compare_lexicographically(PolyHash& s, PolyHash& t) { 
   int n = sz(s.pref) - 3, m = sz(t.pref) - 3;
   int l = 0, r = min(n, m), ans = 0;
   while (l <= r) {
      int mid = (l + r) >> 1;
      if (s.get_hash(0, mid) == t.get_hash(0, mid)) {
         ans = mid + 1;
         l = mid + 1;
      }
      else {
         r = mid - 1;
      }
   }
   if (ans == min(n, m) + 1) {
      if (n == m) return 0;
      return n < m ? 1 : -1;
   }
   return s.get_hash(ans, ans) < t.get_hash(ans, ans) ? 1 : -1;
}

void concat(string& s, string& t, int& start) {
   if (start == 0) {
      s = t;
      start = sz(s);
   }
   else if (start == sz(s)) {
      s += t;
      start = sz(s);
   }
   else {
      int n = sz(s);
      for (int i = 0; i < t.size(); i++, start++) {
         if (start < sz(s)) s[start] = t[i];
         else s += t[i];
      }
   }
}

const int N = 1e6 + 7;

struct Hash {
   size_t operator()(const pair<int, int>& p) const {
      return hash<int>()(p.first) ^ hash<int>()(p.second);
   }
};

unordered_map<int, PolyHash> mp;
unordered_map<int, string> cache;

struct Trie
{
   struct Node
   {
      unordered_map<short, Node*> next;
      // unordered_set<pair<int, int>, Hash> comb;
      map<int, unordered_set<int>> comb;
   };

   Node* root;
   Trie() {
      root = new Node();
   }

   void add(string& s, int idx) {
      Node* cur = root;
      for (int i = 0; i < s.size(); i++) {
         int c = s[i];
         if (cur->next.count(c) == 0) {
            cur->next[c] = new Node();
         }
         cur->comb[sz(s)].insert(idx);
         cur = cur->next[c];
      }
      cur->comb[sz(s)].insert(idx);
   }

   int find(string& t, int start) {
      Node* cur = root;
      int idx = -1, mxLen = 0;
      for (int i = 0; i < start; ++i) {
         if (cur->next.count(t[i]) == 0 || cur->next[t[i]]->comb.size() == 0) return -1;
         cur = cur->next[t[i]];
      }
      if (cur->comb.size() > 0) {
         mxLen = cur->comb.rbegin()->first;
         int c = *cur->comb.rbegin()->second.begin();
         idx = c;
         for (auto p : cur->comb.rbegin()->second) {
            int cmp = compare_lexicographically(mp[c], mp[p]);
            if (cmp == -1) {
               c = p;
               idx = p;
            } else if (cmp == 0) {
               idx = min(idx, p);
            }
         }
      }
      return idx;
   }

   void del(int idx) {
      Node* cur = root;
      for (int i = 0; i < sz(cache[idx]); i++) {
         int c = cache[idx][i];
         cur->comb[sz(cache[idx])].erase(idx);
         if (cur->comb[sz(cache[idx])].empty()) {
            cur->comb.erase(sz(cache[idx]));
         }
         if (cur->comb.size() == 0) {
            cur->next.erase(c);
            return;
         }
         cur = cur->next[c];
      }
      cur->comb[sz(cache[idx])].erase(idx);
      if (cur->comb[sz(cache[idx])].empty()) {
         cur->comb.erase(sz(cache[idx]));
      }
   }
};


void solve()
{
   int n;
   cin >> n;
   Trie trie;
   string t;
   int start = 0;
   while (n--) {
      string op;
      cin >> op;
      if (op == "add") {
         string pattern;
         int idx;
         cin >> idx >> pattern;
         vector<char> v(pattern.begin(), pattern.end());
         mp[idx] = PolyHash(v);
         cache[idx] = pattern;
         trie.add(pattern, idx);
      }
      else if (op == "append") {
         string pattern;
         cin >> pattern;
         concat(t, pattern, start);
      }
      else if (op == "delete") {
         int idx;
         cin >> idx;
         trie.del(idx);
      }
      else {
         int del;
         cin >> del;
         start -= min(start, del);
      }
      cout << trie.find(t, start) << '\n';
   }
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}