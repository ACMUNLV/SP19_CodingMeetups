# @author Benjamin Alcocer

import math

n = int(input())
arr = [0] * 44000
greatest = 0
for _ in range(n):
    d, t = map(int, input().split())
    arr[t] = arr[t] + 1
    arr[t - d] = arr[t - d] + 1
    arr[t - d - d] = arr[t - d - d] + 1
    if greatest < arr[t]:
        greatest = arr[t]
    if greatest < arr[t - d]:
        greatest = arr[t - d]
    if greatest < arr[t - d - d]:
        greatest = arr[t - d - d]
print(math.ceil(greatest / 2))
