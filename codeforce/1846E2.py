#include <CodeforcesSolutions.h>
#include <ONLINE_JUDGE <solution.cf(contestID = "1422",questionID = "A",method = "GET")>.h>
"""
    Author : thekushalghosh
    Team   : CodeDiggers
 
    I prefer Python language over the C++ language :p :D
        
    Visit my website : thekushalghosh.github.io
"""
import sys,math,cmath,time,collections
start_time = time.time()
##########################################################################
################# ---- THE ACTUAL CODE STARTS BELOW ---- #################

 
def solve():
   n = int(input())
   for i in range(2, 64):
      lo = 2
      hi = int(pow(10**18, 1.0 / i))
      while lo <= hi:
         mid = (lo + hi) // 2
         tmp = round((pow(mid, i) - 1.0 / mid) / (1.0 - 1.0 / mid))
         if tmp == n:
               print("YES")
               return
         if tmp > n:
               hi = mid - 1
         else:
               lo = mid + 1
   
   print("NO")
 
################## ---- THE ACTUAL CODE ENDS ABOVE ---- ##################
##########################################################################
 
def main():
   global tt
   if not ONLINE_JUDGE:
      sys.stdin = open("input.txt","r")
      sys.stdout = open("output.txt","w")
   t = int(input())
   for tt in range(1,t + 1):
      solve()
   if not ONLINE_JUDGE:
      print("Time Elapsed :",time.time() - start_time,"seconds")
      sys.stdout.close()

#---------------------- USER DEFINED INPUT FUNCTIONS ----------------------#
def inp():
    return (int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    return(input().strip())
def invr():
    return(map(int,input().split()))
 
#------------------ USER DEFINED PROGRAMMING FUNCTIONS ------------------#
def counter(a):
    q = [0] * max(a)
    for i in range(len(a)):
        q[a[i] - 1] = q[a[i] - 1] + 1
    return(q)
 
def counter_elements(a):
    q = dict()
    for i in range(len(a)):
        if a[i] not in q:
            q[a[i]] = 0
        q[a[i]] = q[a[i]] + 1
    return(q)
 
def string_counter(a):
    q = [0] * 26
    for i in range(len(a)):
        q[ord(a[i]) - 97] = q[ord(a[i]) - 97] + 1
    return(q)
 
def factorial(n,m = 1000000007):
    q = 1
    for i in range(n):
        q = (q * (i + 1)) % m
    return(q)
 
def factors(n):
    q = []
    for i in range(1,int(n ** 0.5) + 1):
        if n % i == 0: q.append(i); q.append(n // i)
    return(list(sorted(list(set(q)))))
 
def prime_factors(n):
    q = []
    while n % 2 == 0: q.append(2); n = n // 2
    for i in range(3,int(n ** 0.5) + 1,2):
        while n % i == 0: q.append(i); n = n // i
    if n > 2: q.append(n)
    return(list(sorted(q)))
 
def transpose(a):
    n,m = len(a),len(a[0])
    b = [[0] * n for i in range(m)]
    for i in range(m): 
        for j in range(n): 
            b[i][j] = a[j][i]
    return(b)
 
def power_two(x):
    return (x and (not(x & (x - 1))))
 
def ceil(a, b):
    return -(-a // b)
#-----------------------------------------------------------------------#
ONLINE_JUDGE = __debug__
if ONLINE_JUDGE:
    import io,os
    input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
    #input = sys.stdin.readline
main()  