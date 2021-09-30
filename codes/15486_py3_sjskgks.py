import sys
input = sys.stdin.readline

last_work = int(input())
max_reward_arr = [0 for _ in range(last_work+1)]
maxOfpre = 0 # 일 시작하는 날 전까지 중 최대 값

for day in range(1, last_work+1):
    work_day, reward = map(int, input().split())
    finish_day = day+work_day-1
    if finish_day <= last_work:
        max_reward_arr[finish_day] = max(reward+maxOfpre, max_reward_arr[finish_day])
    maxOfpre = max(maxOfpre, max_reward_arr[day])
print(maxOfpre)