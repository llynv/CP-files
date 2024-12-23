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
#define endl '\n'
#define fill(x, y) memset(x, y, sizeof(x))

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return (x) * (x); }
template<class T> T cube(T x) { return (x) * (x) * (x); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f;

struct covid
{
    int x, y;
    int index;
};

const int N = 2e3 + 11;

vector<ii> a;
int dist[N], d, n, m;

int dis(int x, int y, int u, int v)
{
    return (x - u) * (x - u) + (y - v) * (y - v);
}

void bfs(int index)
{
    queue<covid> q;
    covid e {a[index].fi, a[index].se, index};
    q.push(e);
    dist[index] = 0;
    while (!q.empty()) {
        covid cur = q.front();
        q.pop();
        rep (i, 0, n) {
            if (i == index) continue;
            // cout << cur.x << " : " << cur.y << " " << " " << a[i] << " " << dis(cur.x, cur.y, a[i].fi, a[i].se) << " " << d*d << "\n";
            if (dis(cur.x, cur.y, a[i].fi, a[i].se) < d*d && dist[i] == -1) {
                q.push({a[i].fi, a[i].se, i});
                dist[i] = dist[cur.index] + 1;
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> d;
    rep(i, 0, n) {
        int x, y;
        cin >> x >> y;
        a.pb({x, y});
    }
    // sort(all(a));
    memset(dist, -1, sizeof(dist));
    bfs(m-1);
    int f1 = 0, f2 = 0;
    rep (i, 0, n) {
        f1 += (dist[i] == 1);
        f2 += (dist[i] == 2);
        // cout << dist[i] << "\n";
    }
    cout << f1 << " " << f2;
    // dbg(a);
}
