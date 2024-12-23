// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize("O3", "unroll-loops")

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

#define LOCAL

int32_t main() {

    #ifdef LOCAL
        freopen("ADN.INP", "r", stdin);
        freopen("ADN.OUT", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;

void solve()
{
    string s;
    cin >> s;
    int n = sz(s);
    bool isStart = s.front() == '?', isEnd = s.back() == '?';
    if (isStart) {
        for (int i = 0; i < n; ++i) {
            if (s[i] != '?') {
                for (int j = 0; j < i; ++j) s[j] = s[i];
                break;
            }
        }
    } 
    if (isEnd) {
        for (int i = n-1; i >= 0; --i) {
            if (s[i] != '?') {
                for (int j = i+1; j < n; ++j) s[j] = s[i];
                break;
            }
        }
    }

    bool isChar = false;
    for (auto &c : s) if (c != '?') isChar = true;
    if (!isChar) {
        cout << 0 << "\n";
        return;
    }

    char head = '#', tail = '#';
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?' && s[i-1] != '?') head = s[i-1];
        if (s[i] == '?' && s[i+1] != '?') tail = s[i+1];

        if (head != '#' && tail != '#' && head == tail) {
            int j = i;
            while (j >= 0 && s[j] == '?') {
                s[j] = head;
                j--;
            }
            head = '#';
            tail = '#';

            // dbg(s);
        } else if (head != '#' && tail != '#') {
            head = '#';
            tail = '#';
        }
    }

    vector<int> pre(n+1), suf(n+1);
    pre[0] = 0;
    pre[1] = 1;
    suf[n] = 1;
    for (int i = 2; i <= n; ++i) {
        if (s[i-1] == s[i-2] && s[i-1] != '?') {
            pre[i] = pre[i-1] + 1;
        } else {
            pre[i] = 1;
        }
    }

    for (int i = n-1; i > 0; --i) {
        if (s[i-1] == s[i] && s[i-1] != '?') {
            suf[i] = suf[i+1] + 1;
        } else {
            suf[i] = 1;
        }
    }
    // dbg(s);
    // dbg(pre);
    // dbg(suf);

    int i = 0;
    while (i < n) {
        if (s[i] == '?') {
            int j = i;
            while (s[j] == '?') ++j;

            if (pre[i] > suf[j]) {
                for (int k = i; k < j; ++k) {
                    s[k] = s[i-1];
                    // if (s[k] == s[k-1]) pre[k+1] = pre[k] + 1;
                    // else pre[k+1] = 1;
                }
            } else {
                for (int k = j-1; k >= i; --k) {
                    s[k] = s[j];
                    // if (s[k] == s[k+1]) suf[k] = suf[k+1] + 1;
                    // else suf[k] = 1;
                }
            }

            // dbg(s, pre);

            // i = j;
        }
        if (i > 0 && s[i] == s[i-1]) pre[i+1] = pre[i] + 1;
        else pre[i+1] = 1;

        // dbg(s, pre, i);

        ++i;
    }

    // dbg(pre);

    int res = 0, cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) cnt++;
        else {
            res += cnt * (cnt+1) / 2;
            cnt = 1;
        }
    }

    res += cnt * (cnt+1) / 2;

    cout << n*(n+1)/2 - res << "\n";
}
