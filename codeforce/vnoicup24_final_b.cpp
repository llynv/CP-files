/*
  Code by: linvg
*/

#include <bits/stdc++.h>
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

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e8;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> init(3), testing(3);
    for (int i = 0; i < 3; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            init[i].push_back(x);
        }
        testing[i] = init[i];
        reverse(all(init[i]));
    }
    // for (auto v : init) {
    //     for (auto c : v) cerr << c << ' ';
    //     cerr << '\n';
    // }
    // cerr << '\n';

    map<tuple<int, int, int>, int> mp;
    mp[{testing[0].size(), testing[1].size(), testing[2].size()}] = 1;
    while (true) {
        bool next = false;
        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 3; ++j) {
                if (testing[i].empty() || testing[j].empty()) continue;
                if (testing[i].back() == testing[j].back()) {
                    testing[i].pop_back();
                    testing[j].pop_back();
                    mp[{testing[0].size(), testing[1].size(), testing[2].size()}] = 1;
                    next = true;
                    break;
                }
            }
            if (next) break;
        }
        if (!next) break;
    }
    int h[3];
    for (int i = 0; i < 3; ++i) h[i] = testing[i].size();

    // for (auto v : testing) {
    //     for (auto c : v) cerr << c << ' ';
    //     cerr << '\n';
    // }
    // cerr << '\n';

    // for (auto [u, v] : mp) {
    //     auto [x, y, z] = u;
    //     cerr << x << ' ' << y << ' ' << z << '\n';
    // }

    vector<vector<int>> pref(3, vector<int>(n+1));  
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            pref[i][j+1] = pref[i][j] + (init[i].size() > j && init[i][j] == 1);
        }
    }

    while (q--) {
        int m[3];
        for (int i = 0; i < 3; ++i) {
            cin >> m[i];
        }
        bool skip = false;
        for (int i = 0; i < 3; ++i) {
            if (m[i] < h[i]) {
                cout << "Lihwy\n";
                skip = true;
                break;  
            }
        }
        if (skip) continue;
        cout << (mp[{m[0], m[1], m[2]}] == 1 ? "MofK\n" : "Lihwy\n");
    }
}


int32_t main() {

   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}