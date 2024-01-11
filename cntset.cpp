#include <bits/stdc++.h>
 
// Importing header files
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
 
// Declaring Ordered Set
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
    pbds;
 
 
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

#define LOCAL

void solve();

int32_t main() {

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int N = 2e5 + 7;

void solve()
{
    int n, q;
    cin >> n >> q;
    // Trie trie;
    vector<int> a(n+1);
    pbds s;
    map<int, int> mp;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mp[a[i]]++;
        if (mp[a[i]] == 1)
            s.insert(a[i]);
    }

    for (int i = 0; i < q; ++i) {
        int p, x;
        cin >> p >> x;
        mp[a[p]]--;
        if (mp[a[p]] == 0) s.erase(a[p]);
        mp[x]++;
        if (mp[x] == 1) s.insert(x);
        a[p] = x;
        // for (auto &c : s) cout << c << " ";
        // cout << "\n";
        
        if (*s.find_by_order(0) > 0) {
            cout << "0\n";
            continue;
        }
        
        int l = 0, r = s.size()-1, pos = -1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (*s.find_by_order(mid) > mid) {
                r = mid - 1;
            } else {
                pos = mid;
                l = mid + 1;
            }
        }
        int fi = *s.find_by_order(pos);
        // int se = *s.find_by_order(l);
        cout << fi+1 << "\n";
    }
}
