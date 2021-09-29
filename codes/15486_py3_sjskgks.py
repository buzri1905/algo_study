import sys
input = sys.stdin.readline

last_work = int(input())
max_reward = [0 for _ in range(last_work+1)]
max_day = 0 # 일 시작하는 날 전까지 중 최대 값
for day in range(1, last_work+1):
    work_day, reward = map(int, input().split())
    finish_day = day+work_day-1
    max_day = max(max_day, max_reward[day-1])
    if finish_day > last_work:
        continue
    max_reward[finish_day] = max(reward+max_day, max_reward[finish_day])
print(max(max_reward))
print(max_reward)