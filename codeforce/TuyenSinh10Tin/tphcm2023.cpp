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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    sort(a.begin(), a.end());
    // dbg(a);
    int lo = 0, hi = 1e9 + 7, mid, ans = 0;
    while (lo <= hi)    
    {
        mid = (lo + hi) / 2;
        int cnt = 1;
        int pos = (upper_bound(a.begin(), a.end(), 2 * mid + a[0]) - a.begin()) - 1;
        // dbg(pos);
        while (pos < n - 1)
        {
            int start = a[pos+1];
            pos = (upper_bound(a.begin(), a.end(), 2 * mid + start) - a.begin()) - 1;
            cnt++;
            // dbg(pos, a[pos + 1]);
        }

        if (cnt <= k) {
            hi = mid - 1;
            ans = mid;
        } else {
            lo = mid + 1;
        }
        
    }
    cout << ans;
}
