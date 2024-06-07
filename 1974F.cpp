/*
  Code by: linvg
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)

string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }


#define mp make_pair
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> OST;


const int N = 200001;
 
OST bit[N];
 
void insert(int x, int y)
{
	for(int i = x; i < N; i += i & -i)
		bit[i].insert(mp(y, x));
}
 
void remove(int x, int y)
{
	for(int i = x; i < N; i += i & -i)
		bit[i].erase(mp(y, x));
}
 
int query(int x, int y)
{
	int ans = 0;
	for(int i = x; i > 0; i -= i & -i)
		ans += bit[i].order_of_key(mp(y+1, 0));
	return ans;
}

// #define DBG

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
void solve()
{
    int a, b, n, m;
    cin >> a >> b >> n >> m;

    for (int i = 0; i <= n; ++i) bit[i].clear();

    vector<int> xx(n), yy(n);
    vector<int> compressed_x, compressed_y;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        // insert(x, y);
        xx[i] = x;
        yy[i] = y;
    }

    compressed_x = xx;
    compressed_x.pb(0);
    sort(all(compressed_x));

    compressed_x.erase(unique(all(compressed_x)), compressed_x.end());

    for (int i = 0; i < n; ++i) {
        xx[i] = lower_bound(all(compressed_x), xx[i]) - compressed_x.begin();
        insert(xx[i], yy[i]);
    }

    auto qq = [&](int x, int y, int u, int v) {
        x = upper_bound(all(compressed_x), x) - compressed_x.begin() - 1;
        u = upper_bound(all(compressed_x), u) - compressed_x.begin() - 1;

        return query(u, v) - query(x, v) - query(u, y) + query(x, y);
    };

    int ax = 0, bx = 0;

    int alice = 0, bob = 0;

    for (int i = 0; i < m; ++i) {
        char c;
        int k;
        cin >> c >> k;

        int earn = 0;

        if (c == 'U') {
            earn = qq (ax, bx, ax + k, b);
        } else if (c == 'D') {
            earn = qq(a - k, bx, a, b);
        } else if (c == 'L') {
            earn = qq(ax, bx, a, bx + k);
        } else if (c == 'R') {
            earn = qq(ax, b - k, a, b);
        }

        dbg(c, k, earn);

        if (i & 1) { 
            bob += earn;
        } else {
            alice += earn;
        }

        if (c == 'U') {
            ax += k;
        } else if (c == 'D') {
            a -= k;
        } else if (c == 'L') {
            bx += k;
        } else if (c == 'R') {
            b -= k;
        }
    }
    cout << alice << ' ' << bob << '\n';
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}