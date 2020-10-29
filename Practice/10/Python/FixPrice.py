print("Введите число и диапазоны")
z = 0
s = int(input())
l1 = int(input())
r1 = int(input()) 
l2 = int(input()) 
r2 = int(input())  
if (l1-l2)==s:
    print(l1,l2)
elif (l1-r2)==s:
    print(l1,r2)
elif (r1-l2)==s:
    print(r1-l2)
elif (r1-r2)==s:
    print(r1,r2)
elif (l1+l2)==s:
    print(l1,l2)
elif (l1+r2)==s:
    print(l1,r2)
elif (r1+l2)==s:
    print(r1-l2)
elif (r1+r2)==s:
    print(r1,r2)
else:
    print(-1)
