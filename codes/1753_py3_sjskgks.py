import heapq
import sys
input = sys.stdin.readline

numOfVertex, numOfEdge = map(int, input().split())
start_node = int(input())-1
graph = [[] for _ in range(numOfVertex)]
for _ in range(numOfEdge):
    start, dest, cost = map(int, input().split())
    graph[start-1].append([cost, dest-1])

dist = ["INF" for _ in range(numOfVertex)]
q = []
heapq.heappush(q, [0, start_node])
while q:
    cost, cur_node = heapq.heappop(q)
    if dist[cur_node]!="INF":
        continue
    dist[cur_node]=cost
    for next_cost, next_node in graph[cur_node]:
        heapq.heappush(q, [cost+next_cost, next_node])
for vertex in range(numOfVertex):
        print(dist[vertex])