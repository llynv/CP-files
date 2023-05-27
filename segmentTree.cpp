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

const int N = 200007;

int it[4 * N];
int a[N];

void build (int index, int l, int r)
{
    if (l == r) {
        it[index] = a[l-1];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    it[index] = min(it[2 * index], it[2 * index + 1]);
}

int get (int index, int L, int R, int l, int r)
{
    if (R < l || L > r) return LONG_LONG_MAX;
    if (l <= L && R <= r) {
        return it[index];
    }
    int mid = (L + R) / 2;

    int v1 = get(2 * index, L, mid, l, r);
    int v2 = get(2 * index + 1, mid + 1, R, l, r);
    return min(v1, v2);
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
 
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    build(1, 1, n);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, n, l, r) << "\n";
    }
    return 0;
}