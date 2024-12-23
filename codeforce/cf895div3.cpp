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
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int N = 2e5 + 7;

// vector<ii> it[N * 4], opit[N * 4];
// struct SegmentTree
// {
//     int amt, updateAmt;
// };
// SegmentTree st[N * 4];

// int a[N], s[N];

// void build (int index, int L, int R)
// {
//     if (L == R) {
//         if (s[L] == 1) {
//             it[index].pb({L, R});
//         } else {
//             opit[index].pb({L, R});
//         }
//         st[index].amt = 0;
//         st[index].updateAmt = 0;
//         return;
//     }
//     int mid = (L + R) >> 1;
//     build(index * 2, L, mid);
//     build(index * 2 + 1, mid + 1, R);

//     vector<ii> v(it[2 * index].size() + it[2 * index + 1].size());
//     if (!v.empty()) {
//         merge(it[index * 2].begin(), it[index * 2].end(), it[index * 2 + 1].begin(), it[index * 2 + 1].end(), v.begin());
//         int start = v[0].fi;
//         v.push_back({-1, -1});
//         for (int i = 0; i < sz(v) - 1; ++i) {
//             if (v[i].se != v[i+1].fi - 1) {
//                 it[index].push_back(make_pair(start, v[i].se));
//                 start = v[i+1].fi;
//             }
//         }
//     }

//     vector<ii> v2(opit[2 * index].size() + opit[2 * index + 1].size());
//     if (!v2.empty()) {
//         merge(opit[index * 2].begin(), opit[index * 2].end(), opit[index * 2 + 1].begin(), opit[index * 2 + 1].end(), v2.begin());
//         int start = v2[0].fi;
//         v2.push_back({-1, -1});
//         for (int i = 0; i < sz(v2) - 1; ++i) {
//             if (v2[i].se != v2[i+1].fi - 1) {
//                 opit[index].push_back(make_pair(start, v2[i].se));
//                 start = v2[i+1].fi;
//             }
//         }
//     }
//     // dbg(index, it[index], opit[index]);
// }

// void lazyUpdate (int index, int L, int R)
// {
//     int k = st[index].updateAmt;
//     st[2 * index].amt += k;
//     st[2 * index].updateAmt += k;
//     st[2 * index + 1].amt += k;
//     st[2 * index + 1].updateAmt += k;
//     st[index].updateAmt = 0;
// }

// void update (int index, int L, int R, int u, int v, int val)
// {
//     if (L > v || R < u) return;
//     if (L >= u && R <= v) {
//         swap(it[index], opit[index]);
//         return;
//     }
//     int mid = (L + R) >> 1;
//     update(index * 2, L, mid, u, v, val);
//     update(index * 2 + 1, mid + 1, R, u, v, val);

// }

// int get (int index, int L, int R, int u)
// {
// }

constexpr unsigned low_mask(unsigned x){
  return (1u<<x)-1;
}

constexpr unsigned mask(unsigned width, unsigned offset){
  return low_mask(width+offset)-low_mask(offset);
}

bitset<N> bs, tmp;

int getFirstSetBitPos(int n)
{
    if (n == 0) return 0;
    return log2(n & -n) + 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == '1') bs[i] = 1;
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            bs ^= (mask(r - l + 1, l - 1));
        } else {
            int g;
            cin >> g;
            tmp = bs;
            if (g == 0) {
                tmp.flip();
                int i = getFirstSetBitPos(tmp);
                int res = 0;
                while (i != 0) {
                    res ^= a[i-1];
                    tmp[i-1] = 0;
                    i = getFirstSetBitPos(tmp);
                }
                cout << res << endl;
            }
        }
    }
}
