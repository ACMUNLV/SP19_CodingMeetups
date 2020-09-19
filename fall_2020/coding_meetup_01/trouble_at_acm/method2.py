# @author Benjamin Alcocer
# Method using arrays

n = int(input())

inputList = []
maximum = 0;

for _ in range(n):
    x = int(input())
    inputList.append(x)
    if maximum < x:
        maximum = x

trueList = [0] * maximum
for i in range(n):
    trueList[inputList[i] - 1] = True

goodjob = True
for i in range(maximum):
    if not trueList[i]:
        goodJob = False
        print(i + 1)

if goodJob:
    print('good job')
