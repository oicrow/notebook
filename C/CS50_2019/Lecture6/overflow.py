from time import sleep

i = 1
while True:
    print(i)
    sleep(.1)
    i *= 2

# increases unlimitedly
# (python doesn't have upper limit of int)
# (float has imprecise though)