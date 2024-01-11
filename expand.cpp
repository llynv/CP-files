#include <bits/stdc++.h>
using namespace std;

#define LINVG
// #define int long long
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
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

class LLNode {
public:
    int val;
    LLNode* next;
    LLNode() {}; // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next) {}; // Constructor with customized data
};

LLNode* duplicate(LLNode* root) {
    LLNode* rev = new LLNode();
    LLNode* nRev = rev;
    LLNode* pre = root;
    rev = pre->next;
    rev->next = pre;
    root = root->next;
    // while (root->next != nullptr) {
    //     rev = root->next;
    //     pre = pre->next;
    //     rev->next = pre;
    //     root = root->next;
    // }
    // while (nRev != nullptr) {
    //     cout << nRev->val << " ";
    //     nRev = nRev->next;
    // }
    return rev;
}

 

void solve()
{
    int a[] = {11, 2, 12, 32, 10, 34};
    int n = sizeof(a) / sizeof(a[0]);
    LLNode* root;
    LLNode* p = root;
    for (int i = 0; i < n; ++i) {
        root->next = new LLNode();
        root = new LLNode(a[i], root->next);
    }
    while (p->next != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    // LLNode* res = duplicate(p);
}
