import sys
from collections import deque
input = sys.stdin.readline

numOfCase = int(input())
for _ in range(numOfCase):
    numOfVertex, numOfEdge = map(int, input().split())
    graph=[[] for _ in range(numOfVertex+1)]
    for __ in range(numOfEdge):
        start, dest = map(int, input().split())
        graph[start].append(dest)
        graph[dest].append(start)
    visit = [0 for _ in range(numOfVertex+1)]
    is_biparatite=True
    for vertex in range(1, numOfVertex+1):
        if visit[vertex]:
            continue
        q = deque([[vertex , 1]])
        while q:
            cur_pos, pos_flag = q.popleft()
            if visit[cur_pos]==-1*pos_flag:
                is_biparatite=False
                break
            if not visit[cur_pos]:
                visit[cur_pos]=pos_flag
                for next_pos in graph[cur_pos]:
                    q.append([next_pos, -1*pos_flag])
        if not is_biparatite:
            break
    if is_biparatite:
        print('YES')
    else:
        print('NO')