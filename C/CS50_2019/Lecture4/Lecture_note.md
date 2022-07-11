\*this is a lecture note I wrote based on CS50 2019 lecture 4.   
\*all pictures used in this note are from CS50 course materials.   

# Hexadecimal
We talked in week 0 about decimal and binary. Binary is a counting system based on 2. It turns out that there are other base system where you don't just use powers of 10(decimal) or 2(binary), you use other base systems entirely as well. One of them is **hexadecimal**, which is based on 16(hex).

<br><p align="center"><img src="/C/CS50_2019/Lecture4/images/Lecture 4 - Memory_01.png" width="70%" height="70%" title="hexadecimal digits" alt="hexadecimal digits"></img></p><br>

# Principle - How does it work?
Hexadecimal refers to a system that counts based on 16. In the world of hexadecimal, you can count using single digits not only 0 through 9, but also 10, 11, 12, 13, 14, and 15, with each represented by A, B, C, D, E, F. While using these individual alphabetical letters, can you effectively count 0 through 15.   
   
As it's mentioned in week 0 that you count based on 2 in binary, you count 0 through 15, as F, using powers of 16. In binary, each column is powers of 2. If you reach the limit you can count with one digit, you carry the one to the next place, just like decimal numbers. It works exactly in the same way binary and decimal do.   
But be careful not to read 10 in hexadecimal as 'ten'. 'Ten' is 10 in decimal, a decimal number. You can just say 'one, zero'. Likewise, you can say 'two, zero' for 20 in hexadecimal.   
   
In bianry, you can represent up to 255 with 8 bits, which means binary digit. In decimal, you can represent 255 with 3 digits. Meanwhile, you can represent 255 in decimal, with only 2 digits 'FF'.   

<br><p align="center"><img src="/C/CS50_2019/Lecture4/images/Lecture 4 - Memory_02.png" width="32%" height="32%" title="255 in binary" alt="255 in binary"></img>&nbsp;&nbsp;<img src="/C/CS50_2019/Lecture4/images/Lecture 4 - Memory_03.png" width="32%" height="32%" title="255 in decimal" alt="255 in decimal"></img>&nbsp;&nbsp;<img src="/C/CS50_2019/Lecture4/images/Lecture 4 - Memory_04.png" width="32%" height="32%" title="255 in hexadecimal" alt="255 in hexadecimal"></img></p><br>

## Applications
 To recall from week 0, RGB is one way to represent colors, using some amount of red, some amount of green, some amount of blue. It is hexadecimal that is used to indicate that amounts of red, green, and blue. It's a human convention to describe the amounts of red, green, blue in a color, in terns of hexadecimal digits.
 Each colors are represented in two hexadecimal digits, meaning that minimum amount is 0, represented by '00', and maximum amount is 255, represented by 'FF'. So if it says all '00's, it represents black, and if it all says 'FF's. it represents white.

 It is also useful when it comes to computer's memory in that you can address the memory with it. That means you assign a number, a unique identifier, to every byte so that you can just talk about where things are in memory.
 And it's a human convention, to use hexadecimal to address the memory. So quite often do computers show us numbers not in decimal or not in binary, but in hexadecimal. It turns out this is convenient for reasons related to computing.
 But it seems quite ambiguous. It may be confusing to tell which type of number it is, decimal or hexadecimal or something else together. To avoid this ambiguity, humans decided to prefix every digit with '0x', if you are using hexadecimal. '0x' means nothing mathematically. It's just an arbirtrary sign, declared by human convention. With 0x, you can disambiguate it from something like decimal itself.

<br>
<br>

# Address of Memory - Pointer

 When you store any values in a computer, it takes certain amounts of bytes. As a CPU consists of billions of bytes, it's super natural that those values have their own locations. So humans found that it's convenient to address the memory of variables. As it says above, humans decided to represent this address in hexadecimal numbers, and prefix it with '0x' notation to clarify that it's a hexadecimal number, not anything else.
 It would be like the image on the right side if it was visualized arbitrarily, though it's literally an arbitrary example of address. Actually each address is represented by more digits, since there are way more bytes inside a computer.



| Address of/Go to operators
 If you declare an integer variable called 'n' and store a value '50' in it, that variable 'n' takes up 4 bytes of memory somewhere in the CPU so that it exist at a specific address of memory. That is,  a variable n and the value therein 50 is technically at address 0x12345678(hexadecimal 12345678).

 You can access that memory using the address of operator(&). It's an operator that calls the address of a following variable.

	address of operator	&
		
	Example	
	…+1	int n = 50;
	…+2	printf("%p", &n);
		
	Result:	0x12345678

 As you might see on the example code above, when you print an address, you need to specify that its format is an address, using '%p'. Letter 'p' over there represents a pointer, which is described below.

 Meanwhile, there's another operator which is the opposite of the address of operater. It's called go to operator(*). Though asterisk represents multiplying in most cases, in specific contexts like below, it works as go to operator, which goes to that following address and recalls the values therein.

	go to operator	*
	
	Example	
	…+1	int n = 50;
	…+2	printf("%i", *&n);
		
	Result:	50
	
 As you see, go to operator invalidates the address of operator, or undoes the effect of the address of operator, so it prints out the value in the variable n, located in the address of it. When you print using go to operator, you need to specify its format, as always, but which format to choose is up to you. You might guess or just arbitrarily decide.

 To sum up, 'the address of operator(&)' means 'what's the address?' and 'go to operator(*)' means 'go to that address.'



| pointer
 As it's spoiled a little bit above, an address of a value is called a pointer. So it turns out that as soon as you ask the computer for the address of some value, you are getting a pointer to that value.

 It turns out that you can actually store addresses in variables themselves. You can declare a variable whose data type is a pointer, as follows.

	(data type of other variable) *(variable pointer name)

	Example
	…+1	int i = 50;	// declare a variable that you're going to get the address of
	…+2	int *p = &n;	// store the address of n in the pointer p
	
 So in this example code above, the variable p is a pointer to variable n. In other words, p is a variable that is going to contain a pointer to an integer, which is n, a.k.a the address of an interger n.
 You used 'int *', since the type of the variable you are getting the address of is interger. If you were calling the address of char, it would be 'char *', insteat of 'int *'.

 But actually, we or other programmers are not very interested in what the address of a variable literally exactly is. They don't really care much about where a variable is exactly located. Instead, what really matters is that a pointer points to a specific variable. So humans use arrows to indicate that it's a pointer to a specific variable, instead of writing exact address of it. It's a common abstraction of pointers in computer's memory.

 Additionally, pointers usually takes up 64 bits, or 8 bytes, which is equivalent of a long, in most moder Macs and PCs. It's also a human convention these days, but it doesn't have to be always this way.

 Pointer is amazingly powerful, as it enables various powerful data structures. Using pointers, you can start to construct very sophisticated data structures, which are the underpinnings of fancy algorithms.

<br>
<br>

# String

 To recall from Week 1, a string is an array of characters. But technically strictly speaking, a string is a pointer to the first character of an array of characters. Let's see how string exists.


| String is a Pointer
 Suppose that you declared a variable s and store a string "EMMA" in it.

 From the point of view from Week 1, since a string is an array of characters, the string consists of 5 chars―'E', 'M', 'M', 'A', '\0'. As it was mentioned previously, '\0' is null terminating character, a notation that demonstrastes the end of an array, which literally consists of 8 zero bits.

 But it turns out that it was a kind of white lie. A string doesn't exist. Data type string was just a training wheel that CS50 specifically provided for the sake of demonstration. The reality is, a variable s that seemed to contain a string is just a pointer to the first char 'E'. See the picture on the right side.

 In this point of view, the view of reality, how can we declare a string then? It's never different from what we did a moment ago. Since a string is stored in the form of a pointer to the first character, you can store a string by storing a pointer to the first char.  Note that we said that 'char *' means a data type of a pointer to a char, a chracter. See the code below.

	char *string_name = "string_contents";

 Then how do computers get a full string from a pointer to the first charater? What about know where the string ends? It turns out that every char of string is deliberately 1 byte away, since string is defined by characters back-to-back-to-back. This enables computer to reach following chars and figure out where the string ends by looking for null terminating character as with a loop.

 When printing a string, you need to format code '%s'. It automatically prints out chars until it reaches null terminating character. If you use a '%c' instead, it only prints one first character of the string, which is the very value of the address stored.

 To take a quick peep how CS50 library enabled string, it uses typedef, which is mentioned in last week. Just as we made out custom data type called person last week, you can create a data type, string, using this command. See the code on the right. It's acutally a part of cs50.h.
 To recall, typedef works in the form of 'typedef data_type custom_name;'. In the example of person we created last week, data type was structure, codes in the curly braces were just included in that structure, and person was the custom name of your new data type. 
 The code on the right works exactly the same way 'person' did. The custom data type was char *(pointer to a char), and its name was string.


| Pointer Arithmetic
  You can also directly deal with this pointer. That's called pointer arithmetic. If you literally add 1 to a string, strictly a pointer to the first char, it points to the second char of the string.

<br>
<br>

# C programming

 During Lecture 4 Memory, you could learn some functions or grammars of C. See the summary at the below.



| malloc
 malloc is a function that allocates memory. It's used like below.

	varible_to_allocate_memory = malloc(the_number_of_data);

 It returns the address of the first byte of required amount of memory.



| free
 free is a function that frees the allocated memory by malloc. The opposite of malloc, so to speak. This is necessary because when you keep using malloc but don't freeing them, you'll be running out of memory.

	free(variable);



| valgrind
 valgrind is a command that checks if there is unfreed allocated memory, or memory leaking. It's a universal debug tool, not a CS50 specific one.

	Valgrind ./file_name



| strcpy
 strcpy is a function that 'copies strings', which is declared in the header file 'string.h'. It's used like below.

	strcpy(string1, string2);

 When this is run, you copy into the string1, the contents of string2. Below are one example.

	1	#include <stdio.h>
	2	#include <string.h>
	3	
	4	int main(void)
	5	{
	6	    char *s = "Hello";
	7	    char *t = malloc(strlen(s) + 1);
	8	    strcpy(t, s)
	9	    return 0;
	10	}



| strlen
 strlen is a function that computes 'the length of a string', which is declared in the header file 'string.h'. It's used like below. It returns the length of a string.

	strlen(string);
