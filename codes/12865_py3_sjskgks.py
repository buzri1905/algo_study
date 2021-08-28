import sys
input = sys.stdin.readline

numOfThings, limit = map(int, input().split())
knapsack = [[0,0] for _ in range(limit+1)]
past_pos, cur_pos = 0, 1
for _ in range(numOfThings):
    thing_weight, thing_value = map(int,input().split())
    if cur_pos:
        past_pos, cur_pos=1, 0
    else:
        past_pos, cur_pos=0, 1
    for cur_limit in range(1, limit+1):
        if thing_weight<=cur_limit:
            knapsack[cur_limit][cur_pos]=max(knapsack[cur_limit][past_pos], thing_value+knapsack[cur_limit-thing_weight][past_pos])
        else:
            knapsack[cur_limit][cur_pos]=knapsack[cur_limit][past_pos]
print(knapsack[-1][cur_pos])