# github username : Titan1911

# Welcome to the program which identifies whether a string is a palindrome or not
print('**********Welcome to the program which identifies whether a string is a palindrome or not**********')
word = input('Enter a word : ')
rev_word = word[::-1]
if rev_word==word:
    print('The word is a plaindrome!')
else:
    print('The word is not a palindrome!')