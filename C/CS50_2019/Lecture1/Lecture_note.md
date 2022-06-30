# C

 **C** is a very traditional, a very old language that's purely text-based. It is available in cloud, in the form of CS50 Sandbox.
 
## | Compile & Run
 What we write to code, is called **source code**. Source code is written in programming languages like C, Python, Java, etc. They're English-like syntax humans can read and write. But what machines, or computers understand is not that source code. Computers only understand binary--zeros and ones. That bunch of zeros and ones that corresponds to source code in binary, is called **machine code**. And the algorithm, or program, that converts source code into machine code, is a **compiler**.
<img src="/C/CS50_2019/Lecture0/images/Lecture 0 - Computational Thinking, Scratch_01.png" title="compiler" alt="compiler"></img><br/>
 Say there's a source code that print "hello, world" in the terminal. The source code would look like the left page. English-like syntax. But if you compile it through compiler, the result would be like that right page. A machine code. That is what computers can understand and execute.


 How to execute machine code, totally without a button? We need to type commands in prompt in the terminal. Dollar sign($) means prompt. That's where we type commands for computers. The curser blinks so that it represents that you can type commands in prompt.


 How to compile with that prompt? You can use clang, if you will, but you can also use make, which is much simpler. While you need to type all linked file name to compile if needed with clang, you only need to type source code name with make, and that's it. That's a way more faster and easier.

Command	Format	Meaning
clang	 clang -o (desired machine code name, optional) (source code filename with extension) -l(linked file name, optional)	 Compile the code
make	 make (source code filename without extension)	 Compile the code


 And then how to run? Simple. Just type ./ with your machine code name.

Command	Format	Meaning
./	./(machine code name)	 Execute the file in the current directory

 It is not exactly just what tells to run the program, but what tells to run the program in the current directory. So the period(.) literally means that it's right here, in the current folder, and the slash(/) with filename means to look in the directory and run the program in that file.


 There are some other commands operating in Linux, like cd, ls, mkdir, rm, rmdir. They're available in Linux, but they're also available in CS50 Sandbox.

Command	Format	Meaning
cd	cd (directory)	Move to that directory
ls	ls	List what's in the current directory
mkdir	mkdir (new directory name)	Make a directory in the current directory
rm	rm (file name)	Remove the file
rmdir	rmdir (directory)	Remove an empty directory



| hello, world!
 The code on the right is something that prints "hello, world" in the terminal. Let's understand how C works by interpreting this code.

1	#include <stdio.h>
2	
3	int main(void)
4	{
5	    printf("hello, world\n");
6	}

 In the line 1, #include <stdio.h> enables to use basic functions in C. In line 3, 4, and 6, we see the structure int main(void){…}. It makes our code start, and we write our codes between those two curly braces. And we should add semicolon(;) to every end of the line, or finish of thought.



| Variable, Data type
 To creat a variable, you need to first say data type, and then value name, assign values if needed, and finish with semicolon.

	( data type ) ( value name ) ( assign value, optional );

 Following is the list of some data types.

Code	Meaning	Values
bool	boolean	
char	charater	Integer number
double		Floating-point number
float		Floating-point number
int	integer	Integer number
long		Integer number
string		



| List of commands or functions

Command	Format	Meaning	CS50 specific
printf	printf("…")	 Print what's between the quotes	x
\n	\n	 Move the curser to the next line	x
string	string (value name)	 Assign that value is string	o
get_string	get_string("…")	 Use the string argument as a prompt and get the string as an output	o

Format specifiers	Format
%c	char
%f	float, double
%i	int
%li	long
%s	String

Operator Type	Operator	Meaning
Assignment operator	=	Assign
Arithmetic operators	+	Addition
	- 	Substraction
	• 	Multiplication
	/	Division
	%	Remainder
	++	Increment
	--	Decrement
Comparison operators	==	Equal to
(Relational operators)	!=	Not Equal to
	>	Greater than
	<	Less than
	>=	Greater than or Equal to
	<=	Less than or Equal to
Logical operators	!	Not
	&&	And
	||	Or
Compound assignment operators	a += b	a = a + b
	a -= b	a = a - b
	a *= b	a = a * b
	a /= b	a = a / b
	a %= b	a = a % b



| if, while, for

How to use if?
if ( condition )
{
        ...
}
else if ( condition )
{
        ...
}

...

else
{
        ...
}

How to use while loop?
while ( condition )
{
        ...
}

How to use do…while loop?
do
{
        ...
}
while ( condition );

How to use for loop?
for ( initializationStatement; condition; updateStatement )
{
        ...
}
![image](https://user-images.githubusercontent.com/77658038/176583293-554d2552-a421-42a4-a267-519da5c5a49e.png)
