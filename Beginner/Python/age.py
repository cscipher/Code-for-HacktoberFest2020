# github username : Titan1911

# program to check the whether the person is an adult, teen or a child

print('**********Welcome to the program to check your age group**********')
age = int(input('Enter your age : '))

if age>18 and age<100:
    print('You are an adult!')

if age<=18 and age>10:
    print('You are a teen!')

if age<=10:
    print('You are a child!')

