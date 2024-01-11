#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
using namespace std;
const ll MAX_PRIME = 5e6 + 7;
const ll MOD = 998244353;

ll a, b;

ll spf[MAX_PRIME];
bool ob[MAX_PRIME];

void prepare_spf(ll maxVal)
{
    fu(i, 1, maxVal)
    spf[i] = i;
    fu(i, 2, maxVal)
    {
        if(spf[i] == i)
        {
            fu(j, 2, maxVal / i)
            if(spf[i * j] == i * j)
                spf[i * j] = i;
        }
    }
}


ll cal(ll x)
{
    ll ans = x;
    while(x != 1)
    {
        ll p = spf[x];
        if(ob[p] == false)
            ans -= ans / p;
        while(x % p == 0)
            x /= p;
    }
    return ans;
}

void solve()
{
    ll sum = 0;
    ll ans_a = a;
    ll x = a;
    while(x != 1)
    {
        ll p = spf[x];
        if(ob[p] == false)
        {
            ans_a -= ans_a / p;
            ob[p] = true;
        }
        while(x % p == 0)
            x /= p;
    }
    sum = ans_a % MOD;

    fu(i, 2, b)
    {
        ll ans_ai = cal(i);
        sum = (sum + (ans_ai * ans_a) % MOD) % MOD;
    }
    cout << sum;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//    freopen("input.inp", "r", stdin);
    cin >> a >> b;
    prepare_spf(max(a, b));
    solve();
}