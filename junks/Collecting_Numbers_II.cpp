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

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

#define DEBUG

#ifdef DEBUG
#include <C:\Users\asus\Documents\Workspace\CP\debug.h>
#else
#define dbg(...)
#endif

const int INF = 0x3f3f3f3f3f;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    vector<int> pos(n+1);
    pos[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] >= a[i-1]) pos[i] = pos[i-1] + 1;
        else pos[i] = 1;
    }

    dbg(a);

    vector<vector<int>> f(18, vector<int>(n+1));
    for (int i = 0; i < n; ++i) f[0][i] = pos[i-1];
    for (int i = 1; i < 18; ++i) {
        for (int j = 0; j + (1 << (i-1)) < n; ++j) {
            f[i][j] = max(f[i-1][j], f[i-1][j + (1 << (i-1))]);
        }
    }

    auto get = [&] (int l, int r) {
        if (l > r) return 0ll;
        int k = log2(r - l + 1);
        return max(f[k][l], f[k][r - (1 << k) + 1]);
    };

    // dbg(pos);

    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        
        int lo = l, hi = r;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (pos[mid] != pos[l] + mid - l) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        // dbg(lo, hi, pos[lo], pos[hi], get(hi+1, r));

        int cur = pos[hi] - pos[l-1];
        cur = max(cur, get(hi+1, r));
        cout << cur << "\n";
    }
}



int32_t main() {

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}