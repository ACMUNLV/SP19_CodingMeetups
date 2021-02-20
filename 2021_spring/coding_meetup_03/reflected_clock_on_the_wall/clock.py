# @author Benjamin Alcocer

def intToStr(num):
    return str(num) if num >= 10 else '0' + str(num)

# initialize minArr
minArr = [''] * 60
minArr[0] = '00'
left = 59
for right in range(1, 60):
    minArr[right] = intToStr(left)
    left -= 1

# declare hour arrays (or initialize)
notZeroHour =   ['', '10', '09', '08', '07', '06', '05', '04', '03', '02', '01', '12', '11']
zeroHour =      ['', '11', '10', '09', '08', '07', '06', '05', '04', '03', '02', '01', '12']

# begin program and output
t = int(input())

for _ in range(t):
    hour, minute = map(int, input().split(':'))
    if minute != 0:
        print('{}:{}'.format(notZeroHour[hour], minArr[minute]))
    else:
        print('{}:{}'.format(zeroHour[hour], minArr[minute]))
