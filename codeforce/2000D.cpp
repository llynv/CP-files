/*
    Code by: KoKoDuDu
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define db double
#define pll pair<int, int>
#define pdb pair<db, db>
#define vector2d(name, sz1, sz2, type, val) vector<vector<type>> name(sz1, vector<type>(sz2, val))
#define vector3d(name, sz1, sz2, sz3, type, val) vector<vector<vector<type>>> name(sz1, vector<vector<type>>(sz2, vector<type>(sz3, val)))
#define vector4d(name, sz1, sz2, sz3, sz4, type, val) vector<vector<vector<vector<type>>>> name(sz1, vector<vector<vector<type>>>(sz2, vector<vector<type>>(sz3, vector<type>(sz4, val))))

const int MOD = 1e9 + 7;
const int INF = 1e18;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    string s;
    cin >> s;
    s = " " + s;
    vector<int> l, r;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'L')
        {
            l.push_back(i);
        }
        if (s[i] == 'R')
        {
            r.push_back(i);
        }
    }
    int ans = 0;
    int pos = r.size() - 1;
    for (int i = 0; i < l.size(); i++)
    {
        if (pos >= 0 && l[i] < r[pos])
        {
            ans += sum[r[pos]] - sum[l[i] - 1];
            pos--;
        }
    }
    cout << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    cin >> numTest;
    while (numTest--)
    {
        solve();
    }
    return 0;
}