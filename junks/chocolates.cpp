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
void init();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f;
int f[31][31][50];

void init()
{
    memset(f, INF, sizeof(f));
    for (int i = 0; i <= 30; ++i) f[i][i][1] = 0;
    int i = 30, j = 30, k = 30;
    for (int c = 1; c <= 50; ++c) {
        for (int u = 1; u <= i-1; ++u) {
            f[u][j][c] = min(f[i][j][k], f[i-u][j][k-min(u*i, k)] + f[u][j][u*i] + sqr(i));  
        }
        for (int v = 1; v <= j-1; ++v) {
            f[i][j][c] = min(f[i][j][k], f[i][j-v][k-min(v*j, k)] + f[i][v][v*j] + sqr(j));
        }
        cout << f[i][j][k] << " ";
    }
}

void solve()
{
    int a, b, x;
    cin >> a >> b >> x;
    cout << f[a][b][x] << "\n";
}
