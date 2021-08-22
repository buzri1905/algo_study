import sys
import collections
input = sys.stdin.readline

N=int(input())
q = collections.deque([2, 3, 5, 7])
while q:
    cur_prime = str(q.popleft())
    if len(cur_prime)==N:
        print(int(cur_prime))
        continue
    for next_num in range(1, 10, 2):
        next_total = int(cur_prime+str(next_num))
        division=0
        for divider in range(2, int(next_total**0.5)+1):
            if next_total%divider==0:
                division=1
                break
        if division:
            continue
        q.append(next_total)
