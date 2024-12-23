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
const int N = 1e5 + 7;

int a[N], lv[N];

struct itnode {
    itnode *Left, *Right;
    int cnt, val;

    itnode() {
        Left = Right = nullptr;
        cnt = 0;
    }
};

vector<itnode*> vers;

void CreateNode(itnode *&root) {
    root = new itnode();
    root->Left = new itnode();
    root->Right = new itnode();
}

void build (itnode *&root, int L, int R)
{
    if (L == R) {
        CreateNode(root);
        root->cnt = 0;
        return;
    }

    CreateNode(root);

    int mid = (L + R) >> 1;
    build (root->Left, L, mid);
    build (root->Right, mid + 1, R);
    root->cnt = 0;
}

void update (itnode *&root, int L, int R, int x)
{
    if (L == R) {
        root = new itnode();
        root->val = x;
        root->cnt = 1;
        return;
    }

    int tsum = root->Left->cnt + root->Right->cnt;

    itnode *tmp = new itnode();
    *tmp = *root;

    int mid = (L + R) >> 1;
    if (x <= mid) {
        update (tmp->Left, L, mid, x);
    } else {
        update (tmp->Right, mid + 1, R, x);
    }
    tmp->cnt = tmp->Left->cnt + tmp->Right->cnt;
    root = tmp;
}

int get (itnode *it1, itnode *it2, int L, int R, int k)
{
    if (L == R) {
        return L;
    }

    int numb = it2->Left->cnt - it1->Left->cnt;
    int mid = (L + R) >> 1;
    if (numb >= k) {
        return get (it1->Left, it2->Left, L, mid, k);
    } else {
        return get (it1->Right, it2->Right, mid + 1, R, k - numb);
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    set<ii> s;
    vector<int> b;
    rep (i, 1, n+1) {
        cin >> a[i];
        b.push_back(a[i]);
    }
    sort(all(b));
    for (auto c : b) s.insert(ii{c, sz(s)+1});
    // dbg(s);
    vector<int> ans(n+1);
    rep (i, 1, n+1) {
        auto cur = s.lower_bound(ii{a[i], -1LL});
        lv[i] = (*cur).se;
        ans[lv[i]] = a[i];
        // dbg((*cur).se);
    }
    // rep (i, 1, n+1) cout << lv[i] << " ";
    
    itnode *ver0 = new itnode();
    build(ver0, 1, n);
    vers.push_back(ver0);
    for (int i = 1; i <= n; ++i) {
        itnode *newVer = new itnode();
        *newVer = *vers.back();
        update(newVer, 1, n, lv[i]);
        vers.push_back(newVer);
    }
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        itnode *verl = vers[l-1];
        itnode *verr = vers[r];
        // dbg(verr->val);
        cout << ans[get(verl, verr, 1, n, k)] << "\n";
        // dbg("END");
    }
}
