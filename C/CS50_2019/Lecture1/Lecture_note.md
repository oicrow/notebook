\*this is a lecture note I wrote based on CS50 2019 lecture 1.   
\*all pictures used in this note are from CS50 course materials.   

# C
**C** is a very traditional, a very old language that's purely text-based. It is available in cloud, in the form of CS50 Sandbox.   

<br>

## Compile & Run
What we write to code, is called **source code**. Source code is written in programming languages like C, Python, Java, etc. They're English-like syntax humans can read and write. But what machines, or computers understand is not that source code. Computers only understand binary--zeros and ones. That bunch of zeros and ones that corresponds to source code in binary, is called **machine code**. And the algorithm, or program, that converts source code into machine code, is a **compiler**.   

<br><p align="center"><img src="/C/CS50_2019/Lecture1/images/Lecture 1 - C_01.png" width="70%" height="70%" title="compiler" alt="compiler"></img></p><br>

Say there's a source code that print "hello, world" in the terminal. The source code would look like the left page. English-like syntax. But if you compile it through compiler, the result would be like that right page. A machine code. That is what computers can understand and execute.   

<br><p align="center"><img src="/C/CS50_2019/Lecture1/images/Lecture 1 - C_02.png" width="45%" height="45%" title="source code" alt="source code"></img>&nbsp;->&nbsp;<img src="/C/CS50_2019/Lecture1/images/Lecture 1 - C_03.png" width="45%" height="45%" title="machine code" alt="machine code"></img></p><br>

How to execute machine code, totally without a button? We need to type commands in prompt in the terminal. **Dollar sign($)** means **prompt**. That's where we type commands for computers. The curser blinks so that it represents that you can type commands in prompt.   
   
Then how to compile with that prompt? You can use **clang**, if you will, but you can also use **make**, which is much simpler. While you need to type all linked file name to compile if needed with clang, you only need to type source code name with make, and that's it. That's a way more faster and easier.   

<br><p align="center"><img src="/C/CS50_2019/Lecture1/images/Lecture 1 - C_04.png" width="45%" height="45%" title="compile with clang" alt="compile with clang"></img>&nbsp;&nbsp;<img src="/C/CS50_2019/Lecture1/images/Lecture 1 - C_05.png" width="45%" height="45%" title="compile with make" alt="compile with make"></img></p><br>

|Command|Format|Meaning|   
|------|-----|-----|   
|clang| clang -o (desired machine code name, optional) (source code filename with extension) -l(linked file name, optional)| Compile the code|   
|make|make (source code filename without extension)| Compile the code|   
<br>

And then how to run? Just type `./` with your machine code name.<br><br>

|Command|Format|Meaning|   
|--|--|--|   
|./|./(machine code name)|Execute the file in the current directory|   
<br>

It is not exactly just what tells to run the program, but what tells to run the program in the current directory. So the period(.) literally means that it's right here, in the current folder, and the slash(/) with filename means to look in the directory and run the program in that file.   
   
There are some other commands operating in Linux, like cd, ls, mkdir, rm, rmdir. They're available in Linux, but they're also available in [CS50 Sandbox](https://sandbox.cs50.io/ "CS50 Sandbox link").   

<br><p align="center"><img src="/C/CS50_2019/Lecture1/images/Lecture 1 - C_06.png" width="70%" height="70%" title="commands of Linux" alt="commands of Linux"></img></p><br>

|Command|Format|Meaning|   
|--|--|--|   
|cd|cd (directory)|Move to that directory|   
|ls|ls|List what's in the current directory|   
|mkdir|mkdir (new directory name)|Make a directory in the current directory|   
|rm|rm (file name|Remove the file|   
|rmdir|rmdir (directory)|Remove an empty directory|   

<br>

## hello, world!
The code on the right is something that prints "hello, world" in the terminal. Let's understand how C works by interpreting this code.   
   
``` C
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```
   
In the line 1, `#include <stdio.h>` enables to use basic functions in C. In line 3, 4, and 6, we see the structure `int main(void){…}`. It makes our code start, and we write our codes between those two curly braces. And we should add **semicolon(;)** to every end of the line, or finish of thought.   

<br>

## Variable, Data type
To creat a variable, you need to first say data type, and then value name, assign values if needed, and finish with semicolon.   
   
	( data type ) ( value name ) ( assign value, optional );
   
Following is the list of some data types.   

<br>

|Code|Meaning|Values|   
|--|--|--|   
|bool|boolean||   
|char|charater|Integer number|   
|double||Floating-point number|   
|float||Floating-point number|   
|int|integer|Integer number|   
|long||Integer number|   
|*string*|||   

<br>

## List of commands or functions
|Command|Format|Meaning|CS50 specific|   
|--|--|--|:--:|   
|printf|printf("…")|Print what's between the quotes|x|   
|\n|\n|Move the curser to the next line|x|   
|string|string (value name)|Assign that value is string|o|   
|get_string|get_string("…")|Use the string argument as a prompt and get the string as an output|o|   

<br>

|Format specifiers|Format|   
|--|--|   
|%c|char|   
|%f|float, double|   
|%i|int|   
|%li|long|   
|%s|string|   

<br>

|Operator Type|Operator|Meaning|   
|--|--|--|   
|Assignment operator|=|Assign|   
|Arithmetic operators|+|Addition|   
||-|Substraction|   
||\*|Multiplication|   
||\/|Division|   
||\%|Remainder|   
||++|Increment|   
||--|Decrement|   
|Comparison operators|==|Equal to|   
|(Relational operators)|!=|Not Equal to|   
||>|Greater than|   
||<|Less than|   
||>=|Greater than or Equal to|   
||<=|Less than or Equal to|   
|Logical operators|!|Not|   
||&&|And|   
||\|\||Or|   
|Compound assignment operators|a += b|a = a + b|   
||a -= b|a = a - b|   
||a \*= b|a = a \* b|   
||a /= b|a = a / b|   
||a %= b|a = a % b|   

<br>

## if, while, for
How to use **if**   

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

How to use **while loop**   

	while ( condition )
	{
		...
	}

How to use **do…while loop**   

	do
	{
		...
	}
	while ( condition );

How to use **for loop**   

	for ( initializationStatement; condition; updateStatement )
	{
		...
	}

<br>
<br>

# Limitations of Computation
Computers do have their own limitations. Since they are also physically finite machine, there has to be a limitation on how much computers can store memory.   
   
<br>

## RAM
**RAM** is where all of the programs and files are stored while they're running, or open. Computer uses it to do multiple things at once and keep things in memory.   

<br><p align="center"><img src="/C/CS50_2019/Lecture1/images/Lecture 1 - C_08.png" width="70%" height="70%" title="RAM" alt="RAM"></img></p><br>

But It is, by nature of hardware, finite, which means that there is some fundamental limitation on what computers can do. That is some limits of computations.   

<br>

## Floating-point imprecision
Computer has limitations on how much it can count. And if it encounters this limit, like "I can count no higher than this value." or "I can store no more than this many numbers after decimal point.", it stores the closest possible match that it can.   
   
In the example code [`floats.c`](./float.c "float.c"), if we input 1 for x, and 10 for y, the result is not exactly 1/10. That's the error caused by the limitations of hardware.

<br>

## Integer overflow
With the same principle of floating-point imprecision, integers can only be so big. If number goes beyond that limitation, a phenomena called **integer overflow** occurs. That means, you don't have enough bits to sort of carry the one and remember the even bigger value, so to speak, so that you lose all the values.   

If you only have 3 bits and are counting, in binary, 111(7 in decimal) to 1000(8 in decimal), you're gonna overflow. That is, you will lose the carried one at the frontmost so the value you're actually storing is just zero.   

<br><p align="center"><img src="/C/CS50_2019/Lecture1/images/Lecture 1 - C_09.png" width="30%" height="30%" title="integer overflow" alt="integer overflow"></img>&nbsp;&nbsp;<img src="/C/CS50_2019/Lecture1/images/Lecture 1 - C_10.png" width="30%" height="30%" title="integer overflow" alt="integer overflow"></img>&nbsp;&nbsp;<img src="/C/CS50_2019/Lecture1/images/Lecture 1 - C_11.png" width="30%" height="30%" title="integer overflow" alt="integer overflow"></img></p><br>

**Y2K problem** is a very representitive example of this overflow. In the past, humans stored the year as 70 for 1970 or 99 for 1999 using only 2 digits. But in 2000, the two digits representing the year 00, was misinterpreted as 1900, which resulted in very expensive costs to fix this problem.   

<br><p align="center"><img src="/C/CS50_2019/Lecture1/images/Lecture 1 - C_12.png" width="45%" height="45%" title="Y2K integer overflow" alt="Y2K integer overflow"></img>&nbsp;&nbsp;<img src="/C/CS50_2019/Lecture1/images/Lecture 1 - C_13.png" width="45%" height="45%" title="Y2K integer overflow" alt="Y2K integer overflow"></img></p><br>
   
Another example is **Boeing 787**. The airplane model 787 had limited numbers it can count, and if it is turned on for about 248 days constantly, it overflows. 248 days are about 232 in 1/100 of a second. So if it's 248th day, the plane could lose all alternating current, electrical power and the power in the plane could cut off entirely. To solve this problem, they had rebooted the planes to reset the value.   

<br><p align="center"><img src="/C/CS50_2019/Lecture1/images/Lecture 1 - C_14.png" width="70%" height="70%" title="Boeing 787" alt="Boeing 787"></img></p><br>
