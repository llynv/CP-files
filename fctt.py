t = int(input())

def sumCP(x):
    return x*(x+1)*(2*x+1)//6
def sum(x):
    return x*(x+1)//2;

for _ in range(t):
    n, m = [int(x) for x in input().split()]
    if n > m:
        n, m = m, n
    
    stg = n*(n-1)//2 * (m-n) + (n-1)*n*(2*n-1)//6
    tsg = 0
    if min(n, m) >= 3:
        x = n - 2
        tsg = m*n*(n-1)//2 - m*(n+1)*(n+1)//4 - n*(n+1)*(n+1)//4 + (n-1)*(n+1)*n//6 + 2*(n-2) + 2*m*(n-2) + 2*n*(n-2)
        print(x)
    print(stg, stg + tsg)