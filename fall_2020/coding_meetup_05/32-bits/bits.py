lookup = {0:0, 1:1, 2:1, 3:2, 4:1, 5:2, 6:2, 7:3, 8:1, 9:2,
10:2, 11:3, 12:2, 13:3, 14:3, 15:4}

n = int(input())

for _ in range(n):
    maxNum = 0
    num = input()
    numStr = ''
    for ele in num:
        numStr += ele
        count = 0
        num = int(numStr)
        while num != 0:
            count += lookup[0xF & num]
            num = num >> 4
        if maxNum < count:
            maxNum = count
    print(maxNum)
