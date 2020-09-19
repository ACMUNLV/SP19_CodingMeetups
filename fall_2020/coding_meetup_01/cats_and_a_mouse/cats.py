# @author Benjamin Alcocer
# https://www.hackerrank.com/challenges/cats-and-a-mouse

n = int(input())

for _ in range(n):
    array = input().replace('\n', '').split()
    z = int(array[2])
    value = abs(z - int(array[0])) - abs(z - int(array[1]))
    print('Mouse C' if valueA == 0 else ('Cat A' if value < 0 else 'Cat B'))
