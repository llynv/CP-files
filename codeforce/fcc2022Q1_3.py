t = int(input())

def f(n):
    res = 0
    while (n):
        res += n % 10
        n //= 10;
    return res;

global ans
def calc (n, nxt, m, k):
    if nxt == 0:
        if n % m == k:
            ans = min(ans, n)
        return 0

    for i in range(1, nxt+1):
        return calc(n * 10 + i, nxt, m, k)

for _ in range(t):
    l, r, m, k = [int(x) for x in input().split()]

    # print(l, r, m, n)

    if m == 1:
        s = "";
        while (l >= 9):
            s += '9';
            l -= 9;
        if (l != 0): s += str(l);
        s = s[::-1]
        print(s)
        continue
    
    if r == 1:
        n = 1
        res = -1
        while (n <= 10*1000):
            if (n % m == k):
                res = n
                break
            n *= 10
        print(res)
        continue

    res = 10*1000
    sc = calc(0, l, m, k)
    if (res == 10*1000):
        print(-1);
    else:
        print(res)
