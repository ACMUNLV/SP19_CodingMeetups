k = int(input())

prev = int(input())
ans = 0
for _ in range(1, k):
    curr = int(input())
    if curr > prev:
        ans += 1
    prev = curr
print(ans + 1)
