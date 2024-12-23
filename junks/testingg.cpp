#include <bits/stdc++.h>
using namespace std;

#define LOCAL
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

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
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
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int N = 1e6 + 11;

struct SegmentTree      
{
    int curVal, maxVal;
} it[11000111];

void update (int index, int L, int R, int l, int r, int val)
{
    if (L > r || R < l) return;
    if (l <= L && R <= r) {
        dbg(L, R);
        it[index].curVal += val;
        it[index].maxVal = max(it[index].curVal, it[index].maxVal);
        return;
    }
    int mid = (L + R) >> 1;
    update (index << 1, L, mid, l, r, val);
    update (index << 1 | 1, mid + 1, R, l, r, val);
    it[index].curVal = it[index << 1].curVal + it[index << 1 | 1].curVal;
    it[index].maxVal = max({it[index].curVal, it[index].maxVal, it[index << 1].maxVal, it[index << 1 | 1].maxVal});
}

int get (int index, int L, int R, int l, int r)
{
    if (L > r || R < l) return 0;
    if (l <= L && R <= r) return it[index].curVal;
    int mid = (L + R) >> 1;
    return max(get(index << 1, L, mid, l, r), get(index << 1 | 1, mid + 1, R, l, r));
}

void solve()
{
    int n;
    cin >> n;
    rep (i, 0, n) {
        int l, r, v;
        cin >> l >> r >> v;
        update (1, 1, N, l, r, v);
    }
    cout << get(1, 1, N, 3, 6) << "\n";
}
