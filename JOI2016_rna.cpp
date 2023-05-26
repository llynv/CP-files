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
    int isStart;
};

node *root, *revRoot;

node *CreateNode()
{
    node *p = new node();
    for (int i = 0; i < 26; ++i) {
        p->child[i] =  NULL;
    }
    p->isStart = 0;
    return p;
}

void AddNode(const string &s)
{
    node *p = root;
    for (int i = 0; i < (int) s.size(); ++i) {
        int id = s[i] - 'A';
        if (p->child[id] == NULL) {
            p->child[id] = CreateNode();
        }
        p = p->child[id];
        p->isStart++;
    }
    // for (int i = (int) s.size() - 1; i >= 0; --i) {
    //     int id = s[i] - 'A';
    //     if (p->parent[id] == NULL) {
    //         p->parent[id] = CreateNode();
    //     }
    //     p = p->parent[id];
    //     p->isStart++;
    // }
}

void update(int &cnt, int vals)
{
    cnt = min(cnt, vals);
}

int FindFinalChild(int n, node *p, vector<int> &ret)
{
    bool isFound = false;
    for (int i = 0; i < 26; ++i) {
        if (p->child[i] != NULL) {
            FindFinalChild(i, p->child[i], ret);
        }
    }
    ret.emplace_back(n);
}

int CalculateNode(const string &st, const string &en)
{
    node *p = root;
    if (p->child[st.front() - 'A'] == NULL) return 0;

    int cnt = LONG_LONG_MAX;
    // cnt = min(p->child[st[0] - 'A']->isStart, p->child[en[0] - 'A']->isStart);

    for (auto c : st) {
        if (p->child[c - 'A'] == NULL) return 0;
        p = p->child[c - 'A'];
        update(cnt, p->isStart);
        // cout << p->isStart << " ";
    }

    vector<int> ret;
    FindFinalChild(-1, p, ret);

    // ret.erase(-1);
    // for (auto c : ret) {
    //     cout << (char)(c + 'A');
    // }
    cout << "\n";
    dbg(ret);
    

    return cnt;
}

void reverse(string &s)
{
    for (int i = 0; i < s.size() / 2; ++i) swap(s[i], s[s.size()-i-1]);
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    root = CreateNode();
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        AddNode(s);
    }
    for (int i = 0; i < m; ++i) {
        string fi, se;
        cin >> fi >> se;
        reverse(se);
        cout << CalculateNode(fi, se) << "\n";
    }
    return 0;
}
