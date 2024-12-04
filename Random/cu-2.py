rowN,colN = map(int,input().split())
rows=[]
for _ in range(rowN):
    rows.append(input())
input()
count = 0    
for r in range(rowN):
    s = input()
    for x, y in zip(rows[r], s):
        if(x!=y):
            count += 1

print(count)

