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
const int N = 3e5 + 7;

int it[N] = {INF};


// void build (int index, int L, int R)
// {
//     if (L == R) {
//         it[index] = (eachsum[L-1] == 0 ? INF : eachsum[L-1]);
//         return;
//     }
//     int mid = (L + R) / 2;
//     build(index * 2, L, mid);
//     build(index * 2 + 1, mid + 1, R);
//     it[index] = min(it[index * 2], it[index * 2 + 1]);
// }

// void update (int index, int L, int R, int pos, int val)
// {
//     if (L > pos || R < pos) return;
//     if (L == R) {
//         it[index] = val;
//         return;
//     }
//     int mid = (L + R) / 2;
//     update(index * 2, L, mid, pos, val);
//     update(index * 2 + 1, mid + 1, R, pos, val);
//     it[index] = min(it[index * 2], it[index * 2 + 1]);
// }

// int get (int index, int L, int R, int l, int r)
// {
//     if (L > r || R < l) return INF;
//     if (L >= l && R <= r) {
//         return it[index];
//     }
//     int mid = (L + R) / 2;
//     return min(get(index * 2, L, mid, l, r), get(index * 2 + 1, mid + 1, R, l, r));
// }

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> type(n);
    for (auto &c : type) cin >> c;
    vector<int> amt(n);
    for (int i = 0; i < n; ++i) cin >> amt[i];
    vector<int> cnt(n+1), check(k+1), sum(n+1);
    // eachsum.assign(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        cnt[i] = cnt[i-1] + (!check[type[i-1]]);
        check[type[i-1]] = 1;

        sum[i] = sum[i-1] + amt[i-1];
    }
    // build(1, 1, n);
    // int ans = 0;
    // int f1 = (upper_bound(cnt.begin(), cnt.end(), cnt[1] + k - 2) - cnt.begin()) - 1;
    // int f2 = (upper_bound(cnt.begin(), cnt.end(), cnt[1] + k - 1) - cnt.begin()) - 1;
    // for (int i = 0; i < f2; ++i) {
    //     eachsum[type[i]] += amt[i];
    // }
    // int minVal = INF;
    // for (int i = 1; i <= k; ++i) {
    //     if (eachsum[i] != 0)
    //         minVal = min(minVal, eachsum[type[i]]);
    // }
    // int imax = f2;
    int ans = 0;
    // dbg(eachsum);
    for (int i = 1; i <= n; ++i) {
        vector<int> eachsum(n+1);
        eachsum[type[i-1]] += amt[i-1];
        int pos = -1;
        
        int f1 = (upper_bound(cnt.begin(), cnt.end(), cnt[1] + k - 2) - cnt.begin()) - 1;
        int f2 = (upper_bound(cnt.begin(), cnt.end(), cnt[1] + k - 1) - cnt.begin()) - 1;

        for (int j = i + 1; j <= f1 + 1; ++j) {
            eachsum[type[j-1]] += amt[j-1];
        }

        int minVal = INF;
        ans = max(ans, sum[f1] - sum[i-1]);
        if (cnt[f2] - cnt[i] + 1 == k) {
            for (int j = 1; j <= k; ++j) {
                if (eachsum[j] != 0)
                    minVal = min(minVal, eachsum[j]);
            }
            
        }
        // dbg(eachsum, minVal);
    }
    cout << ans << "\n";
}
