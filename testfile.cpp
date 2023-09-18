#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 7;
long long n;
vector<int> a[N];
int check[N];
long long nmax;

void dfs(int x , long long dem[]) {
    if(a[x].size() == 0) {
        // cout << x << '\n';
        dem[x] = 1;
        return;
    }
    for(auto it : a[x])  
        if(check[it] == 0) {
            check[it] = 1;
            // cout << it << " ";
            dfs(it , dem);
            dem[x] += dem[it];
            // check[it] = 0;
        }
}
int main() {
    // freopen("solve.inp" , "r" , stdin);
    // freopen("solve.out" , "w" , stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long dem[n + 1];
        for(int i = 1 ; i <= n ; ++i)
            a[i].clear();
        memset(dem , 0 , sizeof(dem));
        memset(check , 0 , sizeof(check));
        for(int i = 1 ; i <= n - 1 ; ++i) {
            int x , y;
            cin >> x >> y;
            if(y > x) a[x].push_back(y);
            else a[y].push_back(x);
        }
        dfs(1 , dem);
        // for(int i = 1 ; i <= n ; ++i)
        //     cout << dem[i] << " ";
        // cout << '\n';
        int q;
        cin >> q;
        while(q--) {
            int x , y;
            cin >> x >> y;
            cout << dem[x] * dem[y] << '\n';
        }
    }
}