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

void solve()
{
    int x, y;
    cin >> x >> y;
    queue<int> q;
    unordered_map<int, bool> vst;
    q.push(x);
    vst[x] = 1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == y) return void (cout << "YES\n" << "\n");

        int bit = 64 - __builtin_clzll(u);
        int rev = 0;
        for (int i = 0; i < bit; ++i) {
            if (u & (1LL << i)) rev |= 1LL << (bit - i - 1);
        }

        if (vst[rev] == 0) {
            vst[rev] = 1;
            q.push(rev);
        }
        int add = 0;
        if (bit < 64) {
            for (int i = 0; i < bit; ++i) {
                if (u & (1LL << i)) add |= 1LL << (bit - i - 1);
            }
            add |= 1LL << bit;   
        }
        if (add != 0 && vst[add] == 0) {
            vst[add] = 1;
            q.push(add);
        }
    }
    cout << "NO\n";
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