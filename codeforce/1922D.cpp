#include <bits/stdc++.h>
using namespace std;

// #define LINVG
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



const int INF = 0x3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), d(n);
    for (auto &c : a) cin >> c;
    for (auto &c : d) cin >> c;

    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    
    set<int> pos;
    for (int i = 0; i < n; ++i) pos.insert(i);

    vector<int> days (n+1);

    int currentDay = 0;
    vector<int> dmg (n);

    dmg[*pos.begin()] = a[*next(pos.begin())];
    dmg[*pos.rbegin()] = a[*prev(prev(pos.end()))];
    // dbg(*pos.begin(), *pos.rbegin(), *next(pos.begin()), *prev(prev(pos.end())));
    // int mn = d[*pos.begin()] / dmg[*pos.begin()];
    for (auto it = next(pos.begin()); it != prev(pos.end()); ++it) {
        dmg[*it] = a[*prev(it)];
        dmg[*it] += a[*next(it)];
    }

    int cur = *pos.begin();
    currentDay++;

    vector<int> dead;

    for (auto it = pos.begin(); it != pos.end(); it = pos.upper_bound(cur)) {
        cur = *it;
        if (d[*it] < dmg[*it]) {
            dead.push_back(*it);
            pos.erase(it);
        }
    }

    days[currentDay] = sz(dead);

    dbg(a);

    dbg(pos);
    dbg(dead);
    dbg(dmg);
    dbg("\n");


    while (sz(pos) > 1 && currentDay < n) {
        
        vector<int> tmp;

        for (auto &c : dead) {;
            auto now = pos.lower_bound(c);

            dbg(c, *now, *prev(now), *next(now));

            if (now == pos.begin()) {
                dmg[*now] = a[*next(now)];
            } else if (now == pos.end()) {
                dmg[*prev(now)] = a[*prev(prev(now))];
            } else {
                dmg[*now] = 0;
                if (next(now) != pos.end()) dmg[*now] += a[*next(now)];
                dmg[*now] += a[*prev(now)];
                
                if (dmg[*now] > d[*now]) {
                    tmp.push_back(*now);
                }

                dmg[*prev(now)] = 0;
                if (prev(now) != pos.begin()) dmg[*prev(now)] += a[*prev(prev(now))];
                dmg[*prev(now)] += a[*now];

                if (dmg[*prev(now)] > d[*prev(now)]) {
                    tmp.push_back(*prev(now));
                }

            }
        }

        // dbg(tmp);

        sort(all(tmp));
        tmp.erase(unique(all(tmp)), tmp.end());

        currentDay++;
        swap(dead, tmp);
        for (auto &c : dead) pos.erase(pos.find(c));
        days[currentDay] = sz(dead);

        dbg(pos);
        dbg(dmg);
        dbg(dead);

        dbg("\n");
        // dbg(d);
        // dbg(dmg);

        if (days[currentDay] == 0) {
            break;
        }
    }
    dbg(days);
    for (int i = 1; i <= n; ++i) {
        cout << days[i] << " ";
    }
    cout << endl;
}



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