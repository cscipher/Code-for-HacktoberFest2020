word = input('Enter a word : ')
rev_word = word[::-1]
if rev_word==word:
    print('The word is a plaindrome!')
else:
    print('The word is not a palindrome!')