#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

struct node
{
    node *child[26];
    bool isEnd;
    int cnt;
};

node *root;

node *CreateNode()
{
    node *p = new node();
    for (int i = 0; i < 26; ++i) {
        p->child[i] = NULL;
    }
    p->isEnd = false;
    p->cnt = 0;
    return p;
}

void AddNode(const string &s, const int &w)
{
    node *p = root;
    for (auto c : s) {
        if (p->child[c - 'a'] == NULL) {
            p->child[c - 'a'] = CreateNode();
        }
        p->cnt = max(p->cnt, w);
        p = p->child[c - 'a'];
    }
    p->isEnd = true;
}

int FindNode(const string &s)
{
    node *p = root;
    for (auto c : s) {
        if (p->child[c - 'a'] == NULL) {
            return -1;
        }
        p = p->child[c - 'a'];
    }
    return p->cnt;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    root = CreateNode();
    for (int i = 0; i < n; ++i) {
        string s;
        int w;
        cin >> s >> w;
        AddNode(s, w);
    }
    while (q--) {
        string str;
        cin >> str;
        cout << FindNode(str) << "\n";
    }
    return 0;
}
