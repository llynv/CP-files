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
const int N = 2e6 + 7;
vector<int>  starty[N], endy[N];
vector<ii> startx[N], segment[N];
int fw[N];

void update (int i, int val)
{
    for (; i < N; i += i & -i)
        fw[i] += val;
}

int get (int i)
{
    int res = 0;
    for (; i > 0; i -= i & -i)
        res += fw[i];
    return res;
}

void solve()
{   
    int n;
    cin >> n;
    rep (i, 0, n) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1e6;
        y1 += 1e6;
        x2 += 1e6;
        y2 += 1e6;

        if (y1 == y2) {
            starty[x1].pb(y1);
            endy[x2].pb(y1);
        } else {    
            startx[x1].pb({max(y1, y2), min(y1, y2)});
        }
    }
    for (int i = 0; i < N; ++i) {
        if (startx[i].empty()) continue;

        sort(all(startx[i]));
        segment[i].push_back({startx[i][0].fi, 0});
        int end = startx[i][0].se;
        for (int j = 1; j < sz(startx[i]); ++j) {
            if (startx[i][j].fi <= end) {
                end = max(end, startx[i][j].se);
            } else {
                segment[i].back().se = end;
                segment[i].push_back({startx[i][j].fi, 0});
                end = startx[i][j].se;
            }
        }
        segment[i].back().se = end;
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        for (auto &p : starty[i]) {
            update(p, 1);
        }

        for (auto &p : endy[i]) {
            update(p, -1);
        }

        // if (!starty[i].empty()) dbg(starty[i]);
        // if (!endy[i].empty()) dbg(endy[i]);

        for (auto &p : segment[i]) {
            res += get(p.fi) - get(p.se - 1);
            // dbg(p);
        }   
    }
    cout << res << "\n";
}
