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

const int INF = 0x3f3f3f3f3f;

void solve()
{
   int n;
   cin >> n;
   if (n <= 2) return void(cout << 4 * (2 * n + 1) - 4 << '\n');
   int ans = 0;
   for (int i = 1; i <= n; ++i) {
      int l = 0, r = n, pos = 0;
      while (l <= r) {
         int m = (l + r) / 2;
         int dist = sqr(m) + sqr(i);
         if (dist < sqr(n + 1)) {
            pos = m;
            l = m + 1;
         } else {
            r = m - 1;
         }
      }
      l = 0, r = n;
      int pos2 = 0;
      while (l <= r) {
         int m = (l + r) / 2;
         int dist = sqr(i) + sqr(m);
         if (dist < sqr(n)) {
            l = m + 1;
         } else {
            pos2 = m;
            r = m - 1;
         }
      }
      ans += pos - pos2 + 1;
   }
   cout << 4 * ans << '\n';
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