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
#define vector2d(var, y, z, type, x) vector<vector<type>> var(y, vector<type>(z, x))
#define vector3d(var, y, z, w, type, x) vector<vector<vector<type>>> var(y, vector<vector<type>>(z, vector<type>(w, x)))
#define vector4d(var, y, z, w, u, type, x) vector<vector<vector<vector<type>>>> var(y, vector<vector<vector<type>>>(z, vector<vector<type>>(w, vector<type>(u, x)))

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
const int N = 3e6 + 5;

void solve()
{
   string a, b;
   getline(cin, a);
   getline(cin, b);
   // int bracket = 0;
   // char c;
   // int type = 1;
   // bool flag = false;
   // while (cin >> c) {
   //    if (c == '(') bracket++;
   //    if (c == ')') bracket--;
   //    if (bracket != 0 && !flag) flag = true;
   //    if (bracket == 0 && isdigit(c) && flag) {
   //       type++;
   //    }
   //    (type == 1) ? a += c : b += c;
   // }

   a.erase(remove(a.begin(), a.end(), ' '), a.end());
   b.erase(remove(b.begin(), b.end(), ' '), b.end());
   
   dbg(a);
   dbg(b);

   bool isAType1 = true;
   for (auto &c : a) if (!isdigit(c)) isAType1 = false;
   bool isBType1 = true;
   for (auto &c : b) if (!isdigit(c)) isBType1 = false;
   if (isAType1 != isBType1) {
      return void (cout << "No\n");
   }
   if (isAType1 && isBType1) {
      if (a == b) {
         return void (cout << "Yes\n");
      } else {
         return void (cout << "No\n");
      }
   }
   // vector<vector<int>> adj_a(N), adj_b(N);
   unordered_map<int, vector<int>> adj_a, adj_b;
   stack<int> val;
   string num;
   for (int i = 0; i < sz(a); ++i) {
      if (isdigit(a[i])) {
         num += a[i];
      } else {
         if (sz(num) && a[i] == ')') {
            adj_a[val.top()].pb(stoll(num));
            num = "";
         } else if (sz(num) && a[i] == '(') {
            if (val.size()) {
               adj_a[val.top()].pb(stoll(num));
            }
            val.push(stoll(num));
            num = "";
         } else if (a[i] == ')') {
            if (val.size()) val.pop();
         }
      }
   }

   while (val.size()) val.pop();
   
   num = "";
   for (int i = 0; i < sz(b); ++i) {
      if (isdigit(b[i])) {
         num += b[i];
      } else {
         if (sz(num) && b[i] == ')') {
            adj_b[val.top()].pb(stoll(num));
            num = "";
         } else if (sz(num) && b[i] == '(') {
            if (val.size()) {
               adj_b[val.top()].pb(stoll(num));
            }
            val.push(stoll(num));
            num = "";
         } else if (b[i] == ')') {
            if (val.size()) val.pop();
         }
      }
   }

   for (auto &x : adj_a) sort(all(x.se));
   for (auto &x : adj_b) sort(all(x.se));

   for (auto [i, _] : adj_a) {
      if (adj_a[i] != adj_b[i]) {
         return void (cout << "No\n");
      }
   }
   for (auto [i, _] : adj_b) {
      if (adj_a[i] != adj_b[i]) {
         return void (cout << "No\n");
      }
   }
   cout << "Yes\n";
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}