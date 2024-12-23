
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
   int n, k, q;
   cin >> n >> k >> q;
   vector<int> a(k), b(k);
   for (auto &x : a) cin >> x;
   for (auto &x : b) cin >> x;
   vector<int> pref(k+1, 0);
   vector<double> v(k, 1);
   for (int i = 1; i <= k; ++i) {
      if (i > 1) {
         v[i-1] = 1.0 * (a[i-1] - a[i-2]) / (b[i-1] - b[i-2]);
         continue;
      }
      v[i-1] = 1.0 * a[i-1] / b[i-1];
   }
   for (int i = 0; i < q; ++i) {
      int x;
      cin >> x;
      int pos = upper_bound(all(a), x) - a.begin();
      if (pos == k) pos--;
      int sum = (pos == 0 ? 0 : b[pos - 1]);
      int d = x - (pos == 0 ? 0 : a[pos - 1]);
      int bb = b[pos] - (pos == 0 ? 0 : b[pos - 1]);
      int aa = a[pos] - (pos == 0 ? 0 : a[pos - 1]);
      cout << sum + (int) (1.0 * d * bb / aa) << ' ';
   }
   cout << '\n';
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