
/*
  Code by: linvg
  Created: 01.09.2024 21:49:58
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
const int MOD = 1e8;
const int N = 1e5 + 5;

vector<int> f;

void solve()
{
    int l, r;
    cin >> l >> r;
    r -= (l - 1);
    auto x = upper_bound(all(f), r) - f.begin() - 1; 
    cout << x + 1 << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    int x = 1, st = 1, r = 1e9;
    for (; x <= r; x += st, st++) {
        f.push_back(x);
    }

   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}