#GitHub Username: 013himanshu

def reverse_words_order_and_swap_cases(sentence):
    word = sentence.split()
    rev = ""
    for i in word:
        letter = list(i)
        case = ""
        for ind in range(0, len(letter)):
            if letter[ind].islower():
                case = case + letter[ind].upper()
            else:
                case = case + letter[ind].lower()

        rev = case + " " + rev

    return rev

sentence = str(input())
print(reverse_words_order_and_swap_cases(sentence))
