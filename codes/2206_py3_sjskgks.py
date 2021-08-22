import collections
import sys
input = sys.stdin.readline

def bfs(graph):
    visit = [[0 for _ in range(col)] for __ in range(row)] # 부순적 없이 방문하는 경우
    crush_visit = [[0 for _ in range(col)] for __ in range(row)] # 한번 부수면서 or 부순적 있이 방문하는 경우
    q = collections.deque([[0,0,1,0]]) # row, col, cost, crush
    visit[0][0]=1 # row, col
    while q:
        cur_r, cur_c, cur_cost, crush_num = q.popleft()
        if cur_r==row-1 and cur_c==col-1:
                return cur_cost
        for next_idx in [[cur_r-1,cur_c],[cur_r+1,cur_c],[cur_r,cur_c-1],[cur_r,cur_c+1]]:
            next_row, next_col = next_idx
            if next_row<row and -1<next_row and next_col<col and -1<next_col:
                if next_row==row-1 and next_col==col-1:
                    return cur_cost+1
                if not crush_visit[next_row][next_col]: #부수면서 방문하는 경우
                    if (graph[next_row][next_col] and crush_num==0) or (not graph[next_row][next_col] and crush_num==1): # 벽있고부수기가능or벽없고이미한번부숨
                        q.append([next_row, next_col, cur_cost+1, 1])
                        crush_visit[next_row][next_col]=1
                if not visit[next_row][next_col] and graph[next_row][next_col]==0 and crush_num==0: # 부수지않고 방문하는 경우
                    q.append([next_row, next_col, cur_cost+1, crush_num])
                    visit[next_row][next_col]=1
    return 10000000

graph = []
row, col = map(int, input().split())
for r in range(row):
    graph.append(list(map(int,input().rstrip())))

cost = bfs(graph)
if cost == 10000000:
    print(-1)
else:
    print(cost)
