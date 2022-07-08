\*this is a lecture note I wrote based on CS50 2019 lecture 2.   
\*all pictures used in this note are from CS50 course materials.   

# Compiling
After writing the source code, we compiled it through command by typing `clang` or `make`. **Compiling** means the process of converting source code, which we write, into machine code, which computers understand. We called the whole process compiling, but actually, it takes four steps to successfully compile a code.   
   
1. Preprocessing
2. Compiling
3. Assembling
4. Linking

<br>

## 1. Preprocessing
Quite often does a source code start with `#include <stdio.h>`. Extension `.h` means a **header file**, which was often already written by someone else some time ago. So if you include a specific header file, you make functions, data types or other things in that header file available to use in your source code.   
   
On the first step of compiling, **preprocessing**, compiler finds functions or other things from header files which are used in the source code, and converts these `#include <.h>`s into those very parts of header files including them. That means, by declaring them ahead, it enables your source code to be compiled.   

<br><p align="center"><img src="/C/CS50_2019/Lecture2/images/Lecture 2 - Arrays_01.png" width="45%" height="45%" title="source code" alt="source code"></img>&nbsp;->&nbsp;<img src="/C/CS50_2019/Lecture2/images/Lecture 2 - Arrays_02.png" width="45%" height="45%" title="preprocessed code" alt="preprocessed code"></img></p><br>

## 2. Compiling
Though all compiling process is called compiling, the second step of compiling is also called **compiling**. In compiling, a compiler automatically converts a preprocessed source code into an **assembly code**.   
   
An **assembly code** is a kind of computer language, which is much more easier for a computer to understand. As compiling means conversion from source code to machine code, an assembly code is the very intermediate step between them. It was an alternative language a few decades ago, and it's a little bit more closer to what the CPU can actually understand. It is a set of instructions for very low-level operations.   

<br><p align="center"><img src="/C/CS50_2019/Lecture2/images/Lecture 2 - Arrays_02.png" width="45%" height="45%" title="preprocessed code" alt="preprocessed code"></img>&nbsp;->&nbsp;<img src="/C/CS50_2019/Lecture2/images/Lecture 2 - Arrays_03.png" width="45%" height="45%" title="compiled code" alt="compiled code"></img></p><br>

## 3. Assembling
The third step of compiling is the process called **assembling**. In assembling, it converts from the assembly code into binary. That is, the whole bunch of zeros and ones. It is done by clang built-in functionality.   

<br><p align="center"><img src="/C/CS50_2019/Lecture2/images/Lecture 2 - Arrays_03.png" width="45%" height="45%" title="compiled code" alt="compiled code"></img>&nbsp;->&nbsp;<img src="/C/CS50_2019/Lecture2/images/Lecture 2 - Arrays_04.png" width="45%" height="45%" title="assembly code" alt="assembly code"></img></p><br>

## 4. Linking
Although you pre-declared functions or date types from header files to use them in your source code, a computer doesn't really know what to do actually, since you literally declared their names but didn't describe their contents. To tell a computer how to do those functions, you need that header file. That forth process of compiling is called **linking**.   
   
In linking, after assembling your source code, you preprocess, compile, and assemble the header files included on the top of your source code. So in the example of the right side, besides the bunch of zeros and ones representing `hello.c`, a compiler also converts `cs50.c` and `stdio.c` into binary. And then, a compiler finally merge those three bunch of binary into one executable file—a machine code.

<br><p align="center"><img src="/C/CS50_2019/Lecture2/images/Lecture 2 - Arrays_05.png" width="45%" height="45%" title="assembly codes" alt="assembly codes"></img>&nbsp;->&nbsp;<img src="/C/CS50_2019/Lecture2/images/Lecture 2 - Arrays_06.png" width="45%" height="45%" title="linked code" alt="linked code"></img></p><br>

<br>

# Debugging
## The origin of bug and debug
The word debug originated from a notebook kept by Grace Hopper, who is a famous computer scientist. She was working on the Mark 2 system with some colleagues. At some the Mark 2 was discovered as having literally a bug inside of it, which was causing a program. Grace Hopper actually recorded this on the note, as "the first actual case of bug being found".   
Even though other people had used the expression 'bug' before to refer to mistakes, or problems in systems, this is really sort of the lore, in computer science.
 
<br><p align="center"><img src="/C/CS50_2019/Lecture2/images/Lecture 2 - Arrays_07.png" width="70%" height="70%" title="Hopper's note" alt="Hopper's note"></img></p><br>

## Syntax Error Debugging with CS50 debug helper

 'help50' is a CS50 specific helping tools, which helps interpreting error messages so that you can debug when you're running a command. You can use this command as 'help50 make (file name)'. Then computer wiil make your file, and if there's any error message, help50 will interpret it for you instead.

 CS50 also provies other commands like 'check50', which the professor use to grade and automatically feedback on code, and 'style50', which helps you to write prettier code.

 CS50 also provides  CS50 IDE, which includes the commands above. IDE is an acronym of integrated Development Environment. There are also a lot of IDEs, like Eclipse and Visual studio. They all provide useful debugging tools.



| Logical Error Debugging with Break point
 If you click to the left of the line numbers in IDE, including CS50 IDE, it puts a red dot, called breakpoint, which represents a sign to stop here. It is a very common feature of IDE, which tells the computer in advance not to run just as usual, and to stop there instead, and allow the human to step through the code, step by step. This is available in almost all IDEs around the world.

 In CS50 IDE, you can use this feature by command as: debug50 ./(file name)

 If you use a breakpoint, you can see a debugger window. You can step over, one line at a time. While doing this, you can check in the debugger window what's going on in your computer step by step.

 Another debugging way for logical error is to use 'printf'. You may use this function to explicitly visualize what's going on in your computer, so that you can find out where a problem resides.



| Additional Human mechanism for debugging
 If you have a syntax error, you can use help50, if you're using CS50 IDE, or read the error message you got. On the other hand, if you have a logical error, you can use breakpoint debugger. But there's another debugging, which is universal.

 It's called rubber duck debugging. It's a term of art in computer science. It means that you can have one of little things on your desk and start talking to explain to it what your code is doing, walking through it line by line verbally until you hopefully self-induce what's wrong with your code.

 Another thing is just steping back. You can take a walk, sleep, grab a coffee, for a moment to refresh, and then start working on it again.

<br>
<br>

# Array

 In the quality of software, you can refer to not only correctness, but also design and style. As we said, style of code refers to pretty code, which includes legibility and readability. And the design of software means efficiency of code. You can save a lot of resources like time, money, memory, CPU cycles with well-designed program. And the one of the first step toward good design, is an array.



| Memory, RAM
 Any types of data take up specific amount of memory. bool, char, int, float, long, and double all take up the fixed number of bytes. That taken memory is located in RAM, random access memory, which is one of the pieces of hard drive.
 The black chip on RAM has some number of bytes that can be allocated. The bytes are so small that the tiny chip represents billions of bytes. This chip is where information is store while running a software.
 So, if you stored a char, you allocate 1 byte of the RAM, and 4 bytes if you stored an integer, somewhere in RAM.


| Array
 An array is a list of value that can be all the same type in a variable of the same name. You can use array like below.

    (data type of array) (array name)[(the number of values)];

 And, `(arrayname)[(number)]` represents the number-th entry of the array. Of course, this starts counting from zero. But the number of values counts from one. Because it needs null terminator `/0` to represent the end of the array.



| string using array
In the point of array, string can be viewed as the array of char, character. So you can make string as follow.

    char* (string name) = "(string)";
