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

int32_t main() {

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;

bool cmp(int a, int b) {
    return a <= b;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> preX(n+2), preY(n+2), sufX(n+2), sufY(n+2);
    int cntX = 0, cntY = 0;
    map<int, vector<int>> prePosX, prePosY;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        cntX += (c == 'R');
        cntY += (c == 'U');
        cntX -= (c == 'L');
        cntY -= (c == 'D');
        prePosX[cntX].pb(i+1);
        prePosY[cntY].pb(i+1);
        preX[i+1] += cntX;
        preY[i+1] += cntY;
    }

    cntX = 0, cntY = 0;
    map<int, vector<int>> sufPosX, sufPosY;
    for (int i = n-1; i >= 0; --i) {
        char c = s[i];
        cntX += (c == 'R');
        cntY += (c == 'U');
        cntX -= (c == 'L');
        cntY -= (c == 'D');
        sufPosX[cntX].pb(i+1);
        sufPosY[cntY].pb(i+1);
        sufX[i+1] += cntX;
        sufY[i+1] += cntY;
    }

    for (auto &c : sufPosX) {
        sort(all(c.se));
    }

    for (auto &c : prePosX) {
        sort(all(c.se));
    }

    dbg(preX);
    dbg(preY);
    dbg(sufX);
    dbg(sufY);

    while (q--) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        if (preX[r] == x && preY[r] == y) {
            cout << "YES\n";
            continue;
        }
        int lRev = n - l + 1;
        int rRev = n - r + 1;
        int i = 0;
        while (i < prePosX[x].size() && prePosX[x][i] < l) {
            // dbg(i, prePosX[x][i], preY[prePosX[x][i]]);
            if (preY[prePosX[x][i]] == y) {
                cout << "YES\n";
                dbg(i, prePosX[x][i], preY[prePosX[x][i]]);
                goto ok;
            }
            ++i;
        }

        i = lower_bound(all(prePosX[x]), r) - prePosX[x].begin();
        dbg(x, y, prePosX[x]);
        while (i < prePosX[x].size()) {
            dbg(i, prePosX[x][i], preY[prePosX[x][i]]);
            if (preY[prePosX[x][i]] == y) {
                cout << "YES\n";
                goto ok;
            }
            ++i;
        }

        i = lower_bound(all(sufPosX[x-preX[l-1]]), l, cmp) - sufPosX[x-preX[l-1]].begin();
        // dbg(prePosX[x-preX[l-1]]);
        dbg(x - preX[l-1], x, sufPosX[x-preX[l-1]]);
        while (i < sufPosX[x-preX[l-1]].size() && sufPosX[x-preX[l-1]][i] <= r) {
            // dbg(i, sufPosX[x+preX[lRev-1]][i], sufY[sufPosX[x+preX[lRev-1]][i]]);
            int pos = sufPosX[x-preX[l-1]][i];

            int totalY = sufY[pos] - sufY[r+1] + preY[l-1];

            dbg (i, x, totalY);

            if (sufY[pos] - sufY[r+1] + preY[l-1] == y) {
                cout << "YES\n";
                goto ok;
            }
            ++i;
        }
        
        cout << "NO\n";
        ok:;
    }
}
