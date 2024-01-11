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

vector<int> mp (256);

int32_t main() {

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    int cnt = 0;
    for (char i = 'A'; i <= 'Z'; ++i) mp[i] = cnt++;
    for (char i = 'a'; i <= 'z'; ++i) mp[i] = cnt++;
    for (int i = 0; i <= 9; ++i) mp[i+'0'] = cnt++;
    mp['+'] = cnt++;
    mp['/'] = cnt++;

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    // dbg(mp);

    vector<int> b;

    int x = 0, y = 0;
    bitset<5007> bs[n];

    for (int i = 0; i < sz(s); ++i) {
        if ((i < sz(s) - 1) || (n*n % 6 == 0)) {
            int d = mp[s[i]];
            // dbg(d);
            for (int j = 0; j < 6; ++j) {
                y = (i * 6 + j) / n;
                // dbg(y, x, (d >> j) & 1);
                bs[y][x] = !((d >> j) & 1);
                x = (x + 1) % n;
                // b.push_back((d >> j) & 1);
            }
        } else {
            int ls = n*n % 6;
            // dbg(ls);
            int d = mp[s[i]];
            for (int j = 0; j < ls; ++j) {
                // b.push_back((d >> j) & 1);
                y = (i * 6 + j) / n;
                // dbg(y, x, (d >> j) & 1);
                bs[y][x] = !((d >> j) & 1);
                x = (x + 1) % n;
            }
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << bs[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if ((bs[i] ^ bs[j]).count() > 0 && (bs[i] & bs[j]).count() > 0) {
                for (int x = 0; x < n; ++x) {
                    for (int y = x + 1; y < n; ++y) {
                        if ((bs[i][x] ^ bs[j][x]) && (bs[i][y] & bs[j][y])
                        ||  (bs[i][x] & bs[j][x]) && (bs[i][y] ^ bs[j][y])) {        
                            cout << "YES\n";
                            cout << j+1 << " " << x+1 << " " << i+1 << " " << y+1 << "\n";
                            return;
                        }
                    }
                }
            }
        }
    }

    cout << "NO\n";
}   
