def minimize_penalty(T, test_cases):
   results = []
   
   for n, S, t, v in test_cases:
      hw = [(t[i], v[i]) for i in range(n)]
      
      hw.sort(key=lambda x: (x[0], -x[1]))
      
      # Initialize time and penalty
      current_time = S
      total_penalty = 0
      
      for time_release, penalty in hw:
         if current_time < time_release:
               current_time = time_release
         total_penalty += (current_time - time_release) * penalty
         current_time += 1 
         
      results.append(total_penalty)
   
   return results


T = int(input())
for _ in range(T):
   n, S = map(int, input().split())
   t = list(map(int, input().split()))
   v = list(map(int, input().split()))
   test_cases = [(n, S, t, v)]
   print(minimize_penalty(T, test_cases))
