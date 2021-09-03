import sys
import collections
input = sys.stdin.readline

lenOfNum=int(input())
q = collections.deque([2, 3, 5, 7])
while q:
    cur_prime = str(q.popleft())
    if len(cur_prime)==lenOfNum:
        print(int(cur_prime))
        continue
    for next_num in range(1, 10, 2):
        next_total = int(cur_prime+str(next_num))
        division=False
        for divider in range(2, int(next_total**0.5)+1):
            if next_total%divider==0:
                division=True
                break
        if division:
            continue
        q.append(next_total)