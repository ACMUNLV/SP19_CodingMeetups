# @author Benjamin Alcocer

array = input().split()
vertical = int(array[2])
horizontal = int(array[3])

verts = []
for i in range(vertical):
    verts.append(int(input()))

str1 = ""
str2 = ""
for i in range(horizontal):
    num = int(input())
    if i % 2:
        str1 += 'W' * num
        str2 += 'B' * num
    else:
        str1 += 'B' * num
        str2 += 'W' * num
str1 += "\n"
str2 += "\n"

flip = True
for ele in verts:
    if flip:
        print(str1 * ele, end = '')
    else:
        print(str2 * ele, end = '')
    flip = not flip
