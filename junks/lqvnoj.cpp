#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long
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


int fastPow(int a, int b)
{
    if (b == 1) return a;
    if (b == 0) return 1;

    if (b & 1) {
        int v1 = fastPow(a, (b-1) / 2);
        return v1 * v1 * a;
    } 
    int v2 = fastPow(a, b / 2);
    return v2 * v2;
}

void solve(int t);

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
 
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }

    return 0;
}

double nRoot (int n, int x)
{
    return pow(x, 1.0 / n);
}

void solve(int t)
{
    int a, b;
    cin >> a >> b;
    int lo = 1, hi = log2(b), k = 0;
    // cout << calLog(2, 16) << "\n";


    int res = 0;
    for (int i = 1; i <= hi; ++i) {
        for (int j = nRoot(i, b) + 1; j >= 0; --j) {
            if (fastPow(j, i) >= a && fastPow(j, i) <= b) {
                res = max(res, i);
                break;
            }

            if (fastPow(j, i) < b) break;   
        }
    }

    cout << "Case #" << t << ": " << res << "\n";
}
