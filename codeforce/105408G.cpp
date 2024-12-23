
/*
  Code by: linvg
  Created: 11.10.2024 22:06:14
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

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int N = 1e6 + 7;
const int M = 1e7 + 7;

int prime[M];
// vector<int> f[M];
unordered_map<int, vector<int>> f;

void sieve() {
   prime[0] = prime[1] = 1;
   for (int i = 2; i * i < M; ++i) {
      if (prime[i] == 0) {
         prime[i] = i;
         for (int j = i * i; j < M; j += i) {
            prime[j] = i;
         }
      }
   }
   for (int i = 3; i < M; i += 2) {
      if (prime[i] == 0) {
         prime[i] = i;
      }
   }
}

// vector<pair<int, int>> fs[M];
unordered_map<int, vector<pair<int, int>>> fs;  
vector<int> fn;

void gen(int i, int n, int ff = 1) {
   if (i == sz(fs[n])) {
      fn.push_back(ff);
      return;
   }
   for (int j = 0; j <= fs[n][i].second; ++j) {
      gen(i + 1, n, ff);
      ff *= fs[n][i].first;
   }
}

void gen_factors(int n) {
   if (f[n].size() > 0) return;
   int x = n, t_f = 1;
   if (fs[n].empty()) {
      while (x > 1) {
         int p = prime[x];
         int cnt = 0;
         while (x % p == 0) {
            x /= p;
            cnt++;
         }
         t_f *= (cnt + 1);
         fs[n].push_back({ p, cnt });
      }
   }
   // if (t_f * log2(n) > sqrt(n)) {
   //    for (int i = 1; i * i <= n; ++i) {
   //       if (n % i == 0) {
   //          f[n].push_back(i);
   //          if (i * i != n) f[n].push_back(n / i);
   //       }
   //    }
   //    return;
   // }
   fn.clear(); 
   gen(0, n);
   f[n] = fn;
}

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   unordered_map<int, int> mp;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      gen_factors(a[i]);
      for (auto &x : f[a[i]]) {
         mp[x]++;
      }
   }
   int ok = 0;
   for (auto [x, y] : mp) {
      if (y != n && y != 1) {
         ok++;
      }
   }
   cout << (!ok ? "YES" : "NO") << endl;
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   sieve();
   solve();
   return 0;
}