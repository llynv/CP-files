#include <iostream>
using namespace std;
#include <bits/stdc++.h>
long long int mod = 998244353;
 
long long int fastexpo(long long int a, long long int b)
{
    long long int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        b = b / 2;
        a = (a * a) % mod;
    }
    return ans % mod;
}
long long int fact[2000001];
vector<int> vec[200005];
bool vis[200005];
int height[200005];
int children[200005];
void dfs(int node, int par, vector<int> &ans)
{
    vis[node] = 1;
    ans.push_back(node);
    // cout << "dfs"
    //      << " " << node << "\n";
    // height[node] = height[par] + 1;
    for (auto child : vec[node])
    {
        // height[child] = height[node] + 1;
        if (!vis[child])
        {
            dfs(child, node, ans);
            // children[node] += children[child];
        }
    }
}
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1000;
    while (t--)
    {
        int n = rand() % 100000 + 1;
        int k = rand() % 100000 + 1;
        string s1, s2;
        cin >> s1 >> s2;
        // int dp[26] = {0};
        for (int i = 0; i < s1.size(); i++)
        {
            // dp[s1[i]]
            if (i + k < n)
            {
                vec[i].push_back(i + k);
                vec[i + k].push_back(i);
            }
            if (i + k + 1 < n)
            {
                vec[k + i + 1].push_back(i);
                vec[i].push_back(i + k + 1);
            }
        }
        bool f = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> ans;
            if (!vis[i])
            {
                dfs(i, -1, ans);
                // for (int j = 0; j < ans.size(); j++)
                // {
                //     cout << ans[j] << "\n";
                // }
                int dp[26] = {0};
                for (int j = 0; j < ans.size(); j++)
                {
                    dp[s1[ans[j]] - 'a']++;
                }
                for (int j = 0; j < ans.size(); j++)
                {
                    dp[s2[ans[j]] - 'a']--;
                }
                for (int j = 0; j < 26; j++)
                {
                    if (dp[j] != 0)
                    {
                        f = 1;
                    }
                }
            }
        }
        if (f)
        {
            cout << "NO"
                 << "\n";
        }
        else
        {
            cout << "YES"
                 << "\n";
        }
        for (int i = 0; i <= n; i++)
        {
            vec[i].clear();
            vis[i] = 0;
        }
    }
 
    return 0;
}