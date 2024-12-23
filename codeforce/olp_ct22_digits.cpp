#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long

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

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f;

bool check(string s)
{
    if (s[0] == '0' && s.size() == 1) return true;
    if (s[0] == '0') return false;
    return true;
}

void reverse (string &s)
{
    for (int i = 0; i < s.size() / 2; ++i) {
        swap(s[i], s[s.size()-i-1]);
    }
}

string pus(string s1, string s2)
{
    reverse(s1);
    reverse(s2);
    while (s1.size() != s2.size())
    {
        if (s1.size() < s2.size()) s1 += "0";
        else s2 += "0";
    }
    int r = 0;
    string str;
    for (int i = 0; i < s1.size(); ++i) {
        int a, b;
        a = (s1[i]-'0');
        b = (s2[i]-'0');
        str += ((a+b+r) % 10)+'0';
        r = (a + b + r >= 10);
    }
    str += (r != 0 ? "1" : "");
    reverse(str);
    // cout << s1 + " " + s2 + " " + str << "\n";
    return str;
}

string min (string a, string b)
{
    if (a.size() < b.size()) return a;
    if (b.size() < a.size()) return b;
    
    if (a < b) return a;
    return b;
}

void solve()
{
    string s;
    cin >> s;
    int i = 1;
    if (s.size() <= 10000) {
        string res = '9' + s;
        while (i < s.size()-1) {
            int j = i + 1;
            while (j < s.size()) {
                string s1, s2, s3;
                s1 = s.substr(0, i);
                s2 = s.substr(i, j-i);
                s3 = s.substr(j, s.size()-j);
                bool c2 = check(s2), c3 = check(s3);
                if (c2 && c3) {
                    // cout << s1 + " " + s2 + " " + s3 << ":\n";
                    res = min(res, pus(pus(s1, s2), s3));
                } else {
                    if (!c2) break;
                }
                ++j;
            }
            ++i;
        }
        cout << res;
    } else {
        cout << "0";
    }
}
