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
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int N = 2e5 + 7; 

int fw[10][N], a[N];
int n, q;

void update_d (int x, int y, int val)
{
    for (; x < N; x += x & -x)
        fw[y][x] += val;
}

int get_div (int x, int y)
{
    int res = 0;
    for (; x; x -= x & -x)
        res += fw[y][x];
    return res;
}

void solve()
{
    cin >> n >> q;
    rep (i, 1, n+1) cin >> a[i];

    rep (i, 1, n+1)
    {
        update_d(i, 0, a[i]);
        for (int j = 1; j < 10; ++j)
        {
            if (i % j == 0)
                update_d(i, j, a[i]);
            else {
                int tmp = i;
                bool isHas = false;
                while (tmp) {
                    if (tmp % 10 == j) {
                        isHas = true;
                        break;
                    }
                    tmp /= 10;
                }

                if (isHas) {
                    update_d(i, j, a[i]);
                }
            }
        }
    }

    rep (i, 0, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int idx, val;
            cin >> idx >> val;
            // update_d(idx, 0, val);
            update_d(idx, 0, val-a[idx]);
            rep (j, 1, 10) {
                if (idx % j == 0) {
                    update_d(idx, j, val-a[idx]);
                    // update_d(idx, j, val);
                }
                else {
                    int tmp = idx;
                    bool isHas = false;
                    while (tmp) {
                        if (tmp % 10 == j) {
                            isHas = true;
                            break;
                        }
                        tmp /= 10;
                    }

                    if (isHas) {
                        update_d(idx, j, val-a[idx]);
                    }
                }
            }
            a[idx] = val;
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            cout << get_div(r, k) - get_div(l-1, k) + get_div(r, 0) - get_div(l-1, 0) << "\n";
        }
    }
}
