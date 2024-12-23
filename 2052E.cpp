/*
  Code by: linvg
  Created: 17.12.2024 15:37:51
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T gcd(initializer_list<T> __l) { int a = 0; for (auto x : __l) { a = gcd(a, x); } return a; }
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
const int MOD = 1e9 + 7;

void solve_for_s(string str, bool first_time = false)
{
   if (str[0] == '+' || str[0] == '-') return;
   if (str[sz(str) - 1] == '+' || str[sz(str) - 1] == '-') return;
   for (int i = 0; i < sz(str); ++i) {
      if (str[i] == '0') {
         if (i > 0 && i < sz(str)) if (!isdigit(str[i + 1]) && !isdigit(str[i - 1])) continue;
         if (i == 0) if (!isdigit(str[i + 1])) continue;
         if (i == sz(str) - 1) if (!isdigit(str[i - 1])) continue;
      }
      if (i < sz(str) && !isdigit(str[i]) && !isdigit(str[i + 1])) return;
      if (str[i] == '=') {
         if (i == 0 || i == sz(str) - 1) return;
         if (str[i - 1] == '+' || str[i - 1] == '-') return;
         if (str[i + 1] == '+' || str[i + 1] == '-') return;
      }
      if (str[i] == '0' && i == 0) return;
      if (i > 0 && str[i] == '0' && (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '=')) return;
   }
   
   string fhalf, shalf;
   bool pass = false;
   for (int i = 0; i < sz(str); ++i) {
      if (str[i] == '=') {
         pass = true;
         continue;
      }
      if (!pass) fhalf += str[i];
      else shalf += str[i];
   }

   int prev = 0, cur = 0;
   stack<char> op;
   string op_pattern = "+-";
   string carry = "0";
   for (int i = 0; i < sz(fhalf); ++i) {
      if (find(all(op_pattern), fhalf[i]) == op_pattern.end()) {
         prev = prev * 10 + (fhalf[i] - '0');
         if (to_string(prev).size() > 10) return;
      }
      else {
         if (sz(op) == 0) {
            op.push(fhalf[i]);
            cur += prev;
            prev = 0;
            continue;
         }
         char c = op.top(); op.pop();
         cur += (c == '+' ? prev : -prev);
         prev = 0;
         op.push(fhalf[i]);
      }
   }
   if (sz(op) > 0) {
      char c = op.top(); op.pop();
      cur += (c == '+' ? prev : -prev);
      prev = 0;
   }
   else {
      cur += prev;
   }
   int f1 = cur;

   while (sz(op) > 0) op.pop();
   cur = 0, prev = 0;
   for (int i = 0; i < sz(shalf); ++i) {
      if (find(all(op_pattern), shalf[i]) == op_pattern.end()) {
         prev = prev * 10 + (shalf[i] - '0');
         if (to_string(prev).size() > 10) return;
      }
      else {
         if (sz(op) == 0) {
            op.push(shalf[i]);
            cur += prev;
            prev = 0;
            continue;
         }
         char c = op.top(); op.pop();
         cur += (c == '+' ? prev : -prev);
         prev = 0;
         op.push(shalf[i]);
      }
   }
   if (sz(op) > 0) {
      char c = op.top(); op.pop();
      cur += (c == '+' ? prev : -prev);
      prev = 0;
   }
   else {
      cur += prev;
   }
   int f2 = cur;
   dbg(f1, f2);
   if (f1 == f2) {
      if (first_time) {
         cout << "Correct\n";
         exit(0);
      }
      cout << str << '\n';
      exit(0);
   }
}

void solve()
{
   string s;
   cin >> s;

   solve_for_s(s, true);

   for (int i = 0; i < sz(s); ++i) {
      if (!isdigit(s[i])) continue;
      string tmp = s;
      tmp.erase(i, 1);
      tmp += s[i];
      solve_for_s(tmp);
      for (int j = sz(s) - 1; j > 0; --j) {
         swap(tmp[j], tmp[j - 1]);
         solve_for_s(tmp);
      }
   }
   cout << "Impossible\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}