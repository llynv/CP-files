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

struct Node
{
    Node *child[2];
    int cnt;

    Node() {
        rep (i, 0, 2) child[i] = NULL;
        cnt = 0;
    }
};

Node *root;

void Add (int n)
{
    Node *p = root;
    for (int i = 0; i < 17; ++i) {
        int id = ((1 << i) & n) > 0;
        if (p->child[id] == NULL) p->child[id] = new Node();
        p = p->child[id];
        p->cnt++;   
    }
}

void Del (int n)
{
    Node *p = root;
    for (int i = 0; i < 17; ++i) {
        int id = ((1 << i) & n) > 0;
        p = p->child[id];
        p->cnt--;
    }
}

void get (Node *p, int n, int &res, int cnt = 0)
{
    dbg(n, cnt, p->cnt);

    if (cnt == 16) {
        res += p->cnt;    
        return;
    }

    int id = ((1 << cnt) & n) > 0;
    if (id == 0) {
        if (p->child[1] != NULL && p->child[1]->cnt > 0) {;
            get(p->child[1], n, res, cnt + 1);
        } 
        if (p->child[0] != NULL && p->child[0]->cnt > 0) {
            get(p->child[0], n, res, cnt + 1);
        }
    } else {
        if (p->child[1] != NULL && p->child[1]->cnt > 0) {
            get(p->child[1], n, res, cnt + 1);
        }
    }
}

void solve()
{
    root = new Node();

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n;
        cin >> n;
        if (s == "add") {
            Add(n);
        } else if (s == "del") {
            Del(n);
        } else {
            int res = 0;
            get(root, n, res);
            cout << res << "\n";
        }
    }
}
