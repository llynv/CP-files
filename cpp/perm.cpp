#include "perm.h"

std::vector<int> construct_permutation(long long x)
{
    long long sum = 1;

    long long mn = 0;

    std::vector<int> res;

    while (sum < x)
    {
        long long cnt = 0;
        for (long long i = 1; i <= 62; ++i)
        {
            if (sum + (1ll << i) - 1 > x)
            {
                sum += (1ll << (i - 1)) - 1;
                cnt = i - 1;
                break;
            }
        }
        // dbg(sum, cnt);
        for (long long i = mn; i < mn + cnt; ++i)
        {
            // cout << i << " ";
            res.push_back(i);
        }
        mn -= cnt - 1;
        // for (long long i = 62; i >= 1; --i)
        // {
        //     if (sum + (1ll << (i - 1)) <= x)
        //     {
        //         sum += (1ll << (i - 1));
        //         cnt = i - 1;
        //         res.push_back(mn + cnt);
        //     }
        // }
    }
    long long minVal = res[0];
    for (int i = 0; i < res.size(); ++i)
    {
        minVal = std::min(minVal, (long long)res[i]);
    }
    for (int i = 0; i < res.size(); ++i)
    {
        res[i] -= minVal;
    }
    return res;
}