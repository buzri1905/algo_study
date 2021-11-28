import sys
input = sys.stdin.readline

num_lan, need_lan = map(int, input().split())
lans = [int(input()) for _ in range(num_lan)]

left, right = 1, 4000000000
while left < right:
    mid = (left + right) // 2
    if sum(lan // mid for lan in lans) >= need_lan:
        left = mid + 1
    else:
        right = mid
print(left - 1)
