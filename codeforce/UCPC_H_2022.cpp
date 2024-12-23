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
    int pMin, pMax;

    node(const int &index) {
        for (int i = 0; i < 26; ++i) {
            this->child[i] = NULL;
        }
        this->pMax = this->pMin = index;
    }

    AddNode(const string &s, const int &index) {
        node *p = this;
        for (auto c : s) {
            int id = c-'a';
            if (p->child[id] == NULL) {
                p->child[id] = new node(index);
            }
            p = p->child[id];
            p->pMax = index;
        }
    }
};

node *root = new node(0);


void Solve(const string &str, int l, int r)
{
    node *p = root;
    for (auto c : str) {
        int id = c - 'a';
        if (p->child[id] == NULL) {
            cout << "no\n";
            return;
        }
        p = p->child[id];
        if (r < p->pMin || l > p->pMax) {
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        root->AddNode(str, i + 1LL);
        // cout << "X\n";
    }
    Solve("ad", 1, 3);
    return 0;
}
