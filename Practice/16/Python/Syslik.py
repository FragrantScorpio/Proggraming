fails=0
i=0
number=int(input("Введите число билетов\n"))
for i in range(number):
    i=i+1 
    s = str(input())
    if s[0] == 'a' and s[4] == '5' and s[5] == '5' and s[6] == '6' and s[7] == '6' and s[8] == '1':
        answer = s
    else:
        fails = fails + 1
if fails == number:
    print("-1")
else:
    print(answer)