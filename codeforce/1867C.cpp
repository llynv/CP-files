#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
    ordered_set;

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

// #define LOCAL

int32_t main() {

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

#define LINVG

const int INF = 0x3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    ordered_set s;
    rep(i, 0, n) {
        int x;
        cin >> x;
        s.insert(x);
    }
    int l = 0, r = sz(s)-1, ans = -1;
    if (*s.find_by_order(0) > 0) {
        cout << 0 << "\n";
        ans = 0;
        s.insert(0);
        cout.flush();
    } else {
        while (l <= r) {
            int mid = (l+r)>>1;
            if (*s.find_by_order(mid) > mid) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
                ans = mid;
            }
        }
        cout << *s.find_by_order(ans) + 1 << "\n"; 
        s.insert(*s.find_by_order(ans) + 1);
        ans = *s.find_by_order(ans) + 1;
        cout.flush();
    }

    int y;
    cin >> y;

    while (true) {

        if (y == -1) return;
        if (y == -2) exit(0);

        s.erase(s.find(y));

        if (*s.find_by_order(0) != 0) {
            cout << 0 << "\n";
            s.insert(0);
            cout.flush();
        } else {
            l = 0, r = sz(s)-1, ans = sz(s);
            while (l <= r) {
                int mid = (l+r) / 2;
                if (*s.find_by_order(mid) > mid) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                    ans = mid;
                }
            }
            cout << *s.find_by_order(ans) + 1 << "\n"; 
            s.insert(*s.find_by_order(ans) + 1);
            cout.flush();
        }

        cin >> y;
    }
}
