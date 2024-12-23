/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)

string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

// #define DBG

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e8;

struct Node
{
    Node* left, * right, * par;
    int val;
    int wrong = 0;
    Node() : left(nullptr), right(nullptr), par(nullptr) {}
    Node(Node* l, Node* r, Node* p) : left(l), right(r), par(p) {}
    Node(Node* p) : left(nullptr), right(nullptr), par(p) {}
    Node(Node* l, Node* r) : left(l), right(r), par(nullptr) {}
    Node(int v) : val(v), left(nullptr), right(nullptr), par(nullptr) {}
};


void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    vector<int> par(n + 1);
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        adj[x].pb(i);
        par[i] = x;
    }
    vector<int> p(n);
    Node* root = new Node();
    Node* cur = root;
    for (auto& c : p) {
        cin >> c;
    }
    int idx = 0;
    auto dfs_build = [&](Node* cur, int u, auto&& dfs_build) -> void {
        // init.push_back(p[idx++]);
        cur->val = p[idx++];
        for (auto &c : adj[u]) {
            if (cur->left == nullptr) {
                cur->left = new Node(cur);
                cur->left->val = p[idx];
                dfs_build(cur->left, c, dfs_build);
            }
            else {
                cur->right = new Node(cur);
                cur->right->val = p[idx];
                dfs_build(cur->right, c, dfs_build);
            }
        }
    };

 
    dfs_build(cur, 1, dfs_build);

    // dfs
    auto dfs_init = [&](Node* cur, auto&& dfs_init) -> void {
        if (!cur) return;
        cur->wrong = 0;
        if (cur->par) {
            if (find(all(adj[cur->par->val]), cur->val) == adj[cur->par->val].end()) {
                cur->par->wrong += 1;
            }
        }
        dbg(cur->val, cur->wrong, cur->left ? cur->left->val : -1, cur->right ? cur->right->val : -1);
        dfs_init(cur->left, dfs_init);
        dfs_init(cur->right, dfs_init);
        if (cur->left && cur->right) cur->wrong += cur->left->wrong + cur->right->wrong;
    };

    dfs_init(cur, dfs_init);

    vector<Node*> nodes(n + 1);
    int id = 0;

    auto dfs_check = [&](Node* cur, auto&& dfs_check) -> void {
        if (!cur) return;
        nodes[++id] = cur;
        cerr << cur->val << " ";
        if (cur->left) cerr << cur->left->val << " ";
        if (cur->right) cerr << cur->right->val << " ";
        cerr << endl;
        dfs_check(cur->left, dfs_check);
        dfs_check(cur->right, dfs_check);
    };

    // dfs_up to update wrong

    dbg(cur->val);

    int total_wrong = 0;

    auto dfs_up = [&](Node* cur, auto&& dfs_up) -> void {
        if (!cur) return;
        cur->wrong = 0;
        if (cur->left) {
            cur->wrong += cur->left->wrong;
            if (find(all(adj[cur->val]), cur->left->val) == adj[cur->val].end()) {
                cur->wrong += 1;
            }
        }
        if (cur->right) {
            cur->wrong += cur->right->wrong;
            if (find(all(adj[cur->val]), cur->right->val) == adj[cur->val].end()) {
                cur->wrong += 1;
            }
        }
        cerr << cur->val << " " << cur->wrong << " ";
        if (cur->left) cerr << cur->left->val << " ";
        if (cur->right) cerr << cur->right->val << " ";
        cerr << endl;
        total_wrong = max(total_wrong, cur->wrong);
        dfs_up(cur->par, dfs_up);
    };

    dfs_check(cur, dfs_check);
    cerr << endl;

    dbg(p);
    for (int i = 1; i <= n; ++i) {
        dbg(nodes[i]->val);
    }



    dbg("query");

    while (q--) {
        int x, y;
        cin >> x >> y;

        dbg("query in ", q);

        dbg(x, y, p);

        dbg(nodes[x]->val, nodes[y]->val);

        swap(nodes[x]->val, nodes[y]->val);

        for (int i = 1; i <= n; ++i) {
            dbg(nodes[i]->val);
        }

        dfs_up(nodes[x], dfs_up);
        dfs_up(nodes[y], dfs_up);
        swap(p[x-1], p[y-1]);

        dbg(p);
        dbg(nodes[1]->wrong, nodes[1]->val);

        cout << ((nodes[1]->wrong == 0 && nodes[1]->val == 1) ? "YES\n" : "NO\n");

    }

}


int32_t main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}