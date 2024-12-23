/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

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
#define int long long

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "../debug.h"
#endif

const int N = 1e7+7;

vector<int> f[N];
int prime[N];
bitset<N> ext;

void eratos() {
   for (int i = 2; i*i < N; ++i) {
      if (prime[i] == 0) {
         prime[i] = i;
         for (int j = i*i; j < N; j += i) {
            prime[j] = i;
         }
      }
   }
   for (int i = 2; i < N; ++i) {
      if (prime[i] == 0) {
         prime[i] = i;
      }
   }
}

int factorize(int x) {
   unordered_map<int, bool> res;
   while (x > 1) {
      res[prime[x]] = 1;
      x /= prime[x];
   }
   int num = 1;
   for (auto &c : res) {
      num *= c.fi;
   }
   return num;
}

void sieve() {
   for (int i = 1; i*i < N; ++i) {
      for (int j = i; j*i < N; ++j) {
         if (!ext[i*j]) continue;
         f[i*j].emplace_back(i);
         if (i != j) f[i*j].emplace_back(j);
      }
   }
}

int mp[N];

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for (auto &c : a) {
      cin >> c;
      c = factorize(c);
   }
   int res = 0;
   sort(all(a));
   for (int i = 0; i < n; ++i) {
      res += mp[a[i]];
      mp[a[i]]++;
   }

   cout << res << '\n';
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   eratos();
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}
