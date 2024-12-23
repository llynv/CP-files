/*
  Code by: linvg
*/

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set                                                            \
    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,         \
         tree_order_statistics_node_update>

using namespace std;
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

// #define DBG

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    for (int i = 1; i <= n; ++i) cin >> p[i];
    ordered_set s;
    
    for (int i = 1; i <= n; ++i) s.insert({v[i], i});
 
    int res = *max_element(v.begin(), v.end());
    int num = 1;
 
    for (int k = 2; k <= n; ++k) {
        s.erase(s.find({v[p[k - 1]], p[k - 1]}));
        s.insert({0, p[k - 1]});
        pair<int, int> it = *s.find_by_order(n - k);
 
        if (it.fi * k > res) {
            res = it.fi * k;
            num = k;
        }
    }
    cout << res << " " << num << "\n";
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