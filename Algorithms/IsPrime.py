num = int(input("Enter a number: "))
if num < 2:
    print('is not prime')
elif num == 2:
    print('prime')
elif num % 2 == 0:
    print('is not prime')
else:
    for i in range(3, num // 2, 2):
        if num % i == 0:
            print('is not prime')
            break
    else:
        print('prime')
