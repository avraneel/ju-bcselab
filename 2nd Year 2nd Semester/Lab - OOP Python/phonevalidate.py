import re
number = input('Enter your phone number = ')
print(re.search('\d{10}', number))