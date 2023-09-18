#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long
#define ll(...) (long long)(__VA_ARGS__)
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

const int N = 2e5 + 7;

int a[N];

struct segment
{
    int count, countLeft, countRight;
};

segment it [4 * N];

void build (int index, int L, int R)
{
    if (L == R) {
        it[index].count = 1;
        it[index].countLeft = 1;
        it[index].countRight = 1;
        return;
    }

    int mid = (L + R) / 2;
    build (index << 1, L, mid);
    build (index << 1 | 1, mid + 1, R);

    it[index].count = it[index << 1].count + it[index << 1 | 1].count;
    it[index].countLeft = it[index << 1].countLeft;
    it[index].countRight = it[index << 1 | 1].countRight; 

    if (it[index << 1].countLeft == mid - L + 1 && a[mid] <= a[mid+1])
        it[index].countLeft += it[index << 1 | 1].countLeft;
    if (it[index << 1 | 1].countRight == R - mid && a[mid] <= a[mid+1])
        it[index].countRight += it[index << 1].countRight;
    if (a[mid] <= a[mid+1])
        it[index].count += it[index << 1].countRight * it[index << 1 | 1].countLeft;
}

void update (int index, int L, int R, int pos, int val)
{
    if (L == R) {
        return;
    }

    int mid = (L + R) / 2;

    if (pos <= mid)
        update (index << 1, L, mid, pos, val);
    else
        update (index << 1 | 1, mid + 1, R, pos, val);

    it[index].count = it[index << 1].count + it[index << 1 | 1].count;
    it[index].countLeft = it[index << 1].countLeft;
    it[index].countRight = it[index << 1 | 1].countRight; 

    if (it[index << 1].countLeft == mid - L + 1 && a[mid] <= a[mid+1])
        it[index].countLeft += it[index << 1 | 1].countLeft;
    if (it[index << 1 | 1].countRight == R - mid && a[mid] <= a[mid+1])
        it[index].countRight += it[index << 1].countRight;
    if (a[mid] <= a[mid+1])
        it[index].count += it[index << 1].countRight * it[index << 1 | 1].countLeft;
}

int res = 0, strk = 0;

void get(int index, int L, int R, int l, int r)
{
    if (R < l || r < L) return;

    if (l <= L && R <= r) {

        res += it[index].count;
        if (strk != 0) {
            if (a[L-1] <= a[L]) {
                res += strk * it[index].countLeft;
                if (it[index].countLeft == R - L + 1) {
                    strk += (R - L + 1);   
                } else {
                    strk = it[index].countRight;
                }
            } else {
                strk = it[index].countRight;
            }
        } else {
            strk = it[index].countRight;
        }
        return;
    }

    int mid = (L + R) / 2;
    get(index << 1, L, mid, l, r);
    get(index << 1 | 1, mid + 1, R, l, r);
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 0; i < m; ++i) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            a[x] = y;
            update(1, 1, n, x, y);
        } else {
            res = 0;
            strk = 0;
            get(1, 1, n, x, y);
            cout << res << "\n";
        }
    }



    return 0;
}   