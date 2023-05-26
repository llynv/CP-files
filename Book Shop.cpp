/*
    JUST A COPIED TEMPLATE HEHE!!!
               _oo0oo_ 
              o8888888o 
              88" . "88 
              (| -_- |) 
              0\  =  /0 
            ___/`---'\___ 
          .' \\|     |// '. 
         / \\|||  :  |||// \ 
        / _||||| -:- |||||- \ 
       |   | \\\  -  /// |   | 
       | \_|  ''\---/''  |_/ | 
       \  .-\__  '-'  ___/-. / 
     ___'. .'  /--.--\  `. .'___ 
  ."" '<  `.___\_<|>_/___.' >' "". 
 | | :  `- \`.;`\ _ /`;.`/ - ` : | | 
 \  \ `_.   \_ __\ /__ _/   .-` /  / 
=====`-.____`.___ \_____/___.-`___.-'===== 
               `=---=' 
*/


#include <bits/stdc++.h>
using namespace std;

// #define LOCAL
#define int long long

// string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
// string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

// template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
// template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
// template<class T> T sqr(T x) { return x * x; }
// template<class T> T cube(T x) { return x * x * x; }


// template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// void dbg_out() { cerr << endl; }
// template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
// #ifdef LOCAL
// #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
// #else
// #define dbg(...)
// #endif

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

struct Data
{
    int c;
    int p;
};

bool cmp(Data a, Data b) {return a.c < b.c;}

const int N = 1e3+7, M = 1e5+7;

int dp[M];
int h[N], w[N];
Data s[N];

void solve()
{
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    // sort(s, s+n+1, cmp);

    for (int i = 1; i <= n; ++i) { 
        for (int j = x; j >= 0; --j) {
        // cout << j << ": \n";
            if (j - h[i] >= 0) {
                dp[j] = max(dp[j-h[i]]+w[i], dp[j]);
                // cout << dp[j] << "\n";
            }
        }
        // cout << "\n";
    }
    cout << dp[x];
}
