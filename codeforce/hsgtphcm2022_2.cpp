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

const int N = 1e6 + 7;
const int mod = 1007;

struct SegmentTree
{
    int val, updateVal;
} it[N];

void lazy (int index, int L, int R)
{
    if (L == R) return;

    if (!it[index].updateVal) return;

    int k = it[index].updateVal;
    it[index].updateVal = 0;
    it[index << 1].updateVal += k;
    it[index << 1 | 1].updateVal += k;
    int mid = (L + R) >> 1;
    it[index << 1].val += (mid - L + 1) * k;
    it[index << 1 | 1].val += (R - mid) * k;
}

void update (int index, int L, int R, int l, int r, int val)
{
    if (R < l || r < L) return;

    lazy(index, L, R);
    if (l <= L && R <= r) {
        it[index].val += (R - L + 1) * val;
        it[index].updateVal += val;
        return;
    }

    int mid = (L + R) >> 1;
    update(index * 2, L, mid, l, r, val);
    update(index * 2 + 1, mid + 1, R, l, r, val);
    it[index].val = it[index * 2].val + it[index * 2 + 1].val;
}

int get (int index, int L, int R, int l, int r)
{
    if (R < l || r < L) return 0;

    lazy(index, L, R);
    if (l <= L && R <= r) return it[index].val;

    int mid = (L + R) >> 1;
    return get(index * 2, L, mid, l, r) + get(index * 2 + 1, mid + 1, R, l, r);
}

void solve()
{
    int n, q, l, r, x, t;
    cin >> n >> q;


    int first = 1, second = 1;
    vector<int> f;
    f.push_back(0);
    f.push_back(first);
    f.push_back(second);
    for (int i = 3; i < 108; ++i) {
        int cur = (first + second) % mod;
        f.push_back(cur);
        // cout << cur << " ";
        first = second;
        second = cur;
    }
    // dbg(f, sz(f));

    int T = sz(f);

    rep (i, 0, q) {
        cin >> t;
        if (t == 1) {
            cin >> l >> r >> x;
            x %= T;
            if (x == 0) {
                update(1, 1, n, l, r, 0);
                continue;
            }            
            update (1, 1, n, l, r, f[x]);
        } else {
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << "\n";
        }
    }    
}
