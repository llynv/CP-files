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

// #define DBG

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    s= " "+s;
    vector<int>s1(n+1,0),s0(n+1,0);
    double ans = 1e18;
    for (int i = 1; i <= n; ++i) {
        s1[i] += s1[i-1] + (s[i] == '1');
        s0[i] += s0[i-1] + (s[i] == '0');
    }
    int pos = -1;
    for (int i = 0; i <= n; ++i) {
        int u = s1[i], v = s0[i], x = s1[n]-s1[i], y = s0[n]-s0[i];
        if((v>=(i+1)/2)&&(x>=(n-i+1)/2)) {
            if(ans > abs((double)n/(double)2-(double)i)) {
                ans = abs((double)n/(double)2-(double)i);
                pos = i;
            }
        }
    }
    cout<<pos<<"\n";
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