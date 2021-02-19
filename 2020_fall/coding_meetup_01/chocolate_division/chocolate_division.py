# @author Benjamin Alcocer

import math

array = input().replace('\n', '').split()
n = int(array[0])
m = int(array[1])
d = math.gcd(n,m)
n = n // d
m = m // d
print(d if n % 2 == 1 and m % 2 == 1 else 0)
