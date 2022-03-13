s = input("Do you agree?\n")

#if s == "Y" or s == "y":
if s.lower() in ["y", "yes"]:
    print("Agreed.")
#elif s == "N" or s == "n":
elif s.lower() in ["n", "no"]:
    print("Not agreed.")

