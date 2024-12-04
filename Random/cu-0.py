# #1
# strs = input()
# strs = strs.split(" ")
# w = ""
# for s in strs:
#     if len(s)>len(w):
#         w = s
# print(w)
# print(len(w))

# #2
# a = float(input())
# b = float(input())
# c = float(input())
# d = float(input())
# x = -b/a
# if(c*x + d == 0):
#     print("NO")
#     exit()
# if(a == 0):
#     print("INF")
#     exit()
# print(x)

#3
ss1 = input().split(" ")
ss2 = input().split(" ")

i = 0
j = 0
if ss1[i]==ss2[j]:
    j+=1
if j == 0:
    print("NO")
    exit()
while i < len(ss1) and j < len(ss2):
    if ss1[i] == ss2[j]:
        j+=1
        continue
    if ss1[i] != ss2[j]:
        print("NO")
        exit()
    while ss1[i] == ss2[j-1]:
        i+=1

print("YES")


