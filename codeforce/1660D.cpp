#include <bits/stdc++.h>
using namespace std;

// #define LINVG
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



const int INF = 0x3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+2);
    rep (i, 1, n+1) cin >> a[i];
    vector<int> Zpos;
    for (int i = 0; i < n+2; ++i) {
        if (a[i] == 0) Zpos.pb(i);
    }

    int res = 1, lft = 0, rgt = n;
    for (int i = 1; i < sz(Zpos); ++i) {
        int l = Zpos[i-1], r = Zpos[i];
        unordered_map<int, int> nev, mul;
        int cnt = 0;
        mul[l] = 1;
        for (int j = l+1; j < r; ++j) {
            mul[j] = mul[j-1] + (abs(a[j]) == 2 ? 2 : 0);
        }
        for (int j = l+1; j < r; ++j) {
            if (a[j] < 0) {
                cnt++;
                nev[cnt] = j;
            }
            if (cnt & 1) {
                dbg(j, mul[j], mul[nev[1]]);
                // res = max(res, mul[j+1] / mul[nev[1]]);
                if (res < (mul[j] - mul[nev[1]])) {
                    res = (mul[j] - mul[nev[1]]);
                    lft = nev[1];
                    rgt = n-j;
                }
            } else {
                dbg(j, mul[j]);
                if (res < mul[j]) {
                    res = mul[j];
                    lft = l;
                    rgt = n-j;
                }
            }
        }
    }
    // dbg("END\n");
    cout << lft << " " << rgt << endl;
}



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