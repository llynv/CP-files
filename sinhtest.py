import sys
import random
import math

try:
    sys.set_int_max_str_digits(1000000)
except:
    pass

for i in range(10):
    with open(f'input ({i}).inp', 'w') as f:
        f.write(str(random.randint(1, 10**1000000)) + ' ' + str(random.randint(1, 10**18)))
        f.write('\n')