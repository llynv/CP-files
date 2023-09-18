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

string rmin, rmax;

void convert(string &s)
{
    while (s.size() < 18) {
        s.insert(s.begin(), '0');
    }
}

string reconvert(string s)
{
    while (s[0] == '0' && s.size() > 1) {
        s.erase(s.begin());
    }
    return s;
}

struct node
{
    node *child[10];
    vector<int> neibour;
};

node *root;

node *CreateNode()
{
    node *p = new node();
    for (int i = 0; i <= 9; ++i) {
        p->child[i] = NULL;
    }
    p->neibour.clear();
    return p;
}

void AddNode(const string &s)
{
    node *p = root;
    for (auto c : s) {
        int id = c - '0';
        if (p->child[id] == NULL) {
            p->child[id] = CreateNode();
            p->neibour.emplace_back(id);
        }
        p = p->child[id];
    }
}

void Calculate(node *p, const string &s, string stringTmp, string &ans, const bool &isLarger)
{
    if (stringTmp.size() == 18) {
        ans = (isLarger ? max(ans, stringTmp) : min(ans, stringTmp));
    }

    char plusChar;
    int son;

    if (!p->neibour.empty()) {

        if (isLarger) {
            plusChar = ' ';
            for (auto c : p->neibour) {
                char charCheck = (((c + (s[stringTmp.size()] - '0')) % 10) + '0');
                if (charCheck > plusChar) {
                    plusChar = charCheck;
                    son = c;
                }
            }
        }
        else {
            plusChar = 'A';
            for (auto c : p->neibour) {
                char charCheck = (((c + (s[stringTmp.size()] - '0')) % 10) + '0');
                if (charCheck < plusChar) {
                    plusChar = charCheck;
                    son = c;
                }
            }
        }

        Calculate(p->child[son], s, stringTmp + plusChar, ans, isLarger);
    }
}

void Solve(const string &s)
{
    node *p = root;
    Calculate(p, s, "", rmin, false);
    Calculate(p, s, "", rmax, true);
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    string str;
    root = CreateNode();
    for (int i = 0; i < 18; ++i) {
        rmin += '9';
        rmax += '0';
    }
    cin >> str;
    convert(str);
    AddNode(str);
    for (int i = 1; i < n; ++i) {
        cin >> str;
        convert(str);
        Solve(str);
        // cout << str << "\n";
        AddNode(str);
    }
    cout << reconvert(rmin) << " " << reconvert(rmax);
    return 0;
}
