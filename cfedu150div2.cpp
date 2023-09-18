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
#define endl "\n";
#define fill(x, y) memset(x, y, sizeof(x))

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }


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
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f;

const int N = 2e5 + 5;
int num[] = {1LL, 10LL, 100LL, 1000LL, 10000LL};

void solve()
{
    string s;
    cin >> s;

    vector<int> maxVal (sz(s), 0);
    vector<int> sum (sz(s) + 1, 0), cntE (sz(s) + 1, 0), posSum (sz(s) + 1, 0);

    per(i, 0, sz(s) - 1) {
        int id = s[i+1] - 'A';
        maxVal[i] = max(maxVal[i + 1], num[id]);
    }
    // dbg(maxVal);
    cntE[0] = (s[0] == 'E');
    rep(i, 1, sz(s)) 
        cntE[i] = cntE[i-1] + (s[i] == 'E');

    rep (i, 1, sz(s)+1) {
        int id = s[i-1] - 'A';
        sum[i] = sum[i - 1] + (maxVal[i-1] > num[id] ? -num[id] : num[id]);
        posSum[i] = posSum[i-1] + (num[id] == 10000LL ? num[id] : 0);
    }
    int total = sum[sz(s)];
    // dbg(posSum);
    rep (i, 0, sz(s)) {
        if (s[i] != 'E') {
            int cur = (sum[sz(s)] - sum[i+1]) + 10000LL + posSum[i];
            // dbg(i, cur);
            total = max(total, cur);
            // cout << sum[sz(s)] << " " << sum[i+1] << " " << posSum[i] << "\n";
        }
    }
    cout << total << "\n";
}
