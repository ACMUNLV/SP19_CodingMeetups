# @author Benjamin Alcocer

str1 = input().strip()

setSize = pow(2, len(str1))

print("{", end = '')
for counter in range(setSize):

    print("{", end = '')

    # for length of string, compare counter to a shifting bit
    # 0001
    # 0010
    # 0100
    # 1000
    # The set bits of counter will trigger the shifting bit bitwise & operation
    # to result to true and the letter is outputted
    for i in range(len(str1)):
        if counter & (1 << i):
            print(str1[i], end = '')

    if counter + 1 != setSize:
        print("}, ", end = '')
    else:
        print("}}")
