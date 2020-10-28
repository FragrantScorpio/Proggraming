import math
print("Формула:ax^2+bx+c=0")
a=float(input())
b=float(input())
c=float(input())
kvadr=1
kvadr=pow(b,2)
if a==0:
 if b==0:
  print("Любое число")
 else: print((c-(2*c))/b)
else: 
 if b==0: 
  print(math.sqrt(c-2*c))
 else:
  d = kvadr-4*a*c
  x1 = (-b + math.sqrt(d))/2*a
  x2 = (-b - math.sqrt(d))/2*a
  print(x1,x2)