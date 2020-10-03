# github username : Titan1911

# program to check an odd number

print('**********Welcome to the program to check whether a number is odd or not**********')
check_number = int(input('Enter a positive number : '))
if check_number>=0:
    if check_number%2==0:
        print('The number is not odd')
    if check_number%2==1:
        print('The number is an odd number')

else:
    print("Invalid Number")
