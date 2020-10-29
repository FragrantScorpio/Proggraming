print("Введите число")
number = int(input())
ostatok = 1
del1 = 2
i = 2
while i < number:
    if (number % del1) == 0:
        print ("Составное")
        ostatok = del1
        number = del1
    del1 = del1 + 1
    i = i + 1
if ostatok == 1:
    print ("Простое")