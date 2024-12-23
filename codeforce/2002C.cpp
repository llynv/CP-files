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
const int MOD = 1e8;

#define Point pair<double, double>
#define F first
#define S second
using namespace std;
 
// Function to return the minimum distance
// between a line segment AB and a point E
double minDistance(Point A, Point B, Point E)
{
    // vector AB
    pair<double, double> AB;
    AB.F = B.F - A.F;
    AB.S = B.S - A.S;
 
    // vector BP
    pair<double, double> BE;
    BE.F = E.F - B.F;
    BE.S = E.S - B.S;
 
    // vector AP
    pair<double, double> AE;
    AE.F = E.F - A.F,
    AE.S = E.S - A.S;
 
    // Variables to store dot product
    double AB_BE, AB_AE;
 
    // Calculating the dot product
    AB_BE = (AB.F * BE.F + AB.S * BE.S);
    AB_AE = (AB.F * AE.F + AB.S * AE.S);
 
    // Minimum distance from
    // point E to the line segment
    double reqAns = 0;
 
    // Case 1
    if (AB_BE > 0) {
 
        // Finding the magnitude
        double y = E.S - B.S;
        double x = E.F - B.F;
        reqAns = sqrt(x * x + y * y);
    }
 
    // Case 2
    else if (AB_AE < 0) {
        double y = E.S - A.S;
        double x = E.F - A.F;
        reqAns = sqrt(x * x + y * y);
    }
 
    // Case 3
    else {
 
        // Finding the perpendicular distance
        double x1 = AB.F;
        double y1 = AB.S;
        double x2 = AE.F;
        double y2 = AE.S;
        double mod = sqrt(x1 * x1 + y1 * y1);
        reqAns = abs(x1 * y2 - y1 * x2) / mod;
    }
    return sqr(reqAns);
}


void solve()
{
    int n;
    cin >> n;
    vector<ii> a(n);
    for (auto &c : a) cin >> c.fi >> c.se;
    ii start, end;
    cin >> start.fi >> start.se >> end.fi >> end.se;
    dbg(start, end);
    int dist = sqr(start.fi - end.fi) + sqr(start.se - end.se);
    for (auto [x, y] : a) {
        int fn = sqr(x - end.fi) + sqr(y - end.se);
        dbg(dist, fn);
        if (fn <= dist) return void(cout << "NO\n");
    }
    cout << "YES\n";
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