
/*
  Code by: linvg
  Created: 02.09.2024 16:01:52
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

void update(int i, int val, vector<int> &fw) {
    for (; i < sz(fw); i |= i + 1) {
        fw[i] += val;
    }
}

int get(int i, vector<int> &fw) {
    int res = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
        res += fw[i];
    }
    return res;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> fw(n+1);
    unordered_map<int, int> mp;
    for (auto &c : a) {
        cin >> c;
        mp[c]++;
        update(c, 1, fw);
    }
    int x = n;
    while (x--) {
        if (mp[x]) {
            mp[x]
        }
    }
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}