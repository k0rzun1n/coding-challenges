# 5 
# 1 2 3 4 
# 1 2 3     # 3

s = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

count = 0
for q in a:
    if s-q in b:
        count += 1
print(count)

