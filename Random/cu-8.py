a, b, c = map(int, input().split())

ds = b * b - 4 * a * c
if ds < 0:
    exit()
if a == 0:
    print(-c/b)
    exit()
if ds == 0:
    print(-b / (2 * a))
    exit()
d = ds**0.5
res = ""
res += str((-b - d) / (2 * a))
res += " "
res += str((-b + d) / (2 * a))
print(res)
