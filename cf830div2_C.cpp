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


void solve();

// #define LOCAL;

int32_t main() {

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    time_t start = clock();

    int t;
    cin >> t;
    while (t--)
        solve();

    cerr << "Time elapsed: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s.\n";
    return 0;
}

const int INF = 0x3f3f3f3f3f;


void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int l, r;
    cin >> l >> r;

    int initSum = 0, initXor = 0;
    for (int i = l-1; i < r; ++i) {
        initSum += a[i];
        initXor ^= a[i];
    }

    int res = 0, lf = 0, rt = n-1;

    l = 0;
    int sum = 0, xorSum = 0;

    for (int i = 0; i < n; ++i)
    {
        // dbg(l, i, sum, xorSum);
        if (sum + a[i] - (xorSum ^ a[i]) != initSum - initXor) {
            sum += a[i];
            xorSum ^= a[i];
            continue;
        }

        sum += a[i];
        xorSum ^= a[i];

        bool ok = false;
        while (l < i) {
            if (sum - a[l] - (xorSum ^ a[l]) == initSum - initXor) {
                sum -= a[l];
                xorSum ^= a[l];
                ok = true;
                ++l;
                continue;
            }
            break;
        }


        dbg (l, i, sum, xorSum);
        if (i - l < rt - lf) {
            lf = l;
            rt = i;
        }
    }

    while (l < n - 1) {
        if (sum - a[l] - (xorSum ^ a[l]) == initSum - initXor) {
            sum -= a[l];
            xorSum ^= a[l];
            ++l;
            continue;
        }
        break;
    }

    if (n - l - 1 < rt - lf) {
        lf = l;
        rt = n-1;
    }

    cout << lf+1 << " " << rt+1 << endl;
}