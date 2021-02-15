# @author Benjamin Alcocer

n = int(input())
numArr = input().split()
mapping = {}

count = 0
for i in range(n):
    key = numArr[i] # no point, but to show the reader
    if key in mapping:
        if mapping[key] == 1:
            count += 1
            mapping[key] = 0
        else:
            mapping[key] = 1
    else:
        mapping[key] = 1
print(count)

