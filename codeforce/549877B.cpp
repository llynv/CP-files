
/*
  Code by: linvg
  Created: 14.09.2024 00:38:13
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
    int n, q;
    cin >> n >> q;
    map<string, char> mp;
    for (int i = 0; i < q; ++i) {
        string s;
        char c;
        cin >> s >> c;
        mp[s] = c;
    }

    int res = 0;

    auto back = [&] (string s, int j, auto&&back) -> void {
        if (j == n) {
            while (true)
            {
                if (s.size() == 1) break;
                string str;
                str += s[0];
                str += s[1];
                if (mp.find(str) == mp.end()) return;
                s.erase(s.begin(), s.begin() + 2);
                s.insert(s.begin(), mp[str]);
            }
            res += (s.back() == 'a');
            return;
        }
        
        for (char c = 'a'; c <= 'f'; ++c) {
            s += c;
            back(s, j + 1, back);
            s.pop_back();
        }
    };

    for (auto [u, s] : mp) {
        back(u, 2, back);
    }
    cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}