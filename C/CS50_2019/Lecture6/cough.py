#It's a human convention to make main function at the top,
#                        to make helper functions in the middle,
#                        and then to call main at the bottom.

def main():
    cough(3)

def cough(n):
    for i in range(n):
        print("cough")

main()