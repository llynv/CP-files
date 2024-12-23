#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long

string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }


template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) { os << '{'; string sep; for (const T& x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve();

int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}

const int INF = 0x3f3f3f3f;

int n, m;

void move(string& dir, int& x, int& y, int& cnt)
{
   if (x == n && y == m) {
      if (dir != "UL") {
         dir = "UL";
         cnt++;
      }
   }
   else if (x == 1 && y == m) {
      if (dir != "DL") {
         dir = "DL";
         cnt++;
      }
   }
   else if (x == 1 && y == 1) {
      if (dir != "DR") {
         dir = "DR";
         cnt++;
      }
   }
   else if (x == n && y == 1) {
      if (dir != "UR") {
         dir = "UR";
         cnt++;
      }
   }
   else if (x == n) {
      if (dir == "DR") {
         dir = "UR";
         cnt++;
      }
      else if (dir == "DL") {
         dir = "UL";
         cnt++;
      }
   }
   else if (x == 1) {
      if (dir == "UR") {
         dir = "DR";
         cnt++;
      }
      else if (dir == "UL") {
         dir = "DL";
         cnt++;
      }
   }
   else if (y == 1) {
      if (dir == "UL") {
         dir = "UR";
         cnt++;
      }
      else if (dir == "DL") {
         dir = "DR";
         cnt++;
      }
   }
   else if (y == m) {
      if (dir == "UR") {
         dir = "UL";
         cnt++;
      }
      else if (dir == "DR") {
         dir = "DL";
         cnt++;
      }
   }

   if (dir == "DR") { x++; y++; }
   else if (dir == "DL") { x++; y--; }
   else if (dir == "UR") { x--; y++; }
   else if (dir == "UL") { x--; y--; }
}

void solve()
{
   int x, y, u, v;
   string dir;
   cin >> n >> m >> x >> y >> u >> v >> dir;
   if (x == u && y == v) {
      cout << "0\n";
      return;
   }
   int x1 = x, y1 = y, cnt = 0;
   string dir1 = dir;
   int res = 0;
   bool pass = false;   
   
   map<tuple<int, int, string>, bool> mp;
   while (true) {
      if (mp.count({x1, y1, dir1})) {
         cout << "-1\n";
         return;
      }
      mp[{x1, y1, dir1}] = true;
      if (x1 == u && y1 == v) {
         cout << cnt << "\n";
         return;
      }
      pass = true;
      move(dir1, x1, y1, cnt);
   }
   cout << "-1\n";
}