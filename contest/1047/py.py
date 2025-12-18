n=int(input())
while n>0:
    n-=1
    s=input().split()
    for i in s:
        print(i[0],end="")
    print("")