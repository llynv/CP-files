t = int(input())

pre = {0: 0, 1: 2, 2: 6, 3: 14, 4: 20}

def f(n, last, len, x):
    if (n <= len): 
        for i in range(n):
            x += (x % 10)
        # print("n <= len", n, len, x, last - n)
        return x * (last - n);

    for i in range(len):
        x += (x % 10)

    n -= len
    last -= len

    step = n // 4
    r = n % 4

    # print((x + step * 20 + pre[r]) * (last - n));
    print(r, pre[r]);
    return (x + step * 20 + pre[r]) * (last - n);

def ternary_search(l, r, n, k, len):
    ans = 0
    while l <= r:
        m1 = l + (r - l) // 3
        m2 = r - (r - l) // 3
        f1 = f(m1, k, len, n)
        f2 = f(m2, k, len, n)
        ans = max(ans, f1, f2)
        if f1 < f2:
            l = m1 + 1
        else:
            r = m2 - 1
    print(f(l+1, k, len, n), f(l, k, len, n) ,f(l-1, k, len, n));
    return f(l, k, len, n)

for _ in range(t):
    n, k = [int(x) for x in input().split()]

    ch = [0] * 10
    i = 0
    x = n % 10
    while ch[x] == 0:
        ch[x] = i + 1
        i += 1
        x = (x + (x % 10)) % 10
    T = i - ch[x] + 1
    len = ch[x] - 1
    if T != 4:
        for i in range(len):
            n += (n % 10)
        print(n * (k - len))
        continue

    print(ternary_search(0, k, n, k, len));
