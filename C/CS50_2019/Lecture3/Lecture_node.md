\*this is a lecture note I wrote based on CS50 2019 lecture 3.   
\*all pictures used in this note are from CS50 course materials.   

# Algorithms and Efficiency
There could be several ways to perform a task. Each ways, strategies may differ in design. The design means the efficiency of algorithms, which can be measured by the time it takes to perform its task.   

<br>

## Big O notation
We can calculate or describe the efficiency of algorithm with the time or the number of operations it takes. We represent this as **Big O notation(*O*)**. This represents **running time**, which means how much time it takes for the algorithm to run, how many seconds it takes, how many steps it makes, whenever your unit of measure is. Note that this refers to them by **the number of steps they might take in the worst case** in the scenario.   
   
We write it in the form of "***O(…)***". We read Big O as "**on the order of …**". For example, when it says "*O*(*n*)", we can say, "on the order of *n*". Likewise, we say "on the order of log *n*" for "*O*(log *n*)". If an algorithms efficiency is indicated as "*O(n)*", we say, "the algorithm is on the order of of *n*".   
   
Big O refers to **approximation** of running time. So even if the number of steps is technically n/2 or log<sub>2</sub>n, we just throw away /2 or base 2, so that we call them as 'on the order of *n*' and 'on the order of log *n*', instead of 'on the order of *n*/2' and 'on the order of log<sub>2</sub>*n*'. This is because when the size of the problem n gets bigger and bigger, those kind of factors like divided 2 or base 2 gets so subtle, and finally those are so similar that we can just call them the same thing.   

<br><p align="center"><img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_01.png" width="30%" height="30%" title="Big O" alt="Big O"></img>&nbsp;&nbsp;<img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_02.png" width="30%" height="30%" title="Big O" alt="Big O"></img>&nbsp;&nbsp;<img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_03.png" width="30%" height="30%" title="Big O" alt="Big O"></img></p><br>

Let's get some typical examples of Big O notations. The image below represent representitive Big O notations and the corresponding algorithms. Detailed explanations is following below.   

<br><p align="center"><img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_04.png" width="70%" height="70%" title="Big O examples" alt="Big O examples"></img></p><br>

## Omega notation
By the way, not always does it take maximum times required to run. In some fortunate cases, we can finish tasks much faster. So, we can also indicate efficiency of algorithms by **the time it takes to run in the best case** in the scenario. It is a capital Greek omega, called **Omega notation(Ω)**. So it's the opposite of Big O, in that Big O is an upper bound on how much time an algorithm might take, while Omega notation is an lower bound.   
   
We write it in the from of "**Ω(…)**", as we did with big O. We read this as "**in omega of …**". For example, when it says "Ω(*1*)", we say "in omega of *1*". If it says "Ω(*n*)" or "Ω(log *n*)", of course, we read them as, "in omega of *n*", "in omega of log *n*". In linear search, for instance, the algorithm's efficiency is represented as "Ω(*1*)", so you can say, "the algorithm is in omega of *1*."

Typical examples of omega notations and the corresponding algorithms are below. Detailed explanations are below.   

<br><p align="center"><img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_05.png" width="70%" height="70%" title="Omega examples" alt="Omega examples"></img></p><br>

## Theta notation
It turns out that some algorithms can have value of big O and omega notation that are identical. When this is the case, you can represent this with capital Greek theta, called **theta notation(Θ)**. Note that only when big O value and omega value are identical can you use this theta notation.   
   
Below are some examples of theta notaitions and their corresponding algorithms that will be introduced below.   

<br><p align="center"><img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_06.png" width="70%" height="70%" title="Theta examples" alt="Theta examples"></img></p><br>


## Efficiency in real world
It would be best to both have good big O value and omega value, but actually that is quite hard to achieve. Scientists care more of big O, the worst case, than omega, the best case, if they have to choose the only one. But in real world, they usually tend to care much more about the average case.   
And sometimes, big O value and omega value could be the same. You might be able to think as a typical example of this, of situation where you count the number of elements of data. No matter in the best case or in the worst caes, you just have to look at all of them.   
   
Efficiency matters also depend on **whether the data set is sorted or not**. But sorting data also cost quite a lot. So there will be some trade-offs, balancing just jumping into searching, or the sum of sorting and searching.   

<br>
<br>

# Search Algorithms
Let's say that we're looking for the number '50' in the 7 lockers arranged in line. There may be two typical algorithms we may come up with - linear search and binary search, if we label them.   

<br><p align="center"><img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_07.png" width="70%" height="70%" title="search problem" alt="search problem"></img></p><br>

## Linear Search
Let's suppose that we're looking for the number '50' in the condition we said above, and we don't have any information or clues about these lockers.   
Then our best strategy, the algorithm might be this; to check every single locker left to right. If we go through all the data, we will finally reach '50', or get to know that there's none. We can represent this as pseudocode like the right.   
   
This kind of searching algorithm is called **linear search**, in that we search through line. This is useful when we don't have any information about the data set or it is not sorted.   

<br><p align="center"><img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_08.png" width="70%" height="70%" title="linear search pseudocode" alt="linear search pseudocode"></img></p><br>

## Binary Search
Let's suppose that we're looking for the number '50' in the condition we referred above, but we now know that the data set is '**sorted**'. Then what would be the best strategy to find the desired number?   
Well, we might look into the middle first, and if it's bigger than 50, search to the left, or if it's smaller, search to the right. We will finally reach the number 50 if we repeat this again and again, and there exists the nuber '50'. It would be like the image of the right if we write this in pseudocode.   
   
This kind of algorithm, which reminds us finding Mike Smith in the phonebook we discussed in week 0, is called **binary search**. Since "bi" means two, this term perfectly matches this algorithm in that it divides the data in half again and again. This is especially useful when the data set is sorted.   

<br><p align="center"><img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_09.png" width="70%" height="70%" title="binary search pseudocode" alt="binary search pseudocode"></img></p><br>

## Comparing Efficiency
The two algorithms to find the number '50' would differ in efficiency. Let's compare their efficiency using Big O notation.   
   
The number of lockes was 7, which means that the size of the problem, n, is also 7. In linear search, we need to check all lockers in the worst case, though we could be so fortunate that we can find '50' just at the first time. So the first algorithm, linear search, is on the order of *n*, that is, *O(n)*.   
In contrast, when it comes to binary search, it takes up to log*n* times to fully run even in the worst case. Since we divide the data in half again and again, we can always find '50' in 3 times(approximately log 7). So, the second algorithm, binary search, is on the order of log*n*, that is, *O*(log*n*).   
If we make the graph of these, we can compare each efficiency. As on the graph below, you can find that the binary search is way more efficient than the linear search.   

<br><p align="center"><img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_10.png" width="70%" height="70%" title="comparing efficiency" alt="comparing efficiency"></img></p><br>

On the other hand, you can also think of omega value of those algorithms to compare efficiency. In this case, both linear search and binary search is in omega of *1*(Ω(*1*)). This is because you can find in the first time if you get lucky, to specify, if 50 is in the first place in linear search, and if 50 is in the middle in binary search.   

<br>
<br>

# Sort Algorithms
To adopt more efficinet algorithms to search, you need to sort first. **Sorting algorithms** also require certain amounts of operations. In sort algorithm, the input would be an unsorted array and the output would be a sorted array. Let's see how we can sort a data set and compare their efficiency.   

<br><p align="center"><img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_11.png" width="70%" height="70%" title="sorting problem" alt="sorting problem"></img></p><br>

## Bubble Sort
The first algorithm you could come up with is something called, **bubble sort**. It means to switch items when the right one is bigger than the left one. If you repeat this again and again, you'll finally reach the sorted array of numbers. You can also write this sorting algorithm as a psuedocode.

<br><p align="center"><img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_12.png" width="70%" height="70%" title="bubble sort pseudocode" alt="bubble sort pseudocode"></img></p><br>

If there are n numbers to sort, you need to repeat it (n-1)x(n-1) times. Because it requires n-1 operations to go through the array once, and you need to go through the array n-1 times.   
   
To represent this as big O notation, it would be **O(n<sup>2</sup>)**. Although (n-1)x(n-1) is 'n<sup>2</sup> - 2n + 1', you would simplify this as 'n<sup>2</sup>' since big O notation refers to just an approximation. So bubble sort is **on the order of n<sup>2</sup>**.   

<br><p align="center"><img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_13.png" width="70%" height="70%" title="bubble sort running time" alt="bubble sort running time"></img></p><br>

On the other hand, since bubble sort doesn't check if the array is already sorted, there's no chance to reduce running time. That means that the omega value of it is also n<sup>2</sup>. So, bubble sort is **in omega of n<sup>2</sup> (Ω(n<sup>2</sup>))**.   
   
But, you can modify your pseudocode so that you can make omega value a little smaller. You can use `repeat until no swaps`, instead `repeat n-1 times`. It can reduce running time at some case, because there would be no swaps no later than n-1 times. Then the lower bound of running time should be n-1, reduced into n. So, the revised bubble sort algorithm is **in omega of n(Ω(n))**.

<br><p align="center"><img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_14.png" width="70%" height="70%" title="revised bubble sort" alt="revised bubble sort"></img></p><br>

## Selection Sort
You can also think of another algorithm, so-called **selection sort**. You can do this by finding the smallest item among unsorted items yet and placing it on the right next to the place of sorted items. If you keep doing this, you'll eventually get the sorted list of numbers. You can write it as  psuedocode. See the image below.   

<br><p align="center"><img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_15.png" width="70%" height="70%" title="selection sort pseudocode" alt="selection sort pseudocode"></img></p><br>

If there are n numbers to sort, you need to repeat this operation n + (n-1) + … + 1 times. This is because you need to conduct n-1 comparing operations to find the smallest item and 1 operation to swap, given that n is the number of unsorted items.   
   
To represent this as big O notation, it would be **O(n<sup>2</sup>)**. Although n + (n-1) + … + 1 is (n<sup>2</sup> + n)/2, you would simplify this as 'n<sup>2</sup>' since big O notation refers to just an approximation. So selection sort is **on the order of n<sup>2</sup>**.   

<br><p align="center"><img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_16.png" width="70%" height="70%" title="selection sort running time" alt="selection sort running time"></img></p><br>
   
Meanwhile, as to omega value of this sorting algorithm, this also has no possibility to save some operations, since it is just working on, no matter the array is already sorted or not. As a result, selection sort is also **in omega of n<sup>2</sup> (Ω(n<sup>2</sup>))**.   

<br>

## Merge Sort
Here is another groundbreaking algorithm for sorting, called **merge sort**. It uses recursion, which is detailed below. The key idea of this is to sort the left half, sort the right half and merge those two sorted halves. It will be writen like the code below, if you write it in the form of pseudocode.   

<br><p align="center"><img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_17.png" width="70%" height="70%" title="merge sort pseudocode" alt="merge sort pseudocode"></img></p><br>

If you were to sort the array of numbers "74526381", you can divide it into two halves, "7452" and "6381". Now you have two smaller arrays to sort. If you repeat this operation again and again, you will finially reach "12345678", in the end.   

<br><p align="center"><img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_18.png" width="70%" height="70%" title="merge sort example" alt="merge sort example"></img></p><br>

How efficient this algorithm is? Just look at the picutre below on the right side and think for a second. Horizontally, you need n, which is 8 in this case, operations in total to merge items, and vertically, you have to repeat this log base 2 of n, which is 4 in this case, times to fully sort the array. So you need n times log n operations, in this case, 8 times 4, which equals 32.   
   
To generalize, merge sort requires *n*log*n* times to run. That is, merge sort is **on the order of *n*log*n* (*O*(*n*log*n*))**.   
   
Meanwhile, it does the same thing always, even if the array is already sorted. So there's no room for reducing running time. Consequently, merge sort is also **in omega of *n*log*n* (*Ω*\(*n*log*n*\))**.   

<br>
<br>

# Recursion
**Recursion** is a key idea of algorithm. Recursion is a technique in programming, whereby you implement an algorithm that calls itself. With recursion, you can make your algorithm to iterate again and again. That means, you don't need loops to make it perform **iteration**, with much more succinct code.   

<br>

## Example 1 - Finding Mike Smith
See the codes below. It is the very pseudocode we discussed in week 0. In the line 8 and 11, there are "Go back to" commands, which stand for loops. In the code right below, it used "Search left/right half of book" commands, which stand for recursion instead. As you see, the lower code looks much simpler.   

<br><p align="center"><img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_19.png" width="45%" height="45%" title="recursion finding mike smith" alt="recursion finding mike smith"></img>&nbsp;&nbsp;<img src="/C/CS50_2019/Lecture3/images/Lecture 3 - Algorithm_20.png" width="45%" height="45%" title="recursion finding mike smith" alt="recursion finding mike smith"></img></p><br>

## Example 2 - Printing Stairs
Let's suppose that you're making a program that gets input as height and prints stairs of that height.   
   
You can program this stair-printing algorithm using loops, as we did before. The code would be like below.   
   
``` C
#include <stdio.h>

void draw(int h);

int main(void)
{
  int height;
  scanf("%d, &height);
  draw(height);
}
	
void draw(int h)
{
  for (int i = 1; i <= h; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      printf("#");
    }
    printf("\n");
  }
}
```
   
As you see, loops are used in the function draw. But instead, you can use recursion. Pyramid of size 4 is the sum of pyramid of size 3 and 4th row. Likewise, pyramid of size 3 is the sum of pyramid of size 2 and 3rd row. With this idea, you can code the same program with differnt algorithm using recursion, as follows.   

``` C
#include <stdio.h>
	
void draw(int h);

int main(void)
{
  int height;
  scanf("%d", &height);
  draw(height);
}

void draw(int h)
{
  if (h == 0)
  {
    return;
  }
  draw(h-1);
  
  for (int i = 0; i < h; i++)
  {
    printf("#");
  }
  printf("\n");
}
```

<br>
<br>

# C programming
During Lecture 3 Algorithms, you could learn some functions or grammars of C. See the summary at the below.   

<br>

## Arrays
You know what is an array, but you can initialize elements of an array more easily like below.   

``` C
int numbers[3];
numbers[0] = 20;     // ->  int numbers[3] = { 20, 19, 50 };
numbers[1] = 19;
numbers[2] = 50;
```

<br>

## strcmp
**`strcmp`** is a function that 'compares strings', which is declared in the header file `string.h`. You can use it like below.   

```
#include <stdio.h>
#include <string.h>

int main(void)
{
  char *s1 = "Hello";
  char *s2 = "Hello";
  printf("%d\n", strcmp(s1, s2));
  return 0;
}
```
	
`strcmp` returns `0` when the two strings are the same. Negative one or positive one is returend when those are different. In this case, since s1 and s2 are same, computer prints `0`, which means that they are same.   

<br>

## typedef
You can also make your own datatype by using **`typedef`**. It enables you to customize a data type. You can make your customized data type as follows.   

``` C
typedef struct
{
  data_type data_name;
  …
}
structure_name;
```

**`struct`** over there means **structure**, which refers to a container, inside of which you can put multiple other data types. That is, structure is a container for multiple data types.   
After delaring a new data type of yours, you can use it just like other data types like int, char, or bool. But note that you need to refer to data_name of structure. See the code below.   

```
typedef struct
{
  int age;
  char grade;
}
student;

int main(void)
{
  student student_1;
  student_1.age = 17;
  student_2. grade = 'A';
  // ...
}
```
