
/*
  Code by: linvg
  Created: 31.10.2024 20:20:38
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
const int N = 4011;

vector<int> inv(N), fact(N), invfact(N);

int power(int a, int b) {
   int res = 1;
   while (b) {
      if (b & 1) res = res * a % MOD;
      a = a * a % MOD;
      b >>= 1;
   }
   return res;
}

void pre() {
   fact[0] = inv[0] = invfact[0] = 1;
   fact[1] = inv[1] = invfact[1] = 1;
   for (int i = 2; i < N; ++i) {
      fact[i] = fact[i - 1] * i % MOD;
      inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
      invfact[i] = invfact[i - 1] * inv[i] % MOD;
   }
}

int C(int n, int k) {
   if (n < k) return 0;
   return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

void solve()
{
   int n, mx = 0;
   scanf("%lld", &n);
   vector<pair<int, int>> a(n);
   for (int i = 0; i < n; ++i) {
      scanf("%lld %lld", &a[i].first, &a[i].second);
      mx = max(mx, max(a[i].first, a[i].second));
   }
   if (n <= 2000) {
      set<pair<int, int>> s;
      for (int i = 0; i < n; ++i) {
         for (int j = i + 1; j < n; ++j) {
            s.insert({ a[i].first + a[j].first, a[i].second + a[j].second });
         }
      }
      int res = 0;
      for (auto [x, y] : s) {
         res += C(x + y, x);
         res %= MOD;
      }
      printf("%lld\n", res);
   } else if (mx <= 50) {
      map<pair<int, int>, int> mp;
      for (auto [x, y] : a) {
         mp[{x, y}]++;
      }
      vector<pair<int, int>> new_a;
      for (auto [k, v] : mp) {
         for (int i = 0; i < min(v, 2ll); ++i) {
            new_a.push_back(k);
         }
      }
      n = new_a.size();
      set<pair<int, int>> s;
      for (int i = 0; i < n; ++i) {
         for (int j = i + 1; j < n; ++j) {
            s.insert({ new_a[i].first + new_a[j].first, new_a[i].second + new_a[j].second });
         }
      }
      int res = 0;
      for (auto [x, y] : s) {
         res += C(x + y, x);
         res %= MOD;
      }
      printf("%lld\n", res);
   }

   printf("0\n");
}


int32_t main() {
   freopen("ordletter.inp", "r", stdin);
   freopen("ordletter.out", "w", stdout);
   pre();
   solve();
   return 0;
}