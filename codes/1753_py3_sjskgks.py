import heapq
import sys
input = sys.stdin.readline

numOfVertex, numOfEdge = map(int, input().split())
start_node = int(input())-1
Graph = [[] for _ in range(numOfVertex)]
for _ in range(numOfEdge):
    start, dest, cost = map(int, input().split())
    Graph[start-1].append([cost, dest-1])

visit = [float("inf") for _ in range(numOfVertex)]
q = []
heapq.heappush(q, [0, start_node])
while q:
    cost, cur_node = heapq.heappop(q)
    if visit[cur_node]!=float('inf'):
        continue
    visit[cur_node]=cost
    for next_cost, next_node in Graph[cur_node]:
        heapq.heappush(q, [cost+next_cost, next_node])
for vertex in range(numOfVertex):
    if visit[vertex] == float("inf"):
        print("INF")
    else:
        print(visit[vertex])