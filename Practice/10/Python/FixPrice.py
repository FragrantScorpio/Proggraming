print("Введите число и диапазоны через пробел")
s, l1, r1, l2, r2 = input().split(' ')
z = 0
s = int (s)
l1 = int (l1)
r1 = int (r1)   
r2 = int (r2)   
l2 = int (l2)     
if (l1-l2)==s or (l1+l2)==s:
    print(l1,l2)
elif (l1-r2)==s or (l1+r2)==s:
    print(l1,r2)
elif (r1-l2)==s or (r1+l2)==s:
    print(r1-l2)
elif (r1-r2)==s or (r1+r2)==s:
    print(r1,r2)
else:
    print(-1)
