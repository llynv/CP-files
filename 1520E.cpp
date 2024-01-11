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
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator>>(ostream &is, const T_container &v) { for (auto &c : v) is >> c; }
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
    string s;
    cin >> s;
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            pos.push_back(i+1);
        }
    }
    vector<int> pre(sz(pos)+1);
    if (pos.empty() || sz(pos) == n) return void (cout << "0\n");
    for (int i = 1; i <= sz(pos); ++i) pre[i] = pre[i-1] + pos[i-1];
    int ans = INF;
    for (int i = 1; i <= n-sz(pos)+1; ++i) {
        int l = i, r = i + sz(pos) - 1;
        int acp = i;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pos[mid-i] <= mid) {
                l = mid + 1;
                acp = mid;
            } else {
                r = mid - 1;
            }
        }
        int cur = acp, rend = i+sz(pos)-1;
        // dbg(i, cur, rend);
        // dbg(pre[cur-i+1] - cur * (cur+1) / 2 - i*(i-1)/2 + r*(r+1)/2 - cur*(cur+1)/2 - - pre[rend-i+1] + pre[cur-i+1]);
        ans = min(ans, abs(cur*(cur+1)/2 - i*(i-1)/2 - pre[cur-i+1]) + abs(pre[rend-i+1] - pre[cur-i+1] - rend*(rend+1)/2 + cur*(cur+1)/2)); 
        // dbg(ans);
    }
    // dbg("break");
    cout << ans << endl;
}
