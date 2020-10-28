print("Введите число и степень")
number=float(input())
stepen=float(input())
mnojitel=float(number)
Bmnojitel = 1
if stepen == 1:
    print(c)
elif stepen == 0:
    print(1)
elif stepen>0:
    while Bmnojitel < stepen:
        Bmnojitel = Bmnojitel + 1
        number = number * Bmnojitel
    print(number)
else:
    d = float(1/number)
    while Bmnojitel > stepen:
        Bmnojitel = Bmnojitel - 1
        number = number * d
    print(number)