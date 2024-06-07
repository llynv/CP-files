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
const int N = 1e5 + 7;

vector<int> factors[N];

void sieve() {
   for (int i = 2; i*i < N; ++i) {
      for (int j = i; j*i < N; ++j) {
         factors[i*j].push_back(i);
         if (i != j) factors[i*j].push_back(j);
      }
   }
}

bool isBin (int n) {
   while (n) {
      if (n % 10 != 0 && n % 10 != 1) return false;
      n /= 10;
   }
   return true;
}

void solve()
{
   int n;
   cin >> n;
   if (isBin(n)) {
      cout << "YES\n";
      return;
   }
   dbg(factors[n]);
   while (n) {
      bool ok = false;
      for (auto& x : factors[n]) {
         if (isBin(x)) {
            n /= x;
            ok = true;
            break;
         }
      }
      if (!ok) {
         break;
      }  
   }
   cout << (isBin(n) ? "YES" : "NO") << '\n';
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   sieve();
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}