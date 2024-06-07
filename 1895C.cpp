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

const int INF = 0x3f3f3f3f3f;

int sumdig(int n) {
   int sum = 0;
   while (n) {
      sum += n % 10;
      n /= 10;
   }
   return sum;
}

int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for (auto &c : a) cin >> c;
   vector<vector<int>> sum(6, vector<int>(50, 0));
   for (auto &c : a) {
      int ssize = to_string(c).size();
      sum[ssize][sumdig(c)]++;
   }
   int ans = 0;
   for (auto &c : a) {
      int ssize = to_string(c).size();

      ans += sum[ssize][sumdig(c)];

      if (ssize & 1) {
         for (int i = 1; i < ssize; i += 2) {
            int half = (ssize + i) / 2;
            int left = c / pow10[half];
            int right = c % pow10[half];
            
            dbg(left, right, half);

            left = sumdig(left);
            right = sumdig(right);

            dbg(left, right, half);
            dbg(c);
            dbg(sum[i][abs(left - right)], i, abs(left - right));

            if (right >= left) ans += sum[i][abs(left - right)];
            
            left = c % pow10[half - i];
            right = c / pow10[half - i];
            left = sumdig(left);
            right = sumdig(right);

            dbg(left, right);
            dbg(c);
            dbg(sum[i][abs(left - right)], i, abs(left - right));
            
            if (right >= left) ans += sum[i][abs(left - right)];
         }
      } else {
         for (int i = 2; i < ssize; i += 2) {
            int half = (ssize + i) / 2;
            int left = c / pow10[half];
            int right = c % pow10[half];

            left = sumdig(left);
            right = sumdig(right);

            dbg(left, right);
            dbg(c);
            dbg(sum[i][abs(left - right)], i, abs(left - right));

            if (right >= left) ans += sum[i][abs(left - right)];

            left = c % pow10[half - i];
            right = c / pow10[half - i];
            left = sumdig(left);
            right = sumdig(right);

            dbg(left, right);
            dbg(c);
            dbg(sum[i][abs(left - right)], i, abs(left - right));

            if (right >= left) ans += sum[i][abs(left - right)];
         }
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
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}