#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define pii pair<ll, ll>
using namespace std;
const ll MAX = 1e6 + 7;

ll d, nd, m, nm;

void enter()
{
    cin >> d >> nd >> m >> nm;
}

void solve()
{
    if(m % d != 0)
    {
        cout << -1;
        return;
    }

    ll k = m / d;
    ll res = -1;

    fu(i, 1, sqrt(k))
    {
        if(k % i == 0)
        {
            ll tmp = i * d;
            if(tmp % nd != 0 && nm % tmp != 0)
            {
                if(res == -1)
                    res = tmp;
                else
                    res = min(res, tmp);
            }
        }
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    enter();
    solve();
}