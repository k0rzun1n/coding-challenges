a = int(input())  # days
b = int(input())  # days
c = int(input())  # hours
d = int(input())  # hours
n = int(input())  # weeks

days = n * 7
cycle_days = a + b
per_cycle_h = a*c + b*d

full_cycles = int(days / cycle_days)

res = full_cycles * per_cycle_h
remaining_days = days % cycle_days
for _ in range(remaining_days):
    if(a>0):
        a-=1
        res+=c
    elif(b>0):
        b-=1
        res+=d

print(res)
