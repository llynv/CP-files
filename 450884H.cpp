#include <bits/stdc++.h>
using namespace std;

#define LINVG
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

void solve()
{
   int n, m;
   cin >> n >> m;
   vector<vector<int>> a(n, vector<int>(m));
   rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];
   vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
   dp[1][1] = 1;
   rep(i, 2, n + 1) dp[i][1] = (a[i - 1][0] == a[i - 2][0]) ? dp[i - 1][1] + 1 : 1;
   rep(i, 2, m + 1) dp[1][i] = (a[0][i - 1] == a[0][i - 2]) ? dp[1][i - 1] + 1 : 1;
   rep(i, 2, n + 1) rep(j, 2, m + 1) {
      if (a[i - 1][j - 1] == a[i - 2][j - 1] && a[i - 1][j - 1] == a[i - 1][j - 2]) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      else if (a[i - 1][j - 1] == a[i - 1][j - 2]) dp[i][j] = dp[i][j - 1] + 1;
      else if (a[i - 1][j - 1] == a[i - 2][j - 1]) dp[i][j] = dp[i - 1][j] + 1;
      else dp[i][j] = 1;
   }
   int res = 0;
   for (auto& c : dp) {
      for (auto& d : c) res += d;
      // cout << endl;
   }
   cout << res << endl;
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