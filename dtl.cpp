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
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int N = 1e6 + 7;

vector<int> primes;

bitset<N> check;
vector<int> single;

void sieve()
{
    check[0] = check[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!check[i]) {
            for (int j = i*i; j < N; j += i) {
                check[j] = 1;
            }
        }
    }
    for (int i = 2; i < N; ++i) {
        if (!check[i]) {
            primes.push_back(i);
        }
    }

    for (int i = 0; i < sz(primes); ++i) {
        for (int j = i+1; j < sz(primes) and primes[i] * primes[j] <= N; ++j) {
            single.push_back(primes[i] * primes[j]);
        }
    }

    sort(all(single));
}

void solve()
{
    sieve();

    // dbg(primes);

    int n;
    cin >> n;
    rep (i, 0, n) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ly = lower_bound(all(primes), a) - primes.begin();
        int ry = upper_bound(all(primes), c) - primes.begin();

        int lx = lower_bound(all(primes), b) - primes.begin();
        int rx = upper_bound(all(primes), d) - primes.begin();

        // dbg(a, b, c, d);
        // dbg(ly, ry, lx, rx);

        int res = 0;
        if (a == 1) {
            int l = lower_bound(all(single), b) - single.begin();
            int r = upper_bound(all(single), d) - single.begin();
            // dbg(i, ":", l, r);
            res += r - l;
        } 

        if (b == 1) {
            int l = lower_bound(all(single), a) - single.begin();
            int r = upper_bound(all(single), c) - single.begin();
            // dbg(i, ":", l, r);
            res += r - l;
        }

        int same = 0;
        if (lx >= ly && lx <= ry) {
            same = min(rx, ry) - lx;
        } else if (rx >= ly && rx <= ry) {
            same = min(rx, ry) - ly;
        } else if (ly >= lx && ly <= rx) {
            same = min(ry, rx) - ly;
        } else if (ry >= lx && ry <= rx) {
            same = min(ry, rx) - lx;
        }
        // dbg(same);
        cout << res + (ry - ly) * (rx - lx) - same << "\n";
    }
}
