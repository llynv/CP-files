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
const int maxN = 1e5 + 0307;
const int MOD = 1e9 + 7;
const int N = 211;
int p[maxN],check[maxN];
vector<int>adj[maxN],save[maxN];
int _lcm(int a, int b)
{
    return (a * b) / __gcd(a, b);
}
void dfs( int x, int dem)
{
    check[x]=1;
    save[dem].push_back(x);
    for( int g : adj[x])
    {
        if(check[g]==0)
        {
            dfs(g,dem);
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=" "+s;
 
    bitset<N>bit[N];
 
    loop_up(i,0,n)
    {
        check[i]=0;
        adj[i].clear();
        save[i].clear();
    }
    loop_up(i,1,n)
    {
        cin>>p[i];
        adj[i].push_back(p[i]);
    }
    int dem = 0 ;
    loop_up(i,1,n)
    {
        if(check[i]==0)
        {
            dem++;
            dfs(i,dem);
        }
    }
    int kq = 1;
    vector<int>ans;
    loop_up(i,1,dem)
    {
    //    cout<<i<<"------------\n";
        set<char>tmp;
        for( int x : save[i])
        {
        //    cout<<x<<" ";
            bit[i][x]=1;
            tmp.insert(s[x]);
        }
        if(tmp.size()!=1)
        {
            ans.push_back((int)save[i].size());
        }
    //    cout<<"\n";
    }
    if(ans.size()==0)
    {
        cout<<1<<"\n";
    }
    else
    {

        bitset<N> pre = bit[1].to_ullong();
        for (int i = 1; i <= dem; ++i) {
            pre &= bit[i].to_ullong();
        }
        int rs = 0;
        for (int i = 0; i < n; ++i) {
            if (pre[i]) {
                rs = i + 1;
                break;
            }
        }

        int res = ans[0];
        loop_up(i,1,ans.size()-1)
        {
            res = _lcm(res,ans[i]);
        }
        cout<<min((rs == 0 ? MOD : rs), res)<<"\n";
    }
//    cout<<kq<<"\n";
}
int main()
{
//    IOFile("test.inp","test.out");
    fastio
    int numTest = 1;
    cin>>numTest;
    while(numTest--)
    {
        solve();
    }
}


