import sys
input = sys.stdin.readline

numOfcity = int(input())
numOfbus = int(input())

city_cost = [[float('inf') for _ in range(numOfcity)] for _ in range(numOfcity)]
for _ in range(numOfbus):
    start, dest, cost = map(int, input().split())
    city_cost[start-1][dest-1] = min(city_cost[start-1][dest-1], cost)

for via in range(numOfcity):
    for start in range(numOfcity):
        for dest in range(numOfcity):
            city_cost[start][dest] = min(city_cost[start][dest], city_cost[start][via]+city_cost[via][dest])

for start in range(numOfcity):
    city_cost[start][start]=0
    for dest in range(numOfcity):
        if city_cost[start][dest]==float("inf"):
            city_cost[start][dest] = 0
        print(city_cost[start][dest], end=" ")
    print("")