#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 7;

int a[N];

struct itnode
{
    itnode *Left, *Right;
    int cnt = 0;

    itnode() {
        Left = Right = nullptr;
        cnt = 0;
    }
};

vector<itnode*> vers;

void CreateNode(itnode *&root) {
    root = new itnode();
    root->Left = new itnode();
    root->Right = new itnode();
}

void build (itnode *&root, int L, int R) {
    if (L == R) {
        root->cnt = 0;
        return;
    }
    int mid = (L + R) >> 1;
    CreateNode(root);
    build (root->Left, L, mid);
    build (root->Right, mid + 1, R);
}

void update (itnode *&root, int L, int R, int x)
{
    if (L == R) {
        root = new itnode();
        root->cnt = 1;
        return;
    }

    int mid = (L + R) >> 1;
    itnode *tmp = new itnode();
    *tmp = *root;

    if (x <= mid) {
        update (tmp->Left, L, mid, x);
    } else {
        update (tmp->Right, mid + 1, R, x);
    }
    tmp->cnt = tmp->Left->cnt + tmp->Right->cnt;
    root = tmp;
}

int get (itnode *it1, itnode *it2, int L, int R, int k)
{
    if (L == R) {
        return L;
    }

    int numb = it2->Left->cnt - it1->Left->cnt;
    int mid = (L + R) >> 1;
    if (numb >= k) {
        return get(it1->Left, it2->Left, L, mid, k);
    } else {
        return get(it1->Right, it2->Right, mid + 1, R, k - numb);
    }
}

void solve()
{
    int n, q; 
    cin >> n >> q;
    vector<int> b;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b.push_back(a[i]);
    }
    sort(all(b));
    set<ii> s;
    for (int i = 0; i < n; ++i) {
        s.insert(ii{b[i], i+1});
    }
    vector<int> lv(n+1), ans(n+1);
    for (int i = 1; i <= n; ++i) {
        auto c = s.lower_bound(ii{a[i], -1});
        lv[i] = (*c).se;
        ans[lv[i]] = a[i];
        s.erase(c);
    }

    itnode *ver0 = new itnode();
    build(ver0, 1, n);
    vers.push_back(ver0);
    for (int i = 1; i <= n; ++i) {
        itnode *nver = new itnode();
        *nver = *vers.back();
        update(nver, 1, n, lv[i]);
        vers.push_back(nver);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        itnode *it1 = vers[l-1];
        itnode *it2 = vers[r];
        cout << ans[get(it1, it2, 1, n, (r - l + 2) / 2)] << "\n";
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}