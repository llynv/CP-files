#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
int n, m, k;


struct DSU{
    vector<int> e;
    int mx = 0;
    DSU(int N){ e = vector<int>(N, -1);}
    int get(int x){
        if(e[x] < 0) return x;
        return e[x] = get(e[x]);
    }
    int size(int x){return -e[get(x)];}
    bool unite(int a, int b){
        a = get(a); b = get(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        mx = max(mx, -e[a]);
        return true;
    }
};

void Kruskal(vector<pair<int,pair<int,int>>> edge){
    sort(edge.begin(), edge.end());
    int ans = 1e18;
    do{
        DSU u(n + 1);
        int temp = 0;
        for(pair<int,pair<int,int>> e : edge){
            int a = e.se.fi, b = e.se.se;
            if(u.unite(a, b)){
                temp += e.fi;
                temp %= k;
            }
        }
        ans = min(ans, temp);
    }while(next_permutation(edge.begin(), edge.end()));
    cout << ans;
}




int32_t main() {
    cin >> n >> m >> k;
    vector<pair<int,pair<int,int>>> edge(m);
    for(int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        edge[i-1] = {w % k, {x, y}};
    }
    Kruskal(edge);
}
