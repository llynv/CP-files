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
#define heapMax(x) priority_queue<x>
#define heapMin(x) priority_queue<x, vector<x>, greater<x>>
#define dbgv(a, n) cerr << #a << " = {" << a[0]; for (int i = 1; i < n; ++i) cerr << ", " << a[i]; cerr << "}\n";

string to_upper(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}
string to_lower(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template <class T>
T gcd(T a, T b)
{
    T r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
template <class T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }
template <class T>
T sqr(T x) { return x * x; }
template <class T>
T cube(T x) { return x * x * x; }

void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int N = 2e5 + 7;

int a[N], _gcd[N][20], f[N], g[N], fw[N], ans[N];

void update(int i, int v, int end)
{
    while (i <= end)
    {
        fw[i] += v;
        i += i & -i;
    }
}

int get(int i)
{
    int res = 0;
    while (i > 0)
    {
        res += fw[i];
        i -= i & -i;
    }
    return res;
}

void buildTable(int n)
{
    rep(i, 0, n) _gcd[i][0] = a[i];

    for (int j = 1; j < 18; ++j)
    {
        for (int i = 0; i + (1 << j) - 1 <= n; ++i)
        {
            _gcd[i][j] = gcd(_gcd[i][j - 1], _gcd[i + (1 << (j - 1))][j - 1]);
        }
    }

    // for (int i = 0; i <= n; ++i) cout << _gcd[i][2] << " ";
}

int gcdQuery(int l, int r)
{
    int k = log2(r - l + 1);
    return gcd(_gcd[l][k], _gcd[r - (1 << k) + 1][k]);
}

struct Query
{
    int l, r, v, id;
};

vector<Query> queries;

void solve()
{
    int n, q;
    cin >> n >> q;
    rep(i, 0, n) cin >> a[i];
    
    buildTable(n);
    rep(i, 0, q)
    {
        int l, r, v;
        cin >> l >> r >> v;
        --l, --r;
        queries.pb({l, r, v, i});
    }

    sort(all(queries), [&] (Query a, Query b) {
        return a.v > b.v;
    });

    map <int, vector<int>> mp;
    rep(i, 0, n)
    {
        int lo = i, hi = n - 1, mid, ans = n + 1;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (gcdQuery(i, mid) <= queries[0].v)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        f[i] = ans;
        int _gcd = gcdQuery(i, ans);
        update(i + 1, f[i], n);
        mp[_gcd].pb(i);
    }

    map <int, vector<int>> :: iterator it = --mp.end();

    rep(i, 0, q)
    {
        int ll = queries[i].l, rr = queries[i].r;

        while (it->first > queries[i].v && it != mp.end())
        {
            for (auto val : it->second) {
                int lo = val, hi = n - 1, mid, ans = n - 1;
                while (lo <= hi)
                {
                    mid = (lo + hi) / 2;
                    if (gcdQuery(val, mid) <= queries[i].v)
                    {
                        ans = mid;
                        hi = mid - 1;
                    }
                    else
                    {lo = mid + 1;
                    }
                }
   
                update(val + 1, -f[val], n);
    
                int _gcd = gcdQuery(val, ans);

                if (_gcd > queries[i].v) {
                    f[val] = n + 1; 
                    continue;
                }

                f[val] = ans;
                update(val + 1, f[val], n);
                mp[_gcd].pb(val);
                // dbg(val, f[val], _gcd, queries[i].v);
            }


            it--;
        }

        int pos = upper_bound(f, f + n, rr) - f - 1;
        int res = (pos - ll + 1) * (rr + 1) - get(pos + 1) + get(ll);
        if (pos < ll || pos > rr) res = 0;
        // dbgv(f, n);
        // dbg (ll, rr, pos, gl, gr, res, queries[i].v);
        ans[queries[i].id] = res;
    }

    rep(i, 0, q) cout << ans[i] << "\n";
}
