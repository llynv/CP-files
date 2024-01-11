#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define loop_up(i,a,b) for( ll i = a ; i <= b ; i ++ )
#define loop_down(i,a,b) for( ll i = b ; i >= a ; i -- )
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define IOFile(in,out) freopen(in, "r", stdin); freopen(out, "w", stdout);
using namespace std;
const ll maxN = 2e5 + 0307;
const ll MOD = 1e9 + 7;
void solve()
{
    string s;
    ll l = 1 ;
    ll r = 1000000;
    while(l!=r)
    {
        ll mid =(l+r+1)/2;
        cout<<mid;
        cout.flush();
        cin>>s;
        if(s==">=")
        {
            l=mid;
        }
        else
        {
            r = mid - 1 ;
        }
    }

    cout<<"! "<<l;
    cout.flush();
}

int main()
{
//    IOFile("test.inp","test.out");
    fastio
    ll numTest = 1;
    while(numTest--)
    {
        solve();
    }
}