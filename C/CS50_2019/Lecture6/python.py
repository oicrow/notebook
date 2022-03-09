# Python is one of the programming languages
# While C needs to be complied and executed, python doesn't need those processes.
# Instead, you need to run the program 'python', and pass the name of your source code(.py) to python.
# Then, python will do all works


# printing hello #

# #include <stdio.h>
#
# int main(void)
# {
#     printf("hello, world!\n");
# }

print("hello, world!")


# get input from user #

# char *answer = malloc(8);
# printf("What's your name?\n");
# scanf("%s", answer);
# printf("hello, %s\n", answer);

answer = input("What's your name?\n")
print("hello, " + answer)
print("hello,", answer)
print(f"hello, {answer}")   # format string


# variable declaration #

# int i = 0;
# int x = 1;
# int y = 2;

i = 0
x = 1
y = 2


# incrementing/decrementing #

# i = i + 1;
# i += 1;
# i++;

i = i = 1
i += 1
# i++ (X)


# if, elif, else #

# if (x < y)
# {
#     printf("x is less than y\n");
# }
# else if (x > y)
# {
#     printf("x is greater than y\n");
# }
# else
# {
#     printf("x is equal to y\n");
# }

if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")


# while #

# while (true)
# {
#     printf("hello world\n");
# }

#while True:                 # infinite loop
#    print("hello world")

# int i = 3;
# while (i > 0)
# {
#     printf("cough\n");
#     i--;
# }

i = 3
while i > 0:
    print("cough")
    i -= 1


# for #

# for (int i = 0; i < 3; i++)
# {
#     printf("cough\n");
# }

for i in [0, 1, 2]:
    print("cough")

for i in range(3):
    print("cough")


# Data types in python

# bool (boolean)
True
False

# float
3.1
-0.2393

# int (integer)
2
-10

# str (string)
"string"
'this is also a string'

# range: sequence of numbers
range(3)

# list: sequence of mutable values
x = [0, 1, 2]

# tuple: sequence of immutable values
y = (0, 1, 2)

# dict: collection of key/value pairs
dictionary = {0:'a', 1:'b'}

# set: collection of unqiue values
set_1 = set([0, 1, 2])


# same code written in C and python
# C: slower to write but faster to execute
# python: faster to write but slower to execute