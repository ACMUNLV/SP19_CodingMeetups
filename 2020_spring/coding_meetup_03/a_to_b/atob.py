# @author Benjamin Alcocer

inputArr = input().split()
a = int(inputArr[0])
b = int(inputArr[1])

# I think there was a slight improvement on the algorithm, but I forgot, and
# I don't want to look through it. It still passes all test cases so it is
# trivial.
if a == b:
    print(0)
elif a < b:
    print(b - a)
else:
    count = 0
    while a > b:
        if a & 1:
            a += 1
        else:
            a = a // 2
        count += 1
    print(count + (b - a))
