# t = int(input())

# for _ in range(t):
#     n = int(input())
#     a = list(map(int, input().split()))
#     c = list(map(int, input().split()))

#     def f(x):
#         res = 0
#         for i in range(n):
#             res += abs(a[i] - x) * c[i]
#         return res
    
#     # avg 

#     l = -10**6
#     r = 10**6


#     res = 10**100
#     pos = 0
#     for i in range(2):
#         while l < r:
#             m1 = l + (r - l) // 3
#             m2 = r - (r - l) // 3

#             f1 = f(m1)
#             f2 = f(m2)

#             if f1 < f2:
#                 r = m2 - 1
#                 if f1 < res:
#                     res = f1
#                     pos = m1
#             else:
#                 l = m1 + 1
#                 if f2 < res:
#                     res = f2
#                     pos = m2

#         if pos > 0:
#             l = pos
#             r = pos * 10**12
#         else:
#             l = pos * -10**12
#             r = pos
        
#     print("-inf" if res > min(f(-10**20), f(10**20)) else str(res))


def min_weighted_sum(a, c):
    n = len(a)
    
    # Create a list of tuples (a_i, c_i) and sort it based on a_i
    ac = sorted(zip(a, c), key=lambda x: x[0])
    
    # Calculate the total weight
    total_weight = sum(c)
    
    # Find the weighted median
    cumulative_weight = 0
    for i in range(n):
        cumulative_weight += ac[i][1]
        if cumulative_weight >= total_weight / 2:
            weighted_median = ac[i][0]
            break
    
    # Calculate the minimum weighted sum using the weighted median
    min_sum = sum(ci * abs(ai - weighted_median) for ai, ci in ac)
    
    return min_sum

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    c = list(map(int, input().split()))

    nev = 0
    for i in range(n):
        nev += c[i] < 0

    if nev == n:
        print("-inf")
        continue
    
    print(min_weighted_sum(a, c))