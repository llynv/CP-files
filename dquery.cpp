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

// template<class T> T mulmod(T a, T b, T m) { T q = (T)(((long double)a * (long double)b) / (long double)m); T r = a * b - q * m; if (r > m) r %= m; if (r < 0) r += m; return r; }
// template<class T> nCr(T n, T r) { if (r > n - r) r = n - r; T ans = 1; for (T i = 1; i <= r; ++i) { ans *= n - r + i; ans /= i; } return ans; }
// template<class T> fastPow(T a, T b, T m) { T res = 1; while (b) { if (b & 1) res = ((res % m) * (a % m)) % m; a = ((a % m) * (a % m)) % m; b >>= 1; } return res; }
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
const int N = 3e4 + 11;
const int MxN = 1e6 + 11;
const int BLOCK = 173;

struct query
{
    int l, r, id;

    bool operator< (const query &c) {
        if (l / BLOCK != c.l / BLOCK) {
            return l < c.l;
        }
        return r < c.r;
    }
};

int cnt[MxN];

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    int q;
    cin >> q;
    vector<query> qs;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        qs.pb({l, r, i});
        // cout << qs[i].l << " " << qs[i].r << " " << qs[i].id << "\n";
    }
    sort(all(qs));

    vector<int> ans(q);

    int curL = qs[0].l - 1, curR = qs[0].r - 1, dif = 0;
    for (int i = qs[0].l - 1; i < qs[0].r; ++i) {
        cnt[a[i]]++;
        dif += (cnt[a[i]] == 1);
    }

    ans[qs[0].id] = dif;

    for (int i = 1; i < q; ++i) {
        int L = qs[i].l - 1, R = qs[i].r - 1;
        // dbg(L, R, curL, curR);
        while (curL > L) {
            curL--;
            cnt[a[curL]]++;
            dif += (cnt[a[curL]] == 1);
        }

        while (curL < L) {
            cnt[a[curL]]--;
            dif -= (cnt[a[curL]] == 0);
            curL++;
        }

        while (curR < R)
        {
            curR++;
            cnt[a[curR]]++;
            dif += (cnt[a[curR]] == 1);
        }

        while (curR > R)
        {
            cnt[a[curR]]--;
            dif -= (cnt[a[curR]] == 0);
            curR--;
        }
        
        ans[qs[i].id] = dif;
    }

    for (auto c : ans) cout << c << "\n";
}
