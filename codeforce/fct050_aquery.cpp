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
const int N = 1e5 + 7;

struct Segment
{
    int val, updVal;
} it[4*N];

int a[N];

void lazyUpdate (int index, int L, int R) {
    if (it[index].updVal == 0) return;
    if (L < R) {
        it[index*2].updVal = it[index].updVal;
        it[index*2+1].updVal = it[index].updVal;
        it[index*2].val = it[index].updVal;
        it[index*2+1].val = it[index].updVal;
    }
    it[index].updVal = 0;
}

void update (int index, int L, int R, int l, int r, int val) {
    lazyUpdate(index, L, R);
    if (l > R || r < L) return;
    lazyUpdate(index, L, R);
    if (l <= L && R <= r) {
        it[index].val = val;
        it[index].updVal = val;
        return;
    }
    int mid = (L + R) >> 1;
    update(index*2, L, mid, l, r, val);
    update(index*2+1, mid+1, R, l, r, val);
    it[index].val = it[index*2].val + it[index*2+1].val;
}

int get (int index, int L, int R, int l, int r) {
    lazyUpdate(index, L, R);
    if (l > R || r < L) return 0;
    if (l <= L && R <= r) return it[index].val;
    int mid = (L + R) >> 1;
    return get(index*2, L, mid, l, r) + get(index*2+1, mid+1, R, l, r);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    rep (i, 0, q) {
        int m, p;
        cin >> m >> p;  
        int l = 1, r = m, pos = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int sum = get(1, 1, n, mid, m);
            int mx = get(1, 1, n, mid, mid);
            if (sum - mx * (r - mid + 1) < p)
                r = mid - 1;
            else 
                l = mid + 1;
        }
        if (l <= m) {
            int lo = get(1, 1, n, m, m);
            int hi = get(1, 1, n, l, l);

            int current = get(1, 1, n, l, m);

            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                int sum = mid * (m - l + 1);
                if (sum - current < p) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            update(1, 1, n, l, m, lo);
            int ex = lo * (m - l + 1) - current;
            update(1, 1, n, l, l + r - 1, lo+1);
        }
    }
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