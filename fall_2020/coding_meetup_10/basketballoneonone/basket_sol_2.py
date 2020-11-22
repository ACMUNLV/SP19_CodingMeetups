# Author: Michael Lazeroff
# Solution: Problem A Basketball One on One ICPC Mid Central USA Programming Contest 2019

scores = input()
A_sum = 0
B_sum = 0
difference = 1

for n in range(len(scores)):
    if scores[n] == 'A':
        A_sum += int(scores[n+1])
        n += 1
    if scores[n] == 'B':
        B_sum += int(scores[n+1])
        n += 1

    # check for tie at 10
    if A_sum == 10 and B_sum == 10:
        difference = 2

    # winning cases
    if difference == 1:
        if A_sum >= 11:
            print('A')
            break
        elif B_sum >= 11:
            print('B')
            break

    if difference == 2:
        if A_sum - B_sum >= 2:
            print('A')
            break
        if B_sum - A_sum >= 2:
            print('B')
            break
