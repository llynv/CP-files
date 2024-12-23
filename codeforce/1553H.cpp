#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("O3", "unroll-loops")

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

struct Trie
{
    struct Node
    {
        Node *child[2];
        int cnt;

        Node () {
            child[0] = child[1] = nullptr;
            cnt = 0;
        }
    };
    
    Node *root;
    int k;

    Trie(int k) {
        root = new Node();
        this->k = k;
    }

    void add (int n) {
        Node *p = root;
        for (int i = 0; i < k; ++i) {
            bool id = (n & (1 << i));
            if (p->child[id] == nullptr) p->child[id] = new Node();
            p = p->child[id];
            p->cnt++;
        }
    }

    int get (int x) {
        vector<int> vst;
        vector<int> nums;
        int res = INF, xnum = -1;
        Node *p = root;
        dfs(p, 0, xnum, res, x);
        return res;
    }

    void dfs (Node *p, int nxt, int &xnum, int &res, int x) {
        if (p->cnt == 1) {
            Node *tmp = p;
            bool isEnd = false;
            int num = nxt, cnt = 0;
            while (!isEnd)
            {
                isEnd = true;
                for (int i = 0; i < 2; ++i) {
                    if (tmp->child[i] != nullptr) {
                        num <<= 1;
                        num |= i;
                        tmp = tmp->child[i];
                        isEnd = false;
                        break;
                    }
                }
                cnt++;
            }
            if (xnum == -1) {
                xnum = num;
                return;
            }
            res = min(res, abs((xnum ^ x) - (num ^ x)));
            dbg(xnum, num, abs((xnum ^ x) - (num ^ x)), x);
            xnum = max(xnum, num);
            return;
        }

        for (int i = 0; i < 2; ++i) {
            if (p->child[i] != nullptr) {
                dfs(p->child[i], i, xnum, res, x);
            }   
        }
    }
};


void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    Trie *trie = new Trie(k);

    for (auto &c : a) {
        cin >> c;
        trie->add(c);
    }

    for (int i = 0; i < (1 << k); ++i) {
        cout << trie->get(i) << " ";
    }
}
