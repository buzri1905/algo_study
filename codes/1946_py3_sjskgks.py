import sys
input = sys.stdin.readline

for case in range(int(input())):
    numOfapp = int(input())
    applicants = sorted([list(map(int, input().split())) for _ in range(numOfapp)])
    recruit = 1
    limit = applicants[0][1]
    for _, rank in applicants:
        if rank<limit:
            limit = rank
            recruit+=1
        if limit == 1:
            break
    print(recruit)
