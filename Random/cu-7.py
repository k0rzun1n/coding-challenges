res = ""

for w in input().split():
    if w == w[::-1]: res += w+" "

print(res[:-1])
