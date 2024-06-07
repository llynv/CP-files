
def u (i, m):
    return i**3 * m;

n = int(input())
lo = 1
hi = 10**12

while lo <= hi:
    mid = (lo + hi) // 2
    cnt = 0
    

    for i in range(2, 10001):
        l = 0
        r = mid
        while l <= r:
            m = (l + r) // 2
            if u(i, m) <= mid:
                l = m + 1
            else:
                r = m - 1
        if l <= 1:
            break
        cnt += l - 1
    if cnt >= n:
        hi = mid - 1
    else:
        lo = mid + 1


res = 0
for i in range(2, 10001):
    l = 1
    r = lo
    while l < r:
        m = (l + r) // 2
        if u(i, m) <= lo:
            l = m + 1
        else:
            r = m
    res += l - 1

if res != n:
    print(-1)
else:
    print(lo)


    # int n;
    # cin >> n;
    # int lo = 1, hi = 1e12;
    # while (lo <= hi) {
    #     int mid = lo + (hi - lo) / 2;
        
    #     int cnt = 0;
    #     for (int i = 2; i <= 10000; ++i) {
    #         int l = 0, r = mid;
    #         while (l <= r) {
    #             int m = l + (r - l) / 2;
    #             if (u(i, m) <= mid) l = m + 1;
    #             else r = m - 1;
    #         }

    #         if (l <= 1) break;

    #         // dbg(i, l, r);

    #         cnt += l - 1;
    #     }

    #     // dbg(cnt);

    #     if (cnt >= n) hi = mid - 1;
    #     else lo = mid + 1;
    # }
    # int res = 0;
    # for (int i = 2; i <= 10000; ++i) {
    #     int l = 1, r = lo;
    #     while (l < r) {
    #         int m = l + (r - l) / 2;
    #         if (u(i, m) <= lo) l = m + 1;
    #         else r = m;
    #     }

    #     res += l - 1;
    # }
    # if (res != n) return void(cout << "-1\n");
    # cout << lo << "\n";