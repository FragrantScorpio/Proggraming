import math
print("Каким способом будете решать?\n 1:Через длины сторон \n 2:Через координаты вершин")
Choice = int(input("Введите число: "))
if Choice == 1:
    a=int(input(""))
    b=int(input(""))
    c=int(input(""))
    hp=(a+b+c)/2
    S= math.sqrt(hp*(hp-a)*(hp-b)*(hp-c))
    print(S)
if Choice == 2:
    x1 = int(input("Введите x1: "))
    y1 = int(input("Введите y1: "))
    x2 = int(input("Введите x2: "))
    y2 = int(input("Введите y2: "))
    x3 = int(input("Введите x3: "))
    y3 = int(input("Введите y3: "))
    a = math.sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)))
    b = math.sqrt(((x3 - x2) * (x3 - x2)) + ((y3 - y2) * (y3 - y2)))
    c = math.sqrt(((x3 - x1) * (x3 - x1)) + ((y3 - y1) * (y3 - y1)))
    if ((a < b + c) & (b < a + c) & (c < a + b)):
     hdp = (a + b + c) / 2
     S = math.sqrt(hdp * (hdp - a) * (hdp - b) * (hdp - c))
     print("S = ", S)
    else:
     print("Такого треугольника нету")
else: print("Такого выбора нет")