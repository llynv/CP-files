#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5 + 11;

string ita[4 * N], itb[4 * N];
string a, b;

void buildA(int index, int L, int R)
{
    if (L == R)
    {
        ita[index] += a[L-1];
        return;
    }

    int mid = (L + R) / 2;
    buildA(index << 1, L, mid);
    buildA(index << 1 | 1, mid + 1, R);
    ita[index] = ita[index << 1];
    ita[index] += ita[index << 1 | 1];
    // cout << ita[index] << "\n";
}

string getA(int index, int L, int R, int l, int r)
{
    if (L > r || R < l) {
        return "";
    }
    if (L >= l && R <= r) {
        return ita[index];
    }

    int mid = (L + R) / 2;
    string v1 = getA(index << 1, L, mid, l, r);
    string v2 = getA(index << 1 | 1, mid + 1, R, l, r);
    string res = v1;
    res += v2;
    return res;
}

void buildB(int index, int L, int R)
{
    if (L == R)
    {
        itb[index] += b[L-1];
        return;
    }

    int mid = (L + R) / 2;
    buildB(index << 1, L, mid);
    buildB(index << 1 | 1, mid + 1, R);
    itb[index] = itb[index << 1];
    itb[index] += itb[index << 1 | 1];
}

string getB(int index, int L, int R, int l, int r)
{
    if (L > r || R < l) {
        return "";
    }
    if (L >= l && R <= r) {
        return itb[index];
    }

    int mid = (L + R) / 2;
    string v1 = getB(index << 1, L, mid, l, r);
    string v2 = getB(index << 1 | 1, mid + 1, R, l, r);
    string res;
    res += v1;
    res += v2;
    return res;
}

int KMP(string s, string t)
{
    int n = s.size(), m = t.size();
    vector<int> pi(m);
    for (int i = 1; i < m; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && t[i] != t[j])
            j = pi[j - 1];
        if (t[i] == t[j])
            j++;
        pi[i] = j;
    }
    int res = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j > 0 && s[i] != t[j])
            j = pi[j - 1];
        if (s[i] == t[j])
            j++;
        if (j == m)
            res++;
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    int q;
    cin >> q;
    buildA(1, 1, a.size()); 
    buildB(1, 1, b.size()); // O(nlog(n))
    map<pair<string, string>, int> mp;
    while (q--)
    {
        int l, r, u, v;
        cin >> l >> r >> u >> v;
        string s = getA(1, 1, a.size(), l, r); // O(log(n))
        string t = getB(1, 1, b.size(), u, v);

        pair<string, string> p = {t, s};
        if (mp[p]) {
            cout << mp[p] << endl;
            continue;
        }
        // cout << s << " " << t << endl;
        int tt = KMP(t, s); // O(n)
        mp[p] = tt;
        cout << tt << endl;

        // O(n);
    }
    
}
