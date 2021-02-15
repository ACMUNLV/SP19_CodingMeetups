# @author Benjamin Alcocer

friendCorrect = int(input())
myAnswers = input().replace('\n', '')
friendAnswers = input().replace('\n', '')

same = 0
size = len(myAnswers)
for i in range(size):
    if myAnswers[i] == friendAnswers[i]:
        same += 1
print(min(friendCorrect, same) + min(size - same, size - friendCorrect))
