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
const int N = 2e5 + 5;

int numb[N], tmpNumb[N];
vector<int> adj[N];

void dfs(int u, int p) {
    numb[u] = 1;
    for (auto v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
        numb[u] += numb[v];
    }
}

void dfs2(int u, int p, int k, int x, int &res) {
    if (res >= k) return;

    int total = 1;
    for (auto v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs2(v, u, k, x, res);
        total += tmpNumb[v];
    }

    if (total >= x && u != 1 && res < k) {
        res++;
        tmpNumb[u] = 0;
    } else {
        tmpNumb[u] = total;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        numb[i] = 0;
    }

    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, -1);

    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2, val = 0;
        std::copy(std::begin(numb), std::end(numb), std::begin(tmpNumb));
        dfs2(1, -1, k, mid, val);
        if (val >= k && tmpNumb[1] >= mid) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << "\n";
}

int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}