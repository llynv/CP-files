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



const int N = 1e5+7;

struct data
{
    int maxVal, updateVal;
};


int a[N];
data it[4 * N];

void LazyUpdate(int index)
{
    int k = it[index].updateVal;
    it[2 * index].maxVal += k;
    it[2 * index].updateVal += k;
    it[2 * index + 1].maxVal += k;
    it[2 * index + 1].updateVal += k;
    it[index].updateVal = 0;
}


void update(int index, int L, int R, int l, int r, int k)
{
    LazyUpdate(index);

    if (R < l || L > r) {
        return;
    }

    if (l <= L && R <= r) {
        it[index].maxVal += k;
        it[index].updateVal += k;
        LazyUpdate(index);
        return;
    }

    LazyUpdate(index);

    int mid = (L + R) / 2;
    update(2 * index, L, mid, l, r, k);
    update(2 * index + 1, mid + 1, R, l, r, k);

    it[index].maxVal = max(it[2 * index].maxVal, it[2 * index + 1].maxVal);
}

int get(int index, int L, int R, int l, int r)
{
    if (R < l || L > r) {
        return -1;
    }

    if (L >= l && R <= r) {
        return it[index].maxVal;
    }

    LazyUpdate(index);

    int mid = (L + R) / 2;
    int v1 = get(2 * index, L, mid, l, r);
    int v2 = get(2 * index + 1, mid + 1, R, l, r);

    return max(v1, v2);    
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
 
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if (x == 0) {
            int x, y, k;
            cin >> x >> y >> k;
            update(1, 1, n, x, y, k);
        } else {
            int x, y;
            cin >> x >> y;
            cout << get(1, 1, n, x, y) << "\n";
        }
    }
 
    return 0;
}
