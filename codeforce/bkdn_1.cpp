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
#define vector2d(var, y, z, type, x) vector<vector<type>> var(y, vector<type>(z, x))
#define vector3d(var, y, z, w, type, x) vector<vector<vector<type>>> var(y, vector<vector<type>>(z, vector<type>(w, x)))
#define vector4d(var, y, z, w, u, type, x) vector<vector<vector<vector<type>>>> var(y, vector<vector<vector<type>>>(z, vector<vector<type>>(w, vector<type>(u, x)))

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

struct binary_tree {
    struct node {
        int val;
        node* left, * right;
        node(int val) : val(val), left(nullptr), right(nullptr) {}
    };
    node* root;
    binary_tree() : root(nullptr) {}
    void insert(int val) {
        if (root == nullptr) {
            root = new node(val);
            return;
        }
        node* cur = root;
        while (true) {
            if (val < cur->val) {
                if (cur->left == nullptr) {
                    cur->left = new node(val);
                    return;
                }
                cur = cur->left;
            }
            else {
                if (cur->right == nullptr) {
                    cur->right = new node(val);
                    return;
                }
                cur = cur->right;
            }
        }
    }
    ii find_min_max_between(int u, int v) {
        ii res = { INF, -INF };
        node* cur = root;
        if (cur->val >= u && cur->val <= v) {
            auto l = cur->left, r = cur->right;
            while (l != nullptr) {
                res.fi = min(res.fi, l->val);
                if (l->val < u) {
                    l = l->right;
                }
                else {
                    l = l->left;
                }
            }
            while (r != nullptr) {
                res.se = max(res.se, r->val);
                if (r->val > v) {
                    r = r->left;
                }
                else {
                    r = r->right;
                }
            }
        }
        else {
            while (cur != nullptr) {
                res.fi = min(res.fi, cur->val);
                res.se = max(res.se, cur->val);
                if (cur->val < v) {
                    cur = cur->right;
                }
                else {
                    cur = cur->left;
                }
            }
        }
        return res;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    binary_tree bt;
    for (auto& c : a) bt.insert(c);
    int u, v;
    cin >> u >> v;
    cout << bt.find_min_max_between(u, v).first << " " << bt.find_min_max_between(u, v).second << "\n";
}


int32_t main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}