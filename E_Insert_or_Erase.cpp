#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct Node {
    int val;
    Node *next, *prev;

    Node(int _val) {
        val = _val;
        next = NULL;
        prev = NULL;
    }

    Node() {
        val = 0;
        next = NULL;
        prev = NULL;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);

    fu(i, 1, n) { cin >> a[i]; }

    map<int, Node *> mp;

    Node *head = new Node(a[1]);
    Node *tail = NULL;

    auto prepare = [&] {
        Node *cur = head;
        cur->prev = NULL;
        fu(i, 1, n) {
            Node *next = (i < n ? new Node(a[i + 1]) : NULL);
            cur->next = next;
            mp[a[i]] = cur;
            if (i == n)
                tail = cur;
            if (next != NULL)
                next->prev = cur;
            cur = next;
        }
    };
    prepare();

    auto show = [&] {
        Node *cur = head;
        while (cur != NULL) {
            // cout << cur->val << " " << mp[cur->val]->val << "\n";
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << "\n";
    };

    int q;
    cin >> q;
    while (q-- > 0) {
        int t, x, y;
        cin >> t;
        if (t == 1) {
            cin >> x >> y;
            Node *newNode = new Node(y);
            Node *cur = mp[x];
            newNode->next = cur->next;
            cur->next = newNode;
            mp[y] = newNode;
            // show();
        } else {
            cin >> x;
            Node *cur = mp[x];
            Node *pre = cur->prev;
            Node *nxt = cur->next;
            // cout << cur->val << " " << prev->val << " " << next->val << "\n";

            if (pre != NULL) {
                pre->next = nxt;
            }

            if (nxt != NULL) {
                nxt->prev = pre;
            }

            if (cur == head) {
                head = nxt;
            }

            mp[x] = NULL;
            // show();
        }
    }
    show();
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}