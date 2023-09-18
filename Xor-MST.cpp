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
    node *child[2];
    int nums;
};

node *root;

node *CreateNode()
{
    node *p = new node();
    p->child[0] = p->child[1] = NULL;
    p->nums = 0;
    return p;
}

void AddNode(const string &s)
{
    node *p = root;
    for (auto c : s) {
        int id = c - '0';
        if (p->child[id] == NULL) {
            p->child[id] = CreateNode();
        }
        p = p->child[id];
        p->nums++;
    }
}

string converter(int n)
{
    string s = "";
    while (n > 0) {
        s += ((n % 2)+'0');
        n /= 2;
    }
    while (s.size() < 30) {
        s += '0';
    }
    reverse(s.begin(), s.end());
    return s;
}

void Calculate(node *q, const string &s, string nxt, vector<string> &res)
{


    if (nxt.size() == 30) {
        
        res.emplace_back(nxt);
        // cout << nxt << "\n";
        // dbg(res);

    } else {

        char c = s[nxt.size()];
        int id = c - '0';
        char ac = (!id)+'0';
        if (q->child[id] != NULL && q->child[id]->nums > 0) {
            // cout << q->child[id]->nums << "\n";
            q->child[id]->nums--;
            Calculate(q->child[id], s, nxt + c, res);
            // q->child[id]->nums++;
        } else {
            // cout << !id;
            q->child[!id]->nums--;
            Calculate(q->child[!(id)], s, nxt + ac, res);
            // q->child[!id]->nums++;
        }
    }
}

int XOR(string a, string b)
{
    int res = 0;
    for (int i = 0; i < b.size(); ++i) {
        b[i] = (b[i] == a[i] ? '0' : '1');
    }
    // cout << b << "\n";
    for (int i = 0; i < b.size(); ++i) {
        if (b[i] == '1') {
            res += pow(2, (int)b.size()-i-1);
        }
    }
    return res;
}
    
int n;


int solve(string str)
{
    vector<string> res;
    res.emplace_back(str);
    node *q = root;
    // cout << str << "\n";
    for (int i = 1; i < n; ++i) {
        Calculate(q, res.back(), "", res);
    }
    dbg(res);
    int tt = 0;
    for (int i = 1; i < n; ++i) {
        tt += XOR(res[i-1], res[i]);
    }
    // dbg(tt);
    return tt;
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    root = CreateNode();
    vector<string> str;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        // cout << converter(x) << "\n";
        str.emplace_back(converter(x));
    }
    dbg(str);
    // node *p = root;
    for (int i = 0; i < n; ++i) {
        if (i != 1) {
            AddNode(str[i]);
        }
    }
    cout << solve(str[1]);
    // dbg(res);
    return 0;
}