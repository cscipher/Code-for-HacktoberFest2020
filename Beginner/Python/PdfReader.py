#Github Username: gurleen3
#Importing the library which can say/ speak
'''Uncomment the code to manually let the speaker speak something you want to'''
#speaker = pyttsx3.init()
#speaker.say('Hey there! I can talk')
#speaker.runAndWait()
import pyttsx3

#importing the library whch can read pdf
import PyPDF2

# Make sure the pdf you want to read is in the same folder as the code, 
# Change code.pdf with name of the pdf.
book = open('code.pdf', 'rb')
pdfReader = PyPDF2.PdfFileReader(book)

# Calculating the number of pages.
pages = pdfReader.numPages
speaker = pyttsx3.init()

# For loop to read through the range and extract text and speak it.
for num in range(15, pages):
    page = pdfReader.getPage(num)
    text = page.extractText()
    speaker.say(text)
    speaker.runAndWait()