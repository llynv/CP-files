#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 7;
int a[N];
vector<int> fw[N], mp[N];

void update (int i, int val, int id)
{
    for (; i < fw[id].size(); i += i & -i) {
        fw[id][i] += val;
    }
}

int get (int i, int id)
{
    int res = 0;
    for (; i > 0; i -= i & -i) {
        res += fw[id][i];
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]].push_back(i+1);
    }

    for (int i = 1; i <= n; ++i) {
        if (mp[i].empty()) continue;
        
        fw[i].resize(mp[i].size() + 1, 0);
        for (int j = 0; j < mp[i].size(); ++j) {
            update(j+1, mp[i][j] * mp[i][j], i);
        }
    }

    int last = 0, t = 0;
    for (int i = 0; i < q; ++i) {
        cin >> t;
        if (t == 1) {
            int p;
            cin >> p;
            p = ((p + last - 1) % (n - 1)) + 1;
            if (a[p-1] == a[p]) continue;
            int fpos = lower_bound(mp[a[p-1]].begin(), mp[a[p-1]].end(), p) - mp[a[p-1]].begin();
            int spos = lower_bound(mp[a[p]].begin(), mp[a[p]].end(), p + 1) - mp[a[p]].begin();
            update(fpos + 1, -(p * p) + (p+1) * (p+1), a[p-1]);

            update(spos + 1, -((p+1)*(p+1)) + p*p, a[p]);

            mp[a[p-1]][fpos] = p + 1;
            mp[a[p]][spos] = p;

            swap (a[p-1], a[p]);

        } else if (t == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            l = (l + last - 1) % n + 1;
            r = (r + last - 1) % n + 1;
            x = (x + last - 1) % n + 1;
            if (l > r) swap(l, r);

            int pr = upper_bound(mp[x].begin(), mp[x].end(), r) - mp[x].begin();
            int pl = lower_bound(mp[x].begin(), mp[x].end(), l) - mp[x].begin();
            int res = get(pr, x) - get(pl, x);

            last = res;
            cout << res << "\n";
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            l = (l + last - 1) % n + 1;
            r = (r + last - 1) % n + 1;
            x = (x + last - 1) % n + 1;
            if (l > r) swap(l, r);
            int res = get(r, x) - get(l-1, x);
            last = res;
            cout << res << "\n";
        }
    }
}
