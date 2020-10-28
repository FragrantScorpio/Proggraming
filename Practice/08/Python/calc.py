print("Добро пожаловать в мой калькулятор, что хотите сделать?")
a,b,c= input()
a=int(a)
c=int(c)
answer=1
if b == '+':
    answer=a+c
elif b == '-':
    answer=a-c
elif b == '*':
    answer=a*c
elif b == '/':
    if c != 0:
        answer=a/c
    else: print("На ноль делить нельзя")
else: print("Неверный формат")
print(answer)
