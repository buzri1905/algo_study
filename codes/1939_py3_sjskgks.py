import sys
from collections import deque
input = sys.stdin.readline

numOfIsland, numOfbridge = map(int, input().split())
graph = [[] for _ in range(numOfIsland+1)]
for _ in range(numOfbridge):
    start, dest, weight = map(int, input().split())
    graph[start].append([dest, weight])
    graph[dest].append([start, weight])

start, dest = map(int, input().split())

min_weight, max_weight = 1, 1000000001
mid = (min_weight+max_weight)//2
find_answer=False
while True:
    if find_answer:
        break
    visit = [0 for _ in range(numOfIsland+1)]
    q = deque([start])
    visit[start]=1
    can_pass = False
    while q:
        cur_pos = q.popleft()
        if cur_pos==dest:
            can_pass=True
            break
        for next_island in graph[cur_pos]:
            next_pos, weight_limit = next_island
            if not visit[next_pos] and mid<=weight_limit:
                q.append(next_pos)
                visit[next_pos]=1
    if can_pass:
        if max_weight-mid==1:
            find_answer=True
            print(mid)
            break
        min_weight = mid
        mid = (min_weight+max_weight)//2
    else:
        max_weight=mid
        mid=(min_weight+max_weight)//2