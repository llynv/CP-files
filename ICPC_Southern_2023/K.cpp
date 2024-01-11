#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
using namespace std;
const ll MAX = 1e6 + 7;

ll a[MAX], n;

void enter()
{
    cin >> n;
    fu(i, 1, n)
        cin >> a[i];
}

ll pre[MAX], aft[MAX];

bool isGood(ll h)
{
    pre[1] = 1;
    fu(i, 2, n)
    {
        if(a[i] > a[i - 1] || a[i] >= h || a[i] > pre[i - 1])
            pre[i] = pre[i - 1] + 1;
        else
        {
            pre[i] = min(pre[i - 1], a[i]);
        }
    }

    aft[n] = 1;
    fd(i, n - 1, 1)
    {
        if(a[i] > a[i + 1] || a[i] >= h || a[i] > aft[i + 1])
            aft[i] = aft[i + 1] + 1;
        else
            aft[i] = min(aft[i + 1], a[i]);
    }

//    fu(i, 1, n)
//        cout << pre[i] << " ";
//    cout << "\n";
//    fu(i, 1, n)
//        cout << aft[i] << " ";
    fu(i, 1, n)
    {
        if(pre[i] >= h&& aft[i] >= h)
            return true;
    }
    return false;
}


void solve()
{
    ll l = 1, r = n;
    ll res = 1;
    while(l <= r)
    {
        ll mid = (l + r) / 2;
        if(isGood(mid))
        {
            res = max(res, mid);
            l = mid + 1;
        }
        else
            r = mid - 1;
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