# Regular Expressions
#   : finds patterns in users input

# .     any character
# .*    0 or more characters
# .+    1 or more characters
# ?     optional
# ^     start of input
# $     end of input


# agree.py

import re #regualr expresion

s = input("Do you agree?\n")

if re.search("^y(es)?$", s, re.IGNORECASE):
    print("Agreed.")
elif re.search("^n(o)?$", s, re.IGNORECASE):
    print("Not agreed.")

