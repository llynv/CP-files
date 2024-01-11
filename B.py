import math
import sys

try:
    sys.set_int_max_str_digits(1000000)
except:
    pass

    
t = int(input())

for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]

    res = 0
    for i in range(1, n):
        if a[i] < a[i-1]:
            try:
                lg = math.ceil(math.log2(math.ceil(a[i-1] / a[i])))
            except:
                lg = 1
            res += lg
            a[i] *= 2 ** lg
    
    print(res)  