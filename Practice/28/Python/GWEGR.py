def print_factorization(number: int) -> None:
    deletes = dict()
    div = 2
    i = 2
    number = 1 
    while number > 1:
        for i in range(i <= number):
            if not(number % i):
                number /= i
                deletes[i] = deletes.count(i) (deletes[i] + 1 if condition else 1)
                break
    print("1")
    for i in range(deletes.count()):
        if (current.second > 1):
            print("",current.first,"^", current.second)
        else:
            print("*", current.first)
numb = input("Введите число для отфакторивания")
print_factorization(numb)
