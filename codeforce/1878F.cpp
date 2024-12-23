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

#ifdef DBG
#include "debug.h"
#else
#define dbg(...)
#endif

const int INF = 1e18;
const int N = 1e6 + 7;

int prime[N];

void eratos() {
   prime[0] = prime[1] = 1;
   for (int i = 2; i * i < N; ++i) {
      if (!prime[i]) {
         for (int j = i*i; j < N; j += i) {
            prime[j] = i;
         }
      }
   }
   for (int i = 2; i < N; ++i) {
      if (!prime[i]) prime[i] = i;
   }
}

map<int, int> factors (int n)
{
   map<int, int> res;
   while (n > 1) {
      res[prime[n]]++;
      n /= prime[n];
   }
   return res;
}

int calc (map<int, int> &f)
{
   int res = 1;
   for (auto &c : f) {
      res *= c.second + 1;
   }
   return res;
}

int safeMul (int a, int b)
{
   if (a > INF / b) return 2 * INF;
   return a * b;
}

void solve()
{
   int n, q;
   cin >> n >> q;
   int init = n;
   bool isOuter = false;
   int maxN = n;
   map<int, int> primeF = factors(n);
   rep (i, 0, q) {
      int type;
      cin >> type;
      if (type == 1) {
         int x;
         cin >> x;

         map<int, int> f = factors(x);
         for (auto &c : f) {
            primeF[c.first] += c.second;
         }


         int numsFact = calc(primeF);
         bool isDivisible = true;

         for (auto &fact : primeF) {
            int cnt = fact.second;
            while (numsFact % fact.first == 0) {
               numsFact /= fact.first;
               cnt--;
            }
            if (cnt < 0) {
               isDivisible = false;
            }
         }

         dbg(numsFact);

         if (!isDivisible || numsFact != 1) {
            cout << "NO\n";
            continue;
         }

         cout << "YES\n";

      } else {
         map<int, int> f = factors(n);
         swap(f, primeF);
         maxN = n;
         isOuter = false;
      }
   }
   cout << '\n';
}



int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   eratos();
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}