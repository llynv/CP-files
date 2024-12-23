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

int vals[37];

string converter(int n)
{
    string s;
    for (int i = 0; i < 32; ++i) s += '0';
    int index = 31;
    while (n > 0) {
        s[index] = (n % 2)+'0';
        n /= 2;
        --index;
    }
    return s;
}

struct node
{
    node *child[2];
    int total;
};

node *root;

node *CreateNode()
{
    node *p = new node();
    p->child[0] = p->child[1] = NULL;
    p->total = 0;
    return p;
}

void AddNode(const string &s)
{
    node *p = root;
    for (int i = 0; i < 32; ++i) {

        if (p->child[s[i]-'0'] == NULL) {
            p->child[s[i]-'0'] = CreateNode();
        }
        p = p->child[s[i]-'0'];
        p->total++;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        root = new node();
        root = CreateNode();
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            if (x == 1) {
                // cout << converter(y) << "\n";
                AddNode(converter(y));
            } else {
                string res;
                node *p = root;
                bool isFirst = true;
                for (int i = 0; i < 32; ++i) {
                    // cout << y << " ";
                    node *tmp = p;
                    if (p->child[0] != NULL) {
                        tmp = p->child[0];
                        if (tmp->total >= y) {
                            res += '0';
                            p = p->child[0];
                            continue;
                        }
                        y -= tmp->total;
                    }

                    if (p->child[1] != NULL) {
                        tmp = p->child[1];
                        if (tmp->total >= y) {
                            res += '1';
                            p = p->child[1];
                            continue;
                        }
                        y -= tmp->total;
                    }

                    if (p->child[1] != NULL) {
                        cout << p->child[1]->total << " - ";
                        res += '1';
                    } else {
                        res += '0';
                    }
                    // cout << y << "\n";
                }
                // cout << res << "\n";
                int ans = 0;
                for (int i = (int) res.size() - 1; i >= 0; --i) {
                    ans += (pow(2, i) * (res[res.size()-i-1]-'0'));
                }
                cout << ans << "\n";        
            }
        }
    }
    

    return 0;
}
