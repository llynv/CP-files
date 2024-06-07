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


unordered_map<string, int> dist;

void solve()
{   
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int sum = a + b + c + d + e;
    string s;
    for (int i = 0; i < sum; ++i) {
        if (a) {
            s += '1';
            a--;
            continue;
        }
        if (b) {
            s += '0';
            b--;
            continue;
        }
        if (c) {
            s += '1';
            c--;
            continue;
        }
        if (d) {
            s += '0';
            d--;
            continue;
        }
        if (e) {
            s += '1';
            e--;
            continue;
        }
    }

    int q;
    cin >> q;
    vector<int> l(q), r(q);
    rep (i, 0, q) cin >> l[i] >> r[i];
    
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    pq.push({1LL, s});
    dist[s] = 1;


    string ans = "";
    for (int j = 0; j < sum; ++j) ans += '1';
    string cbit = ans;

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if (cur.second == ans) return cout << dist[ans] - 1, void();

        for (int i = 0; i < q; ++i) {
            for (int j = 0; j < sum; ++j) {
                if (j < l[i] - 1 || j > r[i] - 1) {
                    cbit[j] = cur.second[j];
                    continue;
                }
                cbit[j] = (cur.second[j] == '1' ? '0' : '1');
            }
            if (dist[cbit] == 0 || dist[cbit] > cur.first + (r[i] - l[i] + 1)) {
                dist[cbit] = cur.first + (r[i] - l[i] + 1);
                pq.push({cur.first + (r[i] - l[i] + 1), cbit});
            }
        }
    }
    // dbg(bit);

    // dbg(ans);
    return cout << "-1\n", void();
}
