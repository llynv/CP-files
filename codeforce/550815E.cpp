
/*
  Code by: linvg
  Created: 17.09.2024 22:32:38
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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    set<int> s;
    for (int i = 1; i <= n; ++i) s.insert(i);
    vector<int> res(n);
    int total = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        if (s.find(a[i]) != s.end()) {
            res[i] = a[i];
            mp[a[i]] = i;
            ++total;
            s.erase(a[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!res[i]) {
            res[i] = *s.rbegin();
            s.erase(prev(s.end()));
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i + 1 == res[i]) {
            swap(res[mp[a[i]]], res[i]);
        }
    }
    cout << total << '\n';
    for (int i = 0; i < n; ++i) cout << res[i] << " \n"[i == n-1];
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}