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
const int MOD = 1e8;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ii> a(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }   
    sort(all(a), [](ii x, ii y) {
        return x.fi < y.fi;
    });
    dbg(a);
    int lb = a[0].first, rb = a[0].second, lf = 0, rf = 0;
    if (a[0].second - a[0].first == a[0].first + n - a[0].second) {
        rf = a[0].second;
        lf = a[0].first;
    } 
    int res = min(rb - lb, lb + n - rb);
    for (int i = 1; i < m; ++i) {
        int mid = 0, tlf = 0, trf = 0;
        if (rf == 0) {
            mid = a[i].second - a[i].first;
        } else {
            if (a[i].first <= rf && a[i].second >= rf) {
                mid = a[i].second - a[i].first;
            } else if (a[i].first <= rf) {
                mid = a[i].second - a[i].first + rf - a[i].second;
            } else if (a[i].second >= rf) {
                mid = a[i].second - a[i].first + a[i].first - rf;
            } else {
                mid = a[i].second - a[i].first + a[i].first - rf + rf - a[i].second;
            }
        }
        int top = 0, tlb = 0, trb = 0;
        if (lb <= a[i].first && a[i].second <= rb) {
            top = a[i].first - lb + rb - a[i].second;
            tlb = a[i].first;
            trb = a[i].second;
        } else if (lb <= a[i].first && a[i].first <= rb) {
            top = min(a[i].first - lb, rb - a[i].first);
            if (a[i].first - lb < rb - a[i].first) {
                tlb = a[i].first;
                trb = rb;
            } else {
                tlb = lb;
                trb = a[i].first;
            }
        } else if (lb <= a[i].second && a[i].second <= rb) {
            top = min(a[i].second - lb, rb - a[i].second);
            if (a[i].second - lb < rb - a[i].second) {
                tlb = a[i].second;
                trb = rb;
            } else {
                tlb = lb;
                trb = a[i].second;
            }
        }
        if (top <= mid) {
            res += top;
            lb = tlb;
            rb = trb;
        } else {
            res += mid;
            lf = a[i].first;
            rf = a[i].second;
        }
    }
    cout << res << endl;
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