#include<bits/stdc++.h>
#define ll long long
#define loop_up(i,a,b) for( ll i = a ; i <= b ; i ++ )
using namespace std;
const ll maxN = 1e6 ;
vector<ll>save;
map<ll,ll>valid;
int main()
{
    ll n,k;
    cin>>n>>k;
    ll check = 0;
    ll num2 = 0, num3 = 0 ;
    for ( ll i = 2 ; i*i <= n ; i ++ )
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
                if(i!=2&&i!=3)
                {
                    save.push_back(i);
                }
                if(i==2)
                {
                    num2++;
                }
                if(i==3)
                {
                    num3++;
                }
            }
            check=max(check,i);
        }
    }
    if(n!=1)
    {
        if(n!=2&&n!=3)
        {
            save.push_back(n);
        }
        check=max(check,n);
        if(n==2)
        {
            num2++;
        }
        if(n==3)
        {
            num3++;
        }
    }
    if(check>9)
    {
        cout<<-1;
        return 0;
    }
    for( ll i = 1 ; i <= num2/3 ; i ++ )
    {
        save.push_back((ll)8);
    }
    for( ll i = 1 ; i <= num3/2 ; i ++ )
    {
        save.push_back((ll)9);
    }
    ll tich = 1 ;
    for( ll i = 1 ; i <= num2%3 ; i ++ )
    {
        tich*=2;
    }
    for( ll i = 1 ; i <= num3%2 ; i ++ )
    {
        tich*=3;
    }
    if(tich==12)
    {
        save.push_back(2);
        save.push_back(6);
    }
    else if(tich!=1)
    {
        save.push_back(tich);
    }
    sort(save.begin(),save.end());
    if((ll)save.size()<=k)
    {
        for( ll i = 1 ; i <= k - (ll)save.size() ; i ++ )
        {
            cout<<1;
        }
        for( ll i = 0 ; i < (ll)save.size() ; i ++ )
        {
            cout<<save[i];
        }
    }
    else
    {
        cout<<-1;
    }
}