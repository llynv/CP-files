#include<bits/stdc++.h>
#define ll long long
#define loop_up(i,a,b) for( ll i = a ; i <= b ; i ++ )
using namespace std;
const ll maxN = 1e2 +0307;
const ll MOD = 2023;
ll dp[maxN][maxN][maxN];
ll a[maxN];
ll pos[370000];
int main()
{
    ll n,q;
    cin>>n;
    loop_up(i,1,n)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    loop_up(i,1,n)
    {
        pos[a[i]]=i;
    }
    for( ll i = 1 ; i < n ; i ++ )
    {
        for( ll j = i + 1 ; j <= n ; j ++ )
        {
            if(__gcd(a[i],a[j])==1&&a[i]<a[j])
            {
                dp[i][j][0]=1;
            }
            for( ll u = i + 1 ; u < j ; u ++ )
            {
                if(a[u]<a[j]&&__gcd(a[u],a[j])==1)
                {
                    for( ll v = 1 ; v <= n ; v ++ )
                    {
                        dp[i][j][v]+=dp[i][u][v-1];
                        dp[i][j][v]%=MOD;
                    }
                }
            }
        }
    }
    cin>>q;
    while(q--)
    {
        ll x,y,k;
        cin>>x>>y>>k;
        cout<<dp[pos[x]][pos[y]][k-1]<<"\n";
    }
}