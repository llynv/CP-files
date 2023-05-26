#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define int long long

using namespace std;

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n+2), l, r;
    a[0] = a[n+1] = 0;
    stack<int> st;
    st.push(0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        while (a[i] <= a[st.top()]) {
            st.pop();
        }
        l.emplace_back(st.top());
        st.push(i);
    }
    st.push(n+1);
    for (int i = n; i >= 1; --i) {
        while (a[i] <= a[st.top()]) {
            st.pop();
        }
        r.emplace_back(st.top());
        st.push(i);
    }
    reverse(r.begin(), r.end());
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = max(res, (r[i]-l[i]-1) * a[i+1]);
    }
    cout << res;
}