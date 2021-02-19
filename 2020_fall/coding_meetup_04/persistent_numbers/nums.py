# @author Benjamin A

num = int(input())
steps = 0
while num >= 10:
    temp = 1
    while num != 0:
        temp *= (num % 10)
        num //= 10
    num = temp
    steps += 1
print(steps)
