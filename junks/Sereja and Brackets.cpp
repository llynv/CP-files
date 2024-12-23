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

const int N = 1e6 + 7;

struct tripe
{
    int results, open, close;
};


tripe it[4 * N];
string s;


void build (int index, int L, int R)
{
    if (L == R) {
        it[index].results = 0;
        it[index].open = (s[L-1] == '(');
        it[index].close = (s[L-1] == ')');
        return;
    }

    int mid = (L + R) / 2;
    build(2 * index, L, mid);
    build(2 * index + 1, mid + 1, R);

    tripe v1 = it[2 * index];
    tripe v2 = it[2 * index + 1];

    it[index].results = v1.results + v2.results + 2 * min(v1.open, v2.close);
    it[index].open = v1.open + v2.open - min(v1.open, v2.close);
    it[index].close = v1.close + v2.close - min(v1.open, v2.close);
}

tripe get (int index, int L, int R, int l, int r)
{
    if (R < l || L > r) {
        return {0, 0, 0};
    }
    if (l <= L && R <= r) {
        return it[index];
    }

    int mid = (L + R) / 2;
    tripe v1 = get(2 * index, L, mid, l, r);
    tripe v2 = get(2 * index + 1, mid + 1, R, l, r);
    // it[index].results = v1.results + v2.results + min(v1.open, v2.close);
    // it[index].open = v1.open + v2.open - min(v1.open, v2.close);
    // it[index].close = v1.close + v2.close - min(v1.close, v2.open);
    tripe res;
    res.results = v1.results + v2.results + 2 * min(v1.open, v2.close);
    res.open = v1.open + v2.open -  min(v1.open, v2.close);
    res.close = v1.close + v2.close - min(v1.open, v2.close);
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    int q;
    cin >> q;
    build(1, 1, s.size());
    while (q--)
    {
        it;
        int l, r;
        cin >> l >> r;
        // cout << get(1, 1, s.size(), l, r) << "\n";
        tripe res = get(1, 1, s.size(), l, r);
        cout << res.results << "\n";
    }
    

    return 0;
}

