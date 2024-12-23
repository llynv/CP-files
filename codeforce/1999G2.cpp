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

void solve(int t)
{
    auto ask = [&] (int a, int b) -> int {
        cout << "? " << a << ' ' << b << "\n";
        cout.flush();
        int x;
        cin >> x;
        if (x == -1) exit(0);
        return x;
    };

    int l = 2, r = 999;
    int res = 2;
    while (l <= r)
    {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int x = ask(m1, m2);
        if (x == m1 * (m2 + 1)) {
            l = m1 + 1;
            r = m2 - 1;
            res = m2;
        } else if (x == (m1 + 1) * (m2 + 1)) {
            r = m1 - 1;
            res = m1;
        } else {
            l = m2 + 1;
        }
    }
    
    cout << "! " << res << "\n";
    cout.flush();
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
   solve(t);
   return 0;
}