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

const int INF = 0x3f3f3f3f3f;
const int N = 3e4 + 11;

vector<ii> startY[N], endY[N];
vector<int> v;

struct SegTree
{
    int range = 0, cnt = 0;
    int val;
} it[5 * N + 11];

void update (int index, int L, int R, int l, int r, int val)
{
    if (r < L || R < l) return;
    if (l <= L && R <= r) {
        it[index].val = val;
        it[index].cnt += val;
        it[index].cnt = max(0LL, it[index].cnt);
        if (it[index].cnt > 0) it[index].range = R - L + 1;
        else it[index].range = it[index*2].range + it[index*2+1].range;
        return;
    }
    int mid = (L + R) / 2;
    update(index*2, L, mid, l, r, val);
    update(index*2+1, mid+1, R, l, r, val);
    if (it[index].cnt > 0) it[index].range = R - L + 1;
    else it[index].range = it[index*2].range + it[index*2+1].range;
}

struct Rect 
{
    int x1, x2, y, val;

    bool operator < (const Rect &other) const {
        return y < other.y;
    }
};

vector<Rect> rects;

void solve()
{
    int n;
    cin >> n;
    rep (i, 0, n) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        rects.pb({x1, x2, y1, 1});
        rects.pb({x1, x2, y2, -1});
    }
    sort(all(rects));
    
    int pre = -1, res = 0;
    for (auto re : rects) {
        if (pre != -1) {
            res += (re.x2 - re.x1) + 2 * (re.y - pre);
            // dbg(it[1].range, re.y, pre);
            // cout << pre-1e6-1 << " " << i-1e6-1 << endl;
        }
        pre = re.y;
        
        // update(1, 0, N, re.x1+1, re.x2, re.val);
    }
    cout << res;
}
