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

const int INF = 1e18;

int safeMultiply(int a, int b, int MOD)
{
    int res = 0;
    a = a % MOD;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res + a) % MOD;
        a = (a * 2) % MOD;
        b /= 2;
    }
    return res % MOD;

}

int lt(int x, int n, int MOD)
{
    if (x == 0)
    {
        return 0LL;
    }
    if (n == 0)
    {
        return 1LL;
    }
    if (n == 1)
    {
        return x;
    }
    int val = lt(x, n / 2, MOD);
    if (n % 2 == 0)
    {
        val = safeMultiply(val, val, MOD);
        return val;
    }
    else
    {
        // return (((val * val) % MOD) * x) % MOD;
        return safeMultiply(safeMultiply(val, val, MOD), x % MOD, MOD);
    }
}
void solve()
{
    int t, q, MOD;
    cin >> t >> q >> MOD;
    if (t == 1)
    {
        while (q--)
        {
            int n, m;
            cin >> n >> m;
            int ans = 0;
            for (int i = 0; i <= n; i++)
            {
                int tmp = (i < m);
                ans = (ans + (lt(i, n, MOD) * tmp) % MOD) % MOD;
            }
            cout << ans << "\n";
        }
    }
    else
    {
        while (q--)
        {
            int n, m;
            cin >> n >> m;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    while (numTest--)
    {
        solve();
    }
    return 0;
}