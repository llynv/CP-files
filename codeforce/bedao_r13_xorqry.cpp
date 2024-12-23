#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define LINVG
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define trav(a, x) for (auto &a : x)
#define endl "\n"
#define fill(x, y) memset(x, y, sizeof(x))
#define heapMax priority_queue<int>
#define heapMin priority_queue<int, vector<int>, greater<int>>

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator>>(ostream &is, const T_container &v) { for (auto &c : v) is >> c; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LINVG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }


void solve();

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

const int INF = 0x3f3f3f3f3f;
const int N = 3e5 + 7;

const int S = log2(N) + 1;

int gilbertOrder(int x, int y){
    int d = 0;
    for (int s = 1 << (S - 1); s; s >>= 1){
        bool rx = x & s, ry = y & s;
        d = d << 2 | rx * 3 ^ static_cast<int>(ry);
        if (!ry){
            if (rx){
                x = (1 << S) - x;
                y = (1 << S) - y;
            }
            swap(x, y);
        }
    }
    return d;
}
 
struct Query {
    int l, r, idx;
    int ord;
 
    void calcOrder() {
        ord = gilbertOrder(l, r);
    }
};
 
bool operator<(const Query &a, const Query &b) {
    return a.ord < b.ord;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    vector<Query> qry(q);
    rep (i, 0, q) {
        int l, r;
        cin >> qry[i].l >> qry[i].r;
        qry[i].idx = i;
    }
    sort(all(qry));

    vector<int> tmp = a;
    sort(all(tmp));
    tmp.erase(unique(all(tmp)), tmp.end());
    vector<int> compress;
    for (int i = 0; i < n; ++i) {
        int c = lower_bound(all(tmp), a[i]) - tmp.begin();
        compress.pb(c);
    }

    int curL = qry[0].l, curR = qry[0].r;
    int sumXor = 0;
    
    vector<int> cnt(sz(tmp) + 1);
    for (int i = curL - 1; i < curR; ++i) {
        cnt[compress[i]]++;
        if (cnt[compress[i]] == 1) {
            sumXor ^= tmp[compress[i]];
        }
    }
    vector<int> ans(q);
    ans[qry[0].idx] = sumXor;
    // dbg(qry);
    rep (i, 1, q) {
        int l = qry[i].l, r = qry[i].r;
        // dbg(l, r, curL, curR);
        while (curL > l) {
            --curL;
            cnt[compress[curL-1]]++;
            if (cnt[compress[curL-1]] == 1) {
                sumXor ^= tmp[compress[curL-1]];
            }
        }

        while (curR < r) {
            ++curR;
            cnt[compress[curR-1]]++;
            if (cnt[compress[curR-1]] == 1) {
                sumXor ^= tmp[compress[curR-1]];
            }
        }

        while (curL < l) {
            cnt[compress[curL-1]]--;
            if (cnt[compress[curL-1]] == 0) {
                sumXor ^= tmp[compress[curL-1]];
            }
            ++curL;
        }

        while (curR > r) {
            cnt[compress[curR-1]]--;
            if (cnt[compress[curR-1]] == 0) {
                sumXor ^= tmp[compress[curR-1]];
            }
            --curR;
        }

        ans[qry[i].idx] = sumXor;
    }
    for (auto &c : ans) cout << c << " ";
}   
