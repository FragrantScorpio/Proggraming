import random
print("Попробуйте угадать мое загаданное число, у вас 5 попыток\n")
randomN=random.randint(0, 100)
game = 1
win = 0
fails= 0
while game == 1:
    while fails < 5:
        userN=int(input())
        if userN>100 or userN<0:
            print("Введите число из диапазона(0-100)")
        elif userN>randomN:
            print("Загаданное число меньше")
            fails=fails+1
        elif userN<randomN:
            print("Загаданное число больше")
            fails=fails+1
        elif userN==randomN:
            print("Поздравляю, вы угадали число!")
            win=win+1
            fails=5
    if win == 0:
        if fails == 5:
            print("Вы проиграли, загаданное число:", randomN)
            print("Хотите сыграть снова?\n1.Да\n2.Нет\n")
            game = int(input())
            if game == 1:
                fails = 0
                print("Попробуйте угадать мое загаданное число, у вас 5 попыток\n")
                continue
            else:
                break
    if win == 1:
        print("Хотите сыграть снова?\n1.Да\n2.Нет\n")
        game = int(input())
        if game == 1:
            fails =0
            print("Попробуйте угадать мое загаданное число, у вас 5 попыток\n")
            continue
        else:
            break