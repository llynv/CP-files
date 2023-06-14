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

struct seg
{
    int value, valPos;
    bool Sub, Add;
};

const int N = 2e5 + 7;

seg it[4 * N];


int CalSum(int x)
{
    return (x+1)*(x+2)*(x+3)*(x+4)/4;
}

void LazyAddUpdate(int index)
{
    int id = it[index].valPos;
    it[2 * index].value += CalSum(id / 2);
    it[2 * index].valPos = id / 2;
    it[2 * index].Add = 1;
    it[2 * index + 1].value += (CalSum(id) - CalSum(id / 2));
    it[2 * index + 1].valPos = id;
    it[index].left = 0;
    it[index].right = 0;
}

void LazySubUpdate(int index)
{
    int l = it[index].left;
    int r = it[index].right;
    int mid = (r - l);
    it[2 * index].value -= CalSum(mid / 2);
    it[2 * index].left = l;
    it[2 * index].right = r / 2;
    it[2 * index + 1].value -= (CalSum(mid) - CalSum(mid / 2));
    it[2 * index + 1].left = r / 2 + 1;
    it[2 * index + 1].right = r;
    it[index].left = 0;
    it[index].right = 0;
}

void updateAdd(int index, int L, int R, int l, int r)
{
    LazyAddUpdate(index);
    if (R < l || L > r) return;
    if (l <= L && R <= r) {
        it[index].value += CalSum(r - l - 1);
        it[index].left = l;
        it[index].right = r;
        LazyAddUpdate(index);
        return;
    }

    int mid = (L + R) / 2;
    updateAdd(2 * index, L, mid, l, r);
    updateAdd(2 * index + 1, mid + 1, R, l, r);
    it[index].value = it[2 * index].value + it[2 * index + 1].value;
}

void updateSub(int index, int L, int R, int l, int r)
{
    LazySubUpdate(index);
    if (R < l || L > r) return;
    if (l <= L && R <= r) {
        it[index].value -= CalSum(r - l - 1);
        it[index].left = l;
        it[index].right = r;
        LazySubUpdate(index);
        return;
    }

    int mid = (L + R) / 2;
    updateSub(2 * index, L, mid, l, r);
    updateSub(2 * index + 1, mid + 1, R, l, r);
    it[index].value = it[2 * index].value + it[2 * index + 1].value;
}

int get(int index, int L, int R, int l, int r)
{
    LazyAddUpdate(index);
    LazySubUpdate(index);
    if (R < l || L > r) return 0;
    if (l <= L && R <= r) {
        LazyAddUpdate(index);
        LazySubUpdate(index);
        return it[index].value;
    }

    int mid = (L + R) / 2;
    int v1 = get(2 * index, L, mid, l, r);
    int v2 = get(2 * index + 1, mid + 1, R, l, r);

    return v1 + v2;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int q, x, y;
        cin >> q >> x >> y;
        if (q == 0) {
            cout << get(1, 1, n, x, y) << "\n";
        } else if (q == 1) {
            updateAdd(1, 1, n, x, y);
        } else {
            updateSub(1, 1, n, x, y);
        }
    }

    return 0;
}
