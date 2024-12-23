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
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> store;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        store[a[i]].pb(i);
    }

    auto nCr = [&] (int n, int r) {
        if (r > n) return 0LL;
        if (r * 2 > n) r = n-r;
        if (r == 0) return 1LL;

        int res = n;
        for (int i = 2; i <= r; ++i) {
            res *= (n-i+1);
            res /= i;
        }
        return res;
    };

    map<ii, int> ans;
    
    int q;
    cin >> q; 
    rep (i, 0, q) {
        int x, y;
        cin >> x >> y;  
        int delta = x*x - 4*y;
        bool ok1 = false, ok2 = false, ok3 = false;
        ok1 = (delta >= 0 && delta == (int)sqrt(delta) * (int)sqrt(delta));
        ok2 = (x + (int)sqrt(delta)) % 2 == 0;
        ok3 = (x - (int)sqrt(delta)) % 2 == 0;
        if (!ok1 || !ok2 || !ok3) {
            cout << "0 ";
            continue;
        }
        int b1 = (x + (int)sqrt(delta)) / 2;
        int b2 = (x - (int)sqrt(delta)) / 2;


        int a1 = x - b1;
        int a2 = x - b2;

        if (b1 == b2) {
            a2 = -1;
        }

        int res = 0;

        if (a1 == b1 || a2 == b2) {
            int val = store[b1].size();
            res += nCr(val, 2ll);
            if (a2 != -1) {
                val = store[b2].size();
                res += nCr(val, 2ll);
            }
            cout << res << " ";
            continue;
        }

        
        ii tmp = {a1, b1};
        ii tmp2 = {a2, b2};

        if (ans.find(tmp) != ans.end()) {
            cout << ans[tmp] << " ";
            continue;
        }


        if (store.find(a1) != store.end() && store.find(a2) != store.end()) {
            vector<int> &v1 = store[a1];
            // dbg(v1);
            vector<int> &v2 = store[b1];
            for (auto c : v1) {
                int pos = lower_bound(all(v2), c)-v2.begin();
                if (pos == v2.size()) break;
                res += (v2.size() - pos);
                // dbg(c, pos, v2, a1, b1);
            }
        }
        if (store.find(a1) != store.end() && store.find(b2) != store.end()) {
            vector<int> &v1 = store[a2];
            // dbg(v1);
            vector<int> &v2 = store[b2];
            for (auto c : v1) {
                int pos = lower_bound(all(v2), c)-v2.begin();
                if (pos == v2.size()) break;
                res += (v2.size() - pos);
                // dbg(c, pos, v2, a2, b2);
            }
        }

        ans[tmp] = res;
        cout << res << " ";
    }
    cout << "\n";
}

