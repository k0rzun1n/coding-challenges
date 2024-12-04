# 10 5 2
# 1 3 3 2 1   #3
# nmk

n, m, k = map(int, input().split())
workers = list(map(int, input().split()))
workers.sort(reverse=True)

dayMod = 0
days = 0
while n > 0:
    # print("----------")
    for i in range(k * dayMod, min(k * (dayMod + 1), len(workers))):
        # print(workers[i])
        n -= workers[i]
    dayMod = (dayMod + 1) % 2
    days += 1

print(days)
# print(n)
# print(m)
# print(k)
# print(workers)
