import csv

name = input("Name: ")
number = input("Number: ")

#file = open("Lecture6\phonebook.csv", "a")
#writer = csv.writer(file)
#writer.writerow((name, number))

#file.close()

with open("Lecture6\phonebook.csv", "a") as file:
    writer = csv.writer(file)
    writer.writerow((name, number))