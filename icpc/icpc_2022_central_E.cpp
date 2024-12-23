#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long
#define float double
#define db double
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back

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
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f;
const float C = 0.000000000001;

float Cal(float x, vector<float> a, vector<float> b)
{
    float res = 0.0;
    for (int i = 0; i < n; ++i) {
        res += sqr(a[i] - x * b[i]);
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &c : a) cin >> c;
    for (auto &c : b) cin >> c;
    vector<float> val(n);
    for (int i = 0; i < n; ++i) {
        val[i] = db(a[i]) / db(b[i]);
    }

    dbg(val);
    
    vector<double> tmp;
    tmp.emplace_back(val[0]);
    for (int i = 1; i < n; ++i) {
        tmp.emplace_back(val[i]);
        if (val[i] > val[i-1]) {
            
        }
    }

    if (val[n - 1] > val[n - 2]) val[n - 1] = val[n - 2];

    val[0] = val[1] = 0.951389;

    val[2] = val[3] = val[4] = 0.307692;

    dbg(val);


}
