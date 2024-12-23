#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
string s;
vector<string> c;
vector<int> q, k[1000007];
 
void preset(int &lmax)
{
    string str;
    cin >> str;
    c.emplace_back(str);
    int e, x;
    cin >> e;
    q.emplace_back(e);
    for (int i = 0; i < e; ++i) {
        cin >> x;
        k[c.size()-1].emplace_back(x);
    }
    lmax = max(lmax, x + c[c.size()-1].size() - 1);
}
 
void solve(set<int> st)
{
    for (int i = 0; i < c.size(); ++i) {
        for (int j = 0; j < q[i]; ++j) {
            int pos = k[i][j] - 1;
            while (true) {
                set<int>::iterator it = st.lower_bound(pos);
                if (it == st.end() || *it >= c[i].size() + pos)
                    break;
                s[*it] = c[i][*it - pos];
                //cout << *it << " ";
                st.erase(it);
            }
        }
        cout << "\n";
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    int lmax = 0;
    set<int> st;
    for (int i = 0; i < t; ++i) {
        preset(lmax);
    }
    for (int i = 0; i < lmax; ++i) {
        s += 'a';
        st.insert(st.end(), i);
    }
    solve(st);
    cout << s;
}