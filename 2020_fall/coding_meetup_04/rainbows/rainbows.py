# @author Benjamin A

string = input()

MOD = 11092019

chars = [0] * 26
for i in range(len(string)):
    chars[ord(string[i]) - 97] += 1
ans = 1
for freq in range(26):
    if chars[freq] != 0:
        ans = ans * (chars[freq] + 1) % MOD
print(ans)
