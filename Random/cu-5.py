# 3
# 800.0
# 150.0 <
# 400.0 >     #  0 275.0

n = int(input())

mn = 0.0
mx = 1000.0

prev = float(input())
for i in range(1,n):
    test, comp = input().split()
    test = float(test)
    diff = prev - test
    if(comp == "<"): #closer
        mx = prev
        # mn = max(0, test - diff)
    elif(comp == ">"): #further
        mx = min(1000, prev - diff/2)
    prev = test

print(mn, mx)