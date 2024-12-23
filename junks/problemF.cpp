/*
  Code by: linvg
  Created: 29.09.2024 15:09:46
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
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
const int MOD = 1e9 + 7;
const int N = 111;

int bit[N];

void add (int i, int v) {
  for (; i < N; i += i & -i) bit[i] += v;
}

int sum (int i) {
  int res = 0;
  for (; i > 0; i -= i & -i) res += bit[i];
  return res;
}

void solve()
{
  int n;
  cin >> n;
  vector<array<int, 2>> a(n);
  vector<string> str(n);
  vector<int> e(6);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int p;
    cin >> p;
    int score = 0, mx = -INF, mn = INF;
    for (int j = 0; j < 6; ++j) {
      cin >> e[j];
      score += e[j];
      mx = max(mx, e[j]);
      mn = min(mn, e[j]);
    }
    a[i] = {score + p * 10 - mx - mn, n - i - 1};
    str[i] = s;
  }
  sort(all(a), greater<array<int, 2>>());
  for (int i = 0; i < min(n, 1000ll); ++i) {
    int above = sum(a[i][0]);
    if (above > 2) break;
    if (a[i][0] != 0) {
      add(1, 1);
      add(a[i][0], -1);
    }
    cout << str[n - a[i][1] - 1] << ' ' << a[i][0] << '\n';
  }
}


int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
  // int t;
  // cin >> t;
  // while (t--)
  solve();
  return 0;
}