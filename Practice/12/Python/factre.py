print ("Введите число для факториала")
number = int(input())
i = 1
b = 1
if number < 0:
    print("Число должно быть положительным")
elif number == 0:
    print ("1")
else:
    while i <= number:
        b = b * i
        i =i + 1
    print(b)
