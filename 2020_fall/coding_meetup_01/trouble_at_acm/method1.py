# @author Benjamin Alcocer

n = int(input())

count = 0

for _ in range(n):
    count += 1
    current = int(input())
    while count < current:
        print(count)
        count += 1
if count == n:
    print('good job')
