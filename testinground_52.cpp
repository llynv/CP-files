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

void solve()
{
    int n;
    cin >> n;
    stack<int> st;
    queue<int> q;
    int res = 0;

    rep (i, 0, n) {
        int x;
        cin >> x;
        res = max(res, x);
        st.push(x);
        q.push(x);
        while (st.size() > 1) {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (a == b) {
                st.push(a+1);
                res = max(res, a+1);
            }
            else {
                st.push(b);
                st.push(a);
                break;
            }
        }

        while (q.size() > 1) {
            int a = q.back();
            q.pop();
            int b = q.back();
            q.pop();
            if (a == b) {
                q.push(a+1);
                res = max(res, a+1);
            }
            else {
                q.push(b);
                q.push(a);
                break;
            }
        }
    }

    while (!st.empty()) {
        res = max(res, st.top());
        st.pop();
    }

    while (!q.empty()) {
        res = max(res, q.front());
        q.pop();
    }

    cout << res;

    // int n, k;
    // cin >> n >> k;
    // rep (i, 0, k) {
    //     int s, t, r;
    //     cin >> s >> t >> r;
    //     int pg = s * t;
    //     int rt = n / pg;
    //     int rm = n - rt * pg;
    //     int time = rt * (t + r);
    //     if (n % pg == 0) {
    //         time -= r;
    //     }
    //     // dbg(time, rm);
    //     cout << time + (int)ceil (double(rm) / double(s)) << "\n";
    // }

    // int n, l;
    // cin >> n >> l;
    // priority_queue<ii, vector<ii>, greater<ii>> pq;
    // vector<ii> a(n);
    // rep (i, 0, n) {
    //     cin >> a[i].fi >> a[i].se;
    //     pq.push(a[i]);
    // }
    // int lo = 0, hi = 1e14, mid, ans = pq.top().fi;
    // while (lo <= hi) {
    //     int L = l;
    //     mid = lo + (hi - lo) / 2;
    //     priority_queue<ii, vector<ii>, greater<ii>> pq2 = pq;
    //     while (pq2.top().fi < mid) {
    //         ii c = pq2.top();
    //         pq2.pop();
    //         int stp = (int)ceil(double(mid - c.fi) / double(c.se));
    //         c.fi += stp * c.se;
    //         L -= stp;
    //         pq2.push(c);
    //     }
        
    //     if (L >= 0) {
    //         ans = max(ans, pq2.top().fi);
    //         lo = mid + 1;
    //     } else {
    //         hi = mid - 1;
    //     }
    // }
    // cout << ans << "\n";
}
