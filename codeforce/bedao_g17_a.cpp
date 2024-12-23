
/*
  Code by: linvg
  Created: 15.09.2024 20:02:11
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e8;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<array<int, 3>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i][0] >> points[i][1] >> points[i][2];
    }
    sort(all(points), [](array<int, 3> a, array<int, 3> b) {
        return sqr(a[0]) + sqr(a[1]) < sqr(b[0]) + sqr(b[1]);
    });

    auto it = points.begin();
    vector<array<int, 2>> sum;
    while (it != points.end()) {
        auto [x, y, p] = *it;
        int dist = sqr(x) + sqr(y);
        if (it == points.begin()) {
            sum.push_back({dist, p});
        } else {
            if (sum.back()[0] == dist) {
                sum.back()[1] += p;
            } else {
                sum.push_back({dist, p + sum.back()[1]});
            }
        }
        ++it;        
    }

    while (q--) {
        int r;
        cin >> r;
        r *= r;
        auto it = upper_bound(all(sum), array<int, 2>{r, INF});
        if (it == sum.begin()) {
            cout << 0 << '\n';
        } else {
            --it;
            cout << (*it)[1] << '\n';
        }
    }   
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
//    int t;
//    cin >> t;
//    while (t--)
   solve();
   return 0;
}