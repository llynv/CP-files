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

void calc(long long& l, long long& r, long long& suml, long long& sumr, long long j, long long i);

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

void solve()
{
    string s;
    cin >> s;
    vector<int> pre1(sz(s)+1), pre2(sz(s)+1);
    for (int i = sz(s) - 1; i >= 0; --i) {
        pre1[i] = pre1[i+1];
        pre2[i] = pre2[i+1];
        pre1[i] += (i % 2 == 0);
        pre2[i] += (i % 2 != 0);
    }

    // dbg(pre1, pre2);

    int res = 10;
    for (int i = 0; i < 1024; ++i) {
        bool isValid = true;
        int cur = i;
        for (int j = 0; j < 10; ++j) {
            if (s[j] == '?') {
                cur >>= 1;
                continue;
            }

            if ((s[j]-'0') != (cur & 1)) {
                isValid = false;
                break;
            }
            cur >>= 1;
        }

        if (!isValid) continue;
        int cnt1 = 0, cnt2 = 0;
        for (int j = 0; j < 10; ++j) {
            if (j % 2 == 0) {
                cnt1 += (((1 << j) & i) > 0);
            } else {
                cnt2 += (((1 << j) & i) > 0);
            }

            if (cnt1 + pre1[j+1] < cnt2 || cnt2 + pre2[j+1] < cnt1) {
                res = min(res, j + 1);

                // cout << cnt1 << " " << cnt2 << "\n";
                // for (int p = 0; p < 10; ++p) cout << ((i & (1 << p)) > 0);
                // cout << "\n";

                break;
            }
        }
    }
    cout << res << "\n";
}
