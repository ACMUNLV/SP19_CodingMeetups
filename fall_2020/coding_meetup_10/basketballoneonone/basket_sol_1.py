# @author Benjamin Alcocer

line = input()
n = 2
line = [line[i:i+n] for i in range(0, len(line), n)]
A = 0
B = 0
for ele in line:
    if ele[0] == 'A':
        A += int(ele[1])
    else:
        B += int(ele[1])
print('A' if A > B else 'B')
