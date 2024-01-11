#include <bits/stdc++.h>
#define ll long long
#define fu(i,a,b) for(ll i = a; i <= b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
using namespace std;
const ll MAX = 107;
const ll MOD = 1e9 + 7;

ll n;
ll a[MAX];

void enter()
{
    cin >> n;
    fu(i, 1, n)
    {
        cin >> a[i];
    }
}

ll myPow(ll x, ll k)
{
    ll mul = x, res = 1;
    while(k > 0)
    {
        if(k % 2 == 1)
        {
            res = res * mul % MOD;
        }
        mul = mul * mul % MOD;
        k >>= 1;
    }
    return res;
}

void countSub(ll arr[], ll n)
{
    map<ll, ll> freq;
    map<ll, ll> subsets;

    ll arrMax = 0;

    fu(i, 1, n)
    {
        arrMax = max(arrMax, arr[i]);
        freq[arr[i]]++;
    }

    ll res = 0;
    fd(i, arrMax, 1)
    {
        ll sub = 0;
        ll add = freq[i];

        for (ll j = 2; j*i <= arrMax; j++)
        {
            add = (add + freq[j*i]) % MOD;

            sub = (sub + subsets[j*i]) % MOD;
        }
        subsets[i] = (myPow(2, add) - 1 - sub + MOD) % MOD;
        res = (res + (subsets[i] * i % MOD)) % MOD;
    }
    cout << res << "\n";

}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t --> 0)
    {
        enter();
        countSub(a, n);
    }
}