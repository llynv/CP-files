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
    Node *child[26];
    int nums, order;
    bool isEnd;

    Node() {
        for (int i = 0; i < 26; ++i) child[i] = NULL;
        nums = 0;
        order = 0;
        isEnd = false;
    }
};

struct Trie
{
    Node *root = new Node();

    void Add (string s, int k) {
        Node *p = root;
        // dbg(k);
        for (auto &c : s) {
            int id = c - 'a';
            if (p->child[id] == NULL) p->child[id] = new Node();
            p = p->child[id];
            p->nums++;
            if (p->order == 0) p->order = k;
            dbg(c, p->order);
        }
        p->isEnd = true;
    }

    void Delete (string s) {
        Node *p = root;
        for (auto &c : s) {
            int id = c - 'a';
            p = p->child[id];
            p->nums--;
            p->order--;
        }
        p->isEnd = false;
    }

    int Get (string s, int k) {
        Node *p = root;
        for (auto &c : s) {
            int id = c - 'a';
            p = p->child[id];
            if (p->nums <= 0) return 404;
        } 
        int res = 404, order = 1;
        dfs(p, 1, k, res, order);
        return res;
    }   

    void dfs(Node *p, int order, int k, int &pos, int &cnt) {
        if (cnt == k && p->isEnd) {
            pos = p->order;
            // pos = order; 
            return;
        }
        dbg(cnt);
        for (int i = 0; i < 26; ++i) {
            if (p->child[i] != NULL) {
                // order += cnt;
                dfs(p->child[i], order + cnt, k, pos, cnt);
                // dbg(order, cnt, k);
            }
        }   
    }

};

Trie myTrie;


void solve()
{
    int q;
    cin >> q;
    vector<string> str;
    str.push_back("");
    rep (i, 1, q+1) {
        string s;
        cin >> s;
        if (s == "POST") {
            int x;
            char c;
            cin >> x >> c;
            str.push_back(str[x] + c);
            myTrie.Add(str.back(), i); 
        } else if (s == "DELETE") {
            int x;
            cin >> x;
            if (str[x] != "") {
                myTrie.Delete(str[x]);
                str[x] = "";
            }
        } else {
            string l;
            cin >> l;
            int k;
            cin >> k;
            int val = myTrie.Get(l, k);
            cout << val << "\n";
        }
    }
}
