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

#ifdef DBG
#include "debug.h"
#else
#define dbg(...)
#endif

const int INF = 0x3f3f3f3f3f;
const int N = 5011;

int fw[N], a[N];

void add(int x, int v, int end) {
   for (;x < end;x += x & -x) fw[x] += v;
}

int get(int x) {
   int ret = 0;
   for (;x > 0;x -= x & -x) ret += fw[x];
   return ret;
}

vector<int> upperLeft[N], upperRight[N];

void solve()
{
   int n;
   cin >> n;
   rep(i, 0, n) {
      cin >> a[i];
      upperLeft[i+1].clear();
      upperRight[i+1].clear();
   }

   for (int i = 1; i <= n; ++i) {
      memset(fw, 0, sizeof(int) * (n+1));
      for (int j = 0; j < n; ++j) { 
         upperLeft[i].emplace_back(get(i));
         if (i == a[j]) break; 
         add(a[j], 1, n+1);
      }
   }

   for (int i = 1; i <= n; ++i) {
      memset(fw, 0, sizeof(int) * (n+1));
      for (int j = n-1; j >= 0; --j) {
         upperRight[i].emplace_back(get(i));
         if (i == a[j]) break;
         add(a[j], 1, n+1);
      }
   }

   int64_t ans = 0;
   for (int i = 1; i < n; ++i) {
      for (int j = i+1; j < n-1; ++j) {
         ans += (int64_t) upperLeft[a[j]][i] * (int64_t) upperRight[a[i]][n-j-1];
      }
   }
   cout << ans << '\n';
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