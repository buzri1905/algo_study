import sys
input = sys.stdin.readline

for case in range(int(input())):
    numOfapp = int(input())
    applicants = [list(map(int, input().split())) for _ in range(numOfapp)]
    applicants.sort()
    recruit = 1
    limit = applicants[0][1]
    for i in range(1, numOfapp):
        if applicants[i][1]<limit:
            limit = min(limit, applicants[i][1])
            recruit+=1
        if limit == 1:
            break
    print(recruit)