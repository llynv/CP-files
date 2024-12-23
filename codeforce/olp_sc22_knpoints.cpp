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
// #define endl "\n"
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

struct point
{
    int x, y;
    point(int _x, int _y) : x(_x), y(_y) {}
    point() {}
    bool operator<(const point &p) const
    {
        return x < p.x || (x == p.x && y < p.y);
    }
    bool operator==(const point &p) const
    {
        return x == p.x && y == p.y;
    }
};

void solve()
{
    int n, k, t;
    cin >> n >> k >> t;
    if (t != 1) return;

    set<int> st;

    auto ask = [&] (int x, int y) {
        cout << "QUERY " << x << " " << y << "\n";
        cout.flush();

        vector<int> res;
        rep (i, 0, k) {
            int u, v;
            cin >> u >> v;
            res.pb(u);
        }
        return res;
    };

    int mx = 1e6;
    vector<int> lft = ask(0, 0);
    vector<int> rgt = ask(mx, 0);

    rep (i, 0, k) {
        st.insert(lft[i]);
        st.insert(rgt[i]);
    }

    if (sz(st) == 1) {
        cout << "ANSWER \n";
        cout << *st.begin() << " " << 0 << endl;
        return;
    }

    int dist = (*st.begin() + *st.rbegin()) / 2;
    rep (i, 1, n / k + 1) {
        int x = i * ceil(pow(dist, 1.0 * k / n));
        vector<int> tmp = ask(x, 0);
        rep (j, 0, k) {
            st.insert(tmp[j]);
        }
    }

    cout <<"ANSWER \n";
    for (auto x : st) cout << x << " " << 0 << endl;

}
