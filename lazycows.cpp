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
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 100100111;

struct Cows
{
    int x, y;
};

bool cmp(Cows a, Cows b) {return (a.y < b.y || (a.y == b.y && a.x < b.x));}

int f[1002][1002][3];

void umin(int &a, int b)
{
    a = min(a, b);
}

void solve()
{
    int n, k, b;
    cin >> n >> k >> b;
    vector<Cows> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
    sort(a.begin(), a.end(), cmp);
    // for (auto c : a) cout << c.x << " " << c.y << "\n";
    // memset(f, INF, sizeof(f));
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= k; ++j) 
            for (int state = 0; state <= 2; ++state)
                f[i][j][state] = INF;
    f[1][1][0] = 1;
    f[1][1][1] = 2;
    f[1][2][2] = 2;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int state = 0; state <= 2; ++state) {
                // cout << f[i][j][state] << " ";
                if (f[i][j][state] == INF) continue;

                umin(f[i+1][j+1][0], f[i][j][state] + 1LL);
                umin(f[i+1][j+1][1], f[i][j][state] + 2LL);
                umin(f[i+1][j+2][2], f[i][j][state] + 2LL);

                if (state == 0) {
                    umin(f[i+1][j+1][2], f[i][j][state] + a[i].y-a[i-1].y+1);

                    if (a[i].x == a[i-1].x) umin(f[i+1][j][0], f[i][j][state] + a[i].y-a[i-1].y);
                } else if (state == 1) {
                    umin(f[i+1][j][1], f[i][j][state] + 2LL*(a[i].y-a[i-1].y));
                } else {
                    if (a[i-1].x != a[i].x) umin(f[i+1][j][0], f[i][j][state] + a[i].y-a[i-1].y);

                    umin(f[i+1][j+1][2], f[i][j][state] + a[i].y-a[i-1].y+1);
                    umin(f[i+1][j][2], f[i][j][state] + 2*(a[i].y-a[i-1].y));
                }

                // cout << f[i][j][state] << "\n";
            }
        }
    }
    cout << min({f[n][k][0], f[n][k][1], f[n][k][2]}) << "\n";
}
