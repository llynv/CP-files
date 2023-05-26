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

const int IF = 0x3f3f3f3f;

int f[1001][1001][12][2];

void cmax(int &a, int b) {
    a = max(a, b);
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    memset(f, -1LL, sizeof(f));
    f[0][0][0][0] = 0;
    bool state = 0;
    int res = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int num = 0; num <= k; ++num) {
                for (int state = 0; state <= 1; ++state) {

                    if (f[i][j][num][state] == -1) continue;

                    if (i + 1 <= n && j + 1 <= m && a[i] == b[j]) {
                        cmax(f[i+1][j+1][num+1][1], f[i][j][num][state] + 1);
                        if (state == 1) {
                            cmax(f[i+1][j+1][num][1], f[i][j][num][state] + 1);
                        }
                    }
                    if (i < n) {
                        cmax(f[i+1][j][num][0], f[i][j][num][state]);
                    }
                    if (j < m) {
                        cmax(f[i][j+1][num][0], f[i][j][num][state]);
                    }
                    // cmax(res, f[i][j][num][state]);
                }
            }
        }
    }
    cout << max(f[n][m][k][0], f[n][m][k][1]);
}
