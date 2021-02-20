# @author Benjamin Alcocer

array = input().split('-', 1)
print('YES' if len(array) == 2 and len(array[0]) > 1 and len(array[0]) <= 8 and len(array[1]) >= 1 and len(array[1]) <= 24 else 'NO')
