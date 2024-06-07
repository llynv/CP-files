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
const int MOD = 1e9+7;

constexpr int sum(int n) { for (int i = 1; i <= n; ++i) {} return n; }

int main()
{
    fastio;
    time_t start = clock();
    cout << sum(1000000000) << endl;
    time_t end = clock();
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
}
 