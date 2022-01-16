# __Push Swap - Sorting a stack__

## 1. Goal

Develop a program that display on the standard input the smallest number of *push_swap* actions to sort (from smallest to biggest) a stack of integer received. 

## 2. Rules of the games

- The program can use 2 stacks (will cal *a* the input one and *b* the "support" one).
- Stack *a* can contain a random amount of unique integers (positive and/or negative) 
- Stack *b* starts empty.
- The program will receive the stack *a* as an input formatted as a list of integers where the first integer is at the top. 
- The followign are the only actions available (or *push_swap* actions):
  - *sa* : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
  - *sb* : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
  - *ss* : sa and sb at the same time.
  - *pa* : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
  - *pb* : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  - *ra* : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
  - *rb* : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
  - *rr* : ra and rb at the same time.
  - *rra* : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
  - *rrb* : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
  - *rrr* : rra and rrb at the same time.

## 3. Implementation

To develop the program I went through the following steps
1. __Chose the structure of my stack.__ It could have been either an array of integer or a linked list (as described [here in Wikipedia](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))); I opted for the second option.
2. __Implemented functions to execute the *push_swap* actions.__
3. __Develop algorithm to sort "small stacks" (no more than 5 numbers).__
For this step I first developed an algorithm to sort a stack of 3 number. To do so, I considered the limited combination of 3 unsorted integers (5 cases) and for each of them identified the shortest list of *push_swap* actions to sort them. For stack with more than 3 elements, I implemented an algorithm that (1) pushes elements to stack *b* until stack *a* is size 3 and then (2) insert the element from stack *b* back to sorted stack *a* in their correct position.
4. __Develop alogrithm for "big" stacks.__
After studying several possible algorithm, I chose to develop a radix sort algorithm since it was efficient enough and easy to implement. [Here is a short video](https://www.youtube.com/watch?v=nu4gDuFabIM) that visualize the logic behind the algorithm. 
This algorithm only works for positive-only arrays, therefore I used the position of each number in the final sorted arrays instead of the original inputs. For example, instead of -234 -670 10 5 -3, I considered 1 0 4 3 2, since the following is the sorted list of number -670 -234 -3 5 10.
Moreover, since the available stacks where only two, I implemented the same logic explained in the video using the binary representation of the numbers.
