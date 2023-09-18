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
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f;

int k, q, n;
vector<int> a(n);

int F(int l, int r)
{
    int mid = (l + r) / 2;
    int lf = mid - 1, rg = mid;
    int suf[mid-l+2], pre[r-mid+1];
    memset(suf, 0, sizeof(suf));
    for (int i = mid-l; i >= 0; --i, lf--) {
        sub[i] = a[lf];
    }

    sort(suf, suf + mid - l + 1);

    int res = 0;
    for (int i = 1; i <= r - mid; ++i) {
        int pos = upper_bound(suf, suf + mid - l + 1, q-pre[i])-suf;
        
        // cout << pre[i] << " " << suf[pos] << "\n";
        if (pos == 0) continue;
        pos--;
        cout << pre[i] << " " << suf[pos] << "\n";
        if (i + pos + 1 >= k && pre[i] + suf[pos] <= q) {
            res += (i + pos + 2 - k);
        }
    }
    return res;
}

int Cal(int l, int r)
{
    if (l == r) {
        if (a[l-1] <= q && k == 1) return 1;
        return 0;
    }

    int mid = (l + r) / 2;
    int v1 = Cal(l, mid);
    int v2 = Cal(mid + 1, r);

    int ret = v1 + v2 + F(l, r);
    return ret;
}

void solve()
{
    cin >> n >> k >> q;\
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= q) {
            cnt++;
        } else {

        }
    }
}
