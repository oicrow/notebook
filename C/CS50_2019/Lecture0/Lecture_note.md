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
   
**ASCII**, the American Standard Code for Information Interchange, is that all-agreed promise about representing characters. It was made a few decades ago and the whole world agreed with it when using computers to represent characters.   
But ASCII is American-centric as it seems literally from its name. It is indeed biased onto American English. And it uses 8 bits, which means that it can represent only up to 256 characters, but 128 in reality, since one frontmost bit is not really represeneting characters. Of course, it is not big enough for characters at all.   
   
<p align="center"><img src="/C/CS50_2019/Lecture0/images/Lecture 0 - Computational Thinking, Scratch_07.png" width="70%" height="70%" title="ASCII" alt="ASCII"></img></p>  
   
We need a way more patterns of code to represent more characters like accented characters, other languages, or emojis. So another promise, like a superset of ASCII, called **unicode** uses more bits. It uses 8 or 16 or 24 or even 32 bits so that it has much more possible patterns of zeros and ones.   
An emoji tears of joy(😂), for instance, is represented by unicode as 128524 in decimal, 11111011000000010 in binary. It also indicates that there's that much of the characters and emojis awaiting us.   
   
<p align="center"><img src="/C/CS50_2019/Lecture0/images/Lecture 0 - Computational Thinking, Scratch_08.png" width="70%" height="70%" title="unicode" alt="unicode"></img></p>  
   
<br>
   
But computers represent more than just numbers and characters. They represent images, videos, or gifs. Even emojis themselves are images. And it's evident to many, that videos and gifs are sequences of images flying past our eyes so quickly. One image after another appears on the screen really quickly, making illusions of movement. And that image is composed of lots of little dots, or pixels.   
As red, green, and blue are the primary colors of the light, computer can represent any color in rainbow by combining some amount of red, green and blue. So those dots contain their color in the system of **RGB**. It's a set of numbers representing how much red, green, blue to use to represent some dots on the screen, respectively.   
   
<p align="center"><img src="/C/CS50_2019/Lecture0/images/Lecture 0 - Computational Thinking, Scratch_09.png" width="45%" height="45%" title="RGB" alt="RBG"></img>&nbsp;&nbsp;<img src="/C/CS50_2019/Lecture0/images/Lecture 0 - Computational Thinking, Scratch_10.png" width="45%" height="45%" title="RGB combined" alt="RGB combined"></img></p>  
   
<br>
Videos contain not only visual contents but also sound tracks. Computers can represent sounds using the note, the duration, and the volume.   
<br>
<br>

# Algorithm
Said computer science is the process of solving problems, by drawing output from input. That way of getting from inputs to outputs, the process in between, is **algorithm**. It is step-by-step instructions for solving some problem.   
   
## Effective Algorithm
If you consider a situation of finding Mike Smith from a book of a thousand pages, you might think of several algorithms for it.   
   
The first one is, to turn the page one by one, until you find Mike Smith. That would take up to 1000 turns to find him.   
   
The second is, to turn the pair of pages at once until you find him. And to prevent skipping him, we might say, if you hit the Sn section, back up one or so pages. This is as twice as faster than the first one, but still takes up to 500 turns. That's a while, just to look someone up.   
   
The third one is, to go to the middle, and go to the middle of one half side which Mike Smith would be in, and repeat again and again. If the book is 1024 pages long, we can perfectly find Mike Smith or conclude that he is not here, only for up to 10 steps.   
   
The first and second algorithms are 'not wrong', but they're also 'not effective' at the same time. Time it takes with them increases in direct proportional to the size of the problem. If the pages of the book doubles, it takes double. But the third one, on the contrary, is much more effective, since the time increases in proportion to just a logarithmic function. As the graph of a logarithmic function we know, the time to solve increases so slowly that it is really time-effective for huge sets of data. The difference is evident in the image on the right.   
   
<p align="center"><img src="/C/CS50_2019/Lecture0/images/Lecture 0 - Computational Thinking, Scratch_11.png" width="70%" height="70%" title="complexity graph" alt="complexity graph"></img></p>    
   
