#include <bits/stdc++.h>
using namespace std;

// #define LINVG
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define trav(a, x) for (auto &a : x)
#define endl "\n"
#define fill(x, y) memset(x, y, sizeof(x))
#define heapMax priority_queue<int>
#define heapMin priority_queue<int, vector<int>, greater<int>>

string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) { os << '{'; string sep; for (const T& x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LINVG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }



const int INF = 0x3f3f3f3f3f;
const int N = 1e5 + 7;

int a[N];
int n, k, ans;

int f(int i)
{
   int mx = 0, mn = i;
   for (int j = 0; j < n; ++j) {
      if (a[j] <= i) {
         mn = min(mn, a[j]);
         mx = max(mx, a[j]);
         continue;
      }
      // dbg(i, factors[a[j]]);
      if (a[j] / k >= i) {
         mx = max(mx, a[j] / k);
         mn = min(mn, a[j] / k);
         continue;
      }
      int l = 1, r = k;
      while (l <= r) {
         int mid = (l + r) / 2;
         if (a[j] / mid > i) {
            l = mid + 1;
         }
         else {
            r = mid - 1;
         }
      }
      mx = max(mx, a[j] / l);
      mn = min(mn, a[j] / l);
   }
   return mx - mn;
}

void put(int l, int r)
{
   if (l >= r) return;

   int lo = l, hi = r;
   while (lo < hi) {
      int mid = (lo + hi) / 2;

      int f1 = f(mid);
      int f2 = f(mid + 1);

      if (f1 < f2) {
         hi = mid;
      }
      else {
         lo = mid + 1;
      }
   }

   ans = min(ans, f(lo));

   dbg(l, r, lo, f(lo), ans);

   int mid = (l + r) / 2;
   // dbg(l, r, mid);

}

void solve()
{
   cin >> n >> k;
   rep(i, 0, n) cin >> a[i];

   ans = INF;
   put(1, *max_element(a, a + n));
   cout << ans << endl;
}



int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
#endif

   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}