h1,m1 = input("Во сколько пришел первый человек?").split(':')
h1=int(h1)
m1=int(m1)
if h1>23 or h1<0  or m1<0 or m1>59:
    print("Неверный формат времени")
h2,m2 = input("Во сколько пришел второй человек?").split(':')
h2=int(h2)
m2=int(m2)
if h2>23 or h2<0 or m2<0 or m2>59:
    print("Неверный формат времени")
hc= h2-h1
mc= m2-m1

if h1==23 and h2 == 0:
    if mc>=-59 and mc<=-45:
        print("встреча состоится")
    else:
        print("Встреча не состоится")
elif hc == 0:
    if mc>15:
        print("встреча не состоится")
    else:
        print("Встреча состоится")
elif hc == 1:
    x = (h1 * 60) + m1
    y = (h2 * 60) + m2
    if ((y-x)>15): 
        print("Встреча не состоится")
    else:
        print("Встреча состоится")
else:
    print("Встреча не состоится")