import sys
input = sys.stdin.readline

numOfthings, limit = map(int, input().split())
knapsack = [[0 for _ in range(limit+1)] for _ in range(numOfthings+1)]
for thingidx in range(1, numOfthings+1):
    thing_weight, thing_value = map(int,input().split())
    for cur_limit in range(1, limit+1):
        if thing_weight<=cur_limit:
            knapsack[thingidx][cur_limit]=max(knapsack[thingidx-1][cur_limit], thing_value+knapsack[thingidx-1][cur_limit-thing_weight])
        else:
            knapsack[thingidx][cur_limit]=knapsack[thingidx-1][cur_limit]
print(knapsack[-1][-1])
