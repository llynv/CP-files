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

struct mytrie {
    
    struct Node {
        Node *child[2];
        bool isEnd;

        Node () {
            child[0] = child[1] = nullptr;
            isEnd = false;
        }
    };

    Node *root = new Node();

    void add (int x) {
        Node *cur = root;
        for (int i = 17; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if (cur->child[bit] == nullptr) {
                cur->child[bit] = new Node();
            }
            cur = cur->child[bit];
        }
        cur->isEnd = true;
    }

    int query (int x) {
        Node *cur = root;
        int res = 0;
        for (int i = 17; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if (cur->child[bit^1] != nullptr) {
                res |= (1LL << i);
                cur = cur->child[bit^1];
            } else {
                cur = cur->child[bit];
            }
        }
        return res;
    }

    int minQuery (int x) {
        Node *cur = root;
        int res = 0;
        for (int i = 17; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if (cur->child[bit] != nullptr) {
                cur = cur->child[bit];
            } else {
                res |= (1LL << i);
                cur = cur->child[bit^1];
            }
        }
        return res;
    }
};

void solve()
{
    int l, r;
    cin >> l >> r;
    mytrie trie;

    vector<int> a(r-l+1);
    int mx = 0, mn = INF;
    vector<int> bit;
    for (auto &c : a) {
        cin >> c;
        trie.add(c);
        bit.push_back((c ^ l));
        bit.push_back((c ^ r));
    }

    for (auto &i : bit) {
        int x = trie.query(i);
        int xm = trie.minQuery(i);
        // dbg(i, x, xm, l, r);
        if (x != r || l != xm) continue;
        return void (cout << i << '\n');
    }
    cout << 0 << '\n';
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