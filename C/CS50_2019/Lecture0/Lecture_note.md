\*this is a lecture note I wrote based on CS50 2019 lecture 0.   
\*all pictures used in this note are from CS50 course materials.

# What is Computer Science?
It's a process of **solving problems**. Solving problem means: You've got some input and the goal is to get some output, the solution, to that particular problem. That process in between, called **algorithm** is where computer science comes in.   
<p align="center"><img src="/C/CS50_2019/Lecture0/images/Lecture 0 - Computational Thinking, Scratch_01.png" width="70%" height="70%" title="computer science" alt="computer science"></img></p>   

<br>

# Representation
So we now know that computer science is drawing output with input, but there left a question: how are we going to represent these inputs and outputs? How could it be possible for a computer to store not only numbers, but letters, images, videos, and sounds?    
   
We, humans, use **decimal**, which use ten(dec) digits, 0 to 9, to represent numbers. From the rightmost digit, we assign each digit to one's place, ten's place, hundred's place, and more on. And it turns out that these colums are just powers of 10: 10 to the 0 is 1, 10 to the 1 is 10, 10 to the 2 is 100. 123, for example, is 100 times 1, plus 10 times 2, plus 1 times 3.
   
<p align="center"><img src="/C/CS50_2019/Lecture0/images/Lecture 0 - Computational Thinking, Scratch_02.png" width="45%" height="45%" title="decimal digits" alt="decimal digits"></img>&nbsp;&nbsp;<img src="/C/CS50_2019/Lecture0/images/Lecture 0 - Computational Thinking, Scratch_03.png" width="45%" height="45%" title="decimal" alt="decimal"></img></p>   

   
## Binary
But computers have only two(bi) digits, 0 and 1, so called **binary**. Binary works exactly the same as  decimal, except that it uses 2 instead of 10. So columns in binary are powers of 2. If we kept going, it'd be one, two, four, eight, and sixteen instead of one, ten, hundred, thousand, and ten thousand.   
   
<p align="center"><img src="/C/CS50_2019/Lecture0/images/Lecture 0 - Computational Thinking, Scratch_04.png" width="45%" height="45%" title="binary digits" alt="binary digits"></img>&nbsp;&nbsp;<img src="/C/CS50_2019/Lecture0/images/Lecture 0 - Computational Thinking, Scratch_05.png" width="45%" height="45%" title="binary" alt="binary"></img></p>  
   
Theses binary digits are called **bits**. Bits is germane to computers, in that electricity is the only physical resouce into computers, that is to say, input. The core can either be plugged in or not plugged in, or 1 or 0, ture or false, on or off, and well that actually maps quite nicely to the idea of binary.   
   
To represent much larger numbers in computer, we can use more number of digits, now bits at a time, maybe 8 bits. This is called **byte**, which is just a term describing 8 bits.   
For instance, to represent dicimal number 50 in a byte, it'd be 00110010, since 50 equals 32 plus 16 plus 2 . Likewise, dicimal number 25 is 00011001 in binary.

   
<p align="center"><img src="/C/CS50_2019/Lecture0/images/Lecture 0 - Computational Thinking, Scratch_06.png" width="70%" height="70%" title="bits and byte" alt="bits and byte"></img></p>  
   
A **transistor** inside a computer is what stores and represents information. It is just a tiny little switch in a computer, and a computer has millions or billions of transistors. By literally turning on and off transistors according to desired information, computers physically represent information and store values.   

   
## Representing Further
Computers can do more than just representing and storing numbers. We all send text messages, images videos and emails, compose documents, and so forth everyday. To enable computers to represent other things, we need to all agree how we're going to go about representing them.   
