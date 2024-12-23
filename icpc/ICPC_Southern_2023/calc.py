a, b, m = map(int, input().split())

def mulmod(a, b, m):
    a %= m
    b %= m
    if b <= 10**18 / a: return (a * b) % m

    res = 0
    while a != 0:
        if a & 1:
            if b >= m - res: res -= m
            res += b

            a >>= 1
            if b >= m - b: b += b - m
            else: b += b
    return res

def powmod(a, b, m):
    res = 1
    while b != 0:
        if b & 1: res = mulmod(res, a, m)
        a = mulmod(a, a, m)
        b >>= 1
    return res

def kth (a, b, m):
    return 10 * mulmod(a, powmod(10, m, b), b) // b

print(kth(a, b, m))
