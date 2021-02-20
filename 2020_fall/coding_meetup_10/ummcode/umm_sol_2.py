# @author Benjamin A

import re
string = "".join(re.split("[^a-z A-Z0-9]*", input())).split()
arr = ''
for ele in string:
    if ele.replace('u', '').replace('m', '') == '':
        arr += ele
arr = arr.replace('u', '1').replace('m', '0')
n = 7
chunks = [arr[i:i+n] for i in range(0, len(arr), n)]
for element in chunks:
    print(chr(int(element, 2)), end = '')
