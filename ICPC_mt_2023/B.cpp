#include<bits/stdc++.h>
#define ll long long
#define loop_up(i,a,b) for( ll i = a ; i <= b ; i ++ )
using namespace std;
const int maxN = 1e2 +0307;
const int MOD = 2023;
int dp[maxN][maxN][maxN];
int a[maxN];
int pos[370000];
int main()
{
    int n,q;
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
    for( int i = 1 ; i < n ; i ++ )
    {
        for( int j = i + 1 ; j <= n ; j ++ )
        {
            if(__gcd(a[i],a[j])==1&&a[i]<a[j])
            {
                dp[i][j][0]=1;
            }
            for( int u = i + 1 ; u < j ; u ++ )
            {
                if(a[u]<a[j]&&__gcd(a[u],a[j])==1)
                {
                    for( int v = 1 ; v <= n ; v ++ )
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
        int x,y,k;
        cin>>x>>y>>k;
        cout<<dp[pos[x]][pos[y]][k-1]<<"\n";
    }
}