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
const int N = 1e6 + 7;

struct Node
{
    Node *Left, *Right;
    int cnt;

    Node () {
        Left = Right = nullptr;
        cnt = 0;
    }
};

void CreateNode (Node *&root) {
    root = new Node();
    root->Left = new Node();
    root->Right = new Node();
}

void build (Node *&root, int L, int R)
{
    if (L == R) {
        root->cnt = 0;
        return;
    }

    int mid = (L + R) >> 1;
    CreateNode(root);
    build(root->Left, L, mid);
    build(root->Right, mid+1, R);
    root->cnt = root->Left->cnt + root->Right->cnt;
}

void update (Node *&root, int L, int R, int pos)
{
    if (L == R) {
        root = new Node();
        root->cnt = 1;
        return;
    }
    int mid = (L + R) >> 1;
    Node *tmp = new Node();
    *tmp = *root;
    if (pos <= mid) {
        update (tmp->Left, L, mid, pos);
    } else {
        update (tmp->Right, mid+1, R, pos);
    }
    tmp->cnt = tmp->Left->cnt + tmp->Right->cnt;
    root = tmp;
}

int get (Node *it1, Node *it2, int L, int R, int k)
{
    if (L == R) {
        return L;
    }

    int mid = (L + R) >> 1;
    int cnt = it2->Left->cnt - it1->Left->cnt;
    if (cnt >= k) {
        return get(it1->Left, it2->Left, L, mid, k);
    } else {
        return get(it1->Right, it2->Right, mid+1, R, k-cnt);
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);

    vector<ii> compress;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        compress.pb({a[i], i});
    }

    sort(all(compress));
    // dbg(compress);
    vector<int> b(n+1);
    for (int i = 0; i < n; ++i) {
        a[compress[i].se] = i+1;
        b[i+1] = compress[i].fi;
    }

    vector<Node*> root;

    Node *ver0 = new Node();
    build(ver0, 1, N);
    root.pb(ver0);
    for (auto &c : a) {
        Node *ver = new Node();
        *ver = *root.back();
        update(ver, 1, N, c);
        root.pb(ver);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << b[get(root[l-1], root[r], 1, N, (r - l + 2) / 2)] << "\n";
    }
}
