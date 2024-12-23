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
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator>>(ostream &is, const T_container &v) { for (auto &c : v) is >> c; }
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
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;

struct trie
{
    struct Node
    {
        Node *child[2];
        int cnt;
        Node()
        {
            child[0] = child[1] = NULL;
            cnt = 0;
        }
    };

    Node *root = new Node();

    void add (int x)
    {
        Node *cur = root;
        for (int i = 30; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if (cur->child[bit] == NULL) {
                cur->child[bit] = new Node();
            }
            cur = cur->child[bit];
            cur->cnt++;
        }
    }

    int get (int x)
    {
        Node *cur = root;
        int res = 0;
        for (int i = 30; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if (cur->child[!bit] != NULL && cur->child[!bit]->cnt > 0) {
                res |= (1 << i);
                cur = cur->child[!bit];
                cur->cnt--;
            } else {
                cur = cur->child[bit];
                cur->cnt--;
                res &= ~(1 << i);
            }
        }
        return res;
    }
};


void solve()
{
    int n;
    cin >> n;

    trie mytrie;
    vector<int> a(n);
    vector<vector<int>> digits(31, vector<int>(2));
    for (auto &c : a) cin >> c;
    for (int i = 0; i < 31; ++i) {
        for (auto &c : a) {
            digits[i][(c >> i) & 1]++;
        }
    }

    vector<int> b(n);
    vector<vector<int>> digits2(31, vector<int>(2));
    for (auto &c : b) {
        cin >> c;
    }
    for (int i = 0; i < 31; ++i) {
        for (auto &c : b) {
            digits2[i][(c >> i) & 1]++;
        }
    }

    vector<vector<vector<int>>> xorVals(2, vector<vector<int>>(2, vector<int> (32)));
    vector<vector<vector<int>>> bVals(2, vector<vector<int>>(2, vector<int> (32)));

    int res = 0;
    for (int i = 30; i >= 0; --i) {
        if (digits[i][1] == digits2[i][0] && digits[i][0] == digits2[i][1]) {
            for (int j = 0; j < n; ++j) {
                for (int k = i-1; k >= 0; --k) {
                    if (a[j] & (1 << i)) {
                        xorVals[1][(a[j] & (1 << k)) > 0][k]++;
                    } else {
                        xorVals[0][(a[j] & (1 << k)) > 0][k]++;
                    }

                    if (b[j] & (1 << i)) {
                        bVals[1][(b[j] & (1 << k)) > 0][k]++;
                    } else {
                        bVals[0][(b[j] & (1 << k)) > 0][k]++;
                    }
                }
            }
            res |= (1 << i);

            for (int j = i-1; j >= 0; --j) {
                if (xorVals[1][0][j] == bVals[0][1][j] && xorVals[1][1][j] == bVals[0][0][j] && xorVals[0][0][j] == bVals[1][1][j] && xorVals[0][1][j] == bVals[1][0][j]) {
                    res |= (1 << j);

                    for (int k = 0; k < n; ++k) {
                        if (a[k] & (1 << j)) {
                            xorVals[1][(a[k] & (1 << j)) > 0][j]--;
                        } else {
                            xorVals[0][(a[k] & (1 << j)) > 0][j]--;
                        }

                        if (b[k] & (1 << j)) {
                            bVals[1][(b[k] & (1 << j)) > 0][j]--;
                        } else {
                            bVals[0][(b[k] & (1 << j)) > 0][j]--;
                        }
                    }
                }
            }
            break;
        }
    }
    cout << res << "\n";

}
