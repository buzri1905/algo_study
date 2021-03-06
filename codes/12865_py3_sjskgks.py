import sys
input = sys.stdin.readline

numOfThings, limit = map(int, input().split())
knapsack = [[0,0] for _ in range(limit+1)]
for i in range(numOfThings):
    past_pos, cur_pos = i%2, (i+1)%2
    thing_weight, thing_value = map(int,input().split())
    for cur_limit in range(1, limit+1):
        if thing_weight<=cur_limit:
            knapsack[cur_limit][cur_pos]=max(knapsack[cur_limit][past_pos], thing_value+knapsack[cur_limit-thing_weight][past_pos])
        else:
            knapsack[cur_limit][cur_pos]=knapsack[cur_limit][past_pos]
print(knapsack[-1][cur_pos])