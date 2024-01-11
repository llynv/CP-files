#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define loop_up(i,a,b) for( ll i = a ; i <= b ; i ++ )
#define loop_down(i,a,b) for( ll i = b ; i >= a ; i -- )
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    fastio
    ll numTest;
    cin>>numTest;
    while(numTest--)
    {
        string s,t;
        cin>>s>>t;
        vector<char>chan1,chan2,le1,le2;
        if(s==t)
        {
            cout<<"YES\n";
            continue;
        }
        if((ll)s.size()!=(ll)t.size())
        {
            cout<<"NO\n";
            continue;
        }
        for( ll i = 0 ; i < s.size() ; i ++ )
        {
            if(i%2==0)
            {
                chan1.push_back(s[i]);
                chan2.push_back(t[i]);
            }
            else
            {
                le1.push_back(s[i]);
                le2.push_back(t[i]);
            }
        }
        sort(chan1.begin(),chan1.end());
        sort(chan2.begin(),chan2.end());
        sort(le1.begin(),le1.end());
        sort(le2.begin(),le2.end());
        if(chan1==chan2&&le1==le2)
        {
            cout<<"YES\n";
            continue;
        }
        else
        {
            cout<<"NO\n";
        }
    }
}