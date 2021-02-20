# @author Benjamin Alcocer

import sys
from bisect import bisect_left

def solve(row, col, pos):
    # Get insertion point for pos in squareArr
    index = bisect_left(squareArr, pos) 
    
    # Update row and col to the perfect square location
    row += index;
    col = row;
    
    # if position is not a perfect square, locate position on current spiral.
    # Else print perfect square location
    if squareArr[index] != pos:
        oneLess = 2 * index
        location = (squareArr[index] - position) // oneLess
        remainder = (squareArr[index] - position) % oneLess
        
        if location == 0:
            row -= remainder
        elif location == 1:
            row -= oneLess
            col -= remainder
        elif location == 2:
            row = row - (oneLess - remainder)
            col -= oneLess
        else:
            col = col - (oneLess - remainder)
    print('Line = {}, column = {}.'.format(row, col))

# Create array based off upright diagonal movement
# [1, 9, 25, 49, ...]
MAX = 50000 # n / 2
squareArr = [0] * MAX

squareValue = 1;
for i in range(MAX):
    squareArr[i] = squareValue * squareValue;
    squareValue += 2;

# For each line in stdin, solve for size, position
# size // 2 + 1 is the mid point of the matrix for row and col
for line in sys.stdin:
    size, position = map(int, line.split())
    if size != 0:
        solve(size // 2 + 1, size // 2 + 1, position)

