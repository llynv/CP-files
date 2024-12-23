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
#define endl "\n"
#define fill(x, y) memset(x, y, sizeof(x))

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
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
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int N = 2e5 + 7;
const int M = 1e9 + 7;

// struct Segtree
// {
//     int val;
//     vector<int> pos;
// };

// Segtree it[4 * N];
int n, q, a, sum[N];

// int dis (int l, int r)
// {
//     return (r);
// }

// void lazyUpdate (int index, int L, int R)
// {
//     if (it[index].pos.empty()) return;
//     if (L != R) {
//         it[index * 2].pos.insert(it[index * 2].pos.end(), all(it[index].pos));
//         it[index * 2 + 1].pos.insert(it[index * 2 + 1].pos.end(), all(it[index].pos));

//         for (auto c : it[index].pos) {
//             it[index * 2].val += (sum[(L + R) / 2] - sum[L-1] + (((L + R) / 2 - L + 1) * c) % M * c) % M;
//             it[index * 2 + 1].val += sum[R] - sum[(L + R) / 2] + (((R - (L + R) / 2) * c) % M * c) % M;
//         }
//     }
//     it[index].pos.clear();
// }

// void update (int index, int L, int R, int u, int v, int pos)
// {
//     lazyUpdate(index, L, R);
//     if (v < L || R < u) return;
//     if (u <= L && R <= v) {
//         it[index].val += sum[R] - sum[L-1] + (((R - L + 1) * pos) % M * pos) % M;
//         it[index].pos.pb(pos);
//         lazyUpdate(index, L, R);
//         return;
//     }
//     int mid = (L + R) / 2;
//     update(index * 2, L, mid, u, v, pos);
//     update(index * 2 + 1, mid + 1, R, u, v, pos);
//     it[index].val = it[index * 2].val + it[index * 2 + 1].val;
// }

// void deleteUpdate(int index, int L, int R, int u, int v)
// {
//     if (v < L || R < u) return;
//     if (u <= L && R <= v) {
//         it[index].val = 0;
//         it[index].pos.clear();
//         return;
//     }
//     int mid = (L + R) / 2;
//     deleteUpdate(index * 2, L, mid, u, v);
//     deleteUpdate(index * 2 + 1, mid + 1, R, u, v);
//     it[index].pos.clear();
//     it[index].val = 0;
// }

// int get (int index, int L, int R, int u, int v)
// {
//     if (v < L || R < u) return 0;
//     if (u <= L && R <= v) return it[index].val;
//     int mid = (L + R) / 2;
//     return get(index * 2, L, mid, u, v) + get(index * 2 + 1, mid + 1, R, u, v);
// }

int calc(int k)
{
    return k * (k + 1) * (2 * k + 1) / 6;
}

void solve()
{
    cin >> n >> q >> a;
    int total = 0;
    bool isAvai = false;
    int cnt = 0;
    while (q--)
    {
        int t, l, r, k;
        cin >> t >> l >> r;
        if (t == 2) {
            for (int i = 1; i <= n; ++i) {
                sum[i] += sum[i-1];
            }
            cnt = sum[l];
            for (int i = 1; i <= n; ++i) sum[i] = 0;
            cout << ((a % M * a % M + sqr(l - 1) % M) * cnt) % M << "\n";
            cnt = 0;
        } else {
            cin >> k;
            sum[l-1]++;
            sum[r]--;
        }
    }
    
}
