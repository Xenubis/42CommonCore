*This project has been created as part of the 42 curriculum by mmusquer*


# DESCRIPTION

This project is about sorting one or several string of character by transforming them into integer and sort them with a set of operations : (sa, sb, pa, pb, ra, rb, rra, rrb)
The purpose is to sort them with as little operations as possible.
The choice of the algorythm is free. For me i choosed at first quiksort but as i was working on it and trying to make it work, it appear to me that it wasn't possible so i switched to radix base 2.

## INSTRUCTIONS

My program works with his makefile.
Compile it with make and use the executable push_swap. You can either put one string, only arguments, several string or a mix of all that.

### RESSOURCES

My first ressources was this website given to me by a pear to understand the quicksort algorythm :
https://me.dt.in.th/page/Quicksort/
Then i used radix which was explain by another peer and also AI for more detail information.
I only used AI to start the project by asking a global structure of what i needed to do without any code. As i said earlier i also ask some theorical question when i don't understand a concept or when i need precise information on it. Of course i always try to check the informations i got somewhere else.

I used funcheck to check for my leak and complexity tester to test my number of operations :
https://github.com/froz42/funcheck
https://github.com/SimonCROS/push_swap_tester

some way to test it manually :

./push_swap 5 4 3 2 1
./push_swap 1 2 2 3
./push_swap 2147483647 -2147483648 0
./push_swap $(seq 1 100 | sort -R | tr '\n' ' ') | wc -l



 _ __ ___  _ __ ___  _   _ ___  __ _ _   _  ___ _ __ 
| '_ ` _ \| '_ ` _ \| | | / __|/ _` | | | |/ _ \ '__|
| | | | | | | | | | | |_| \__ \ (_| | |_| |  __/ |   
|_| |_| |_|_| |_| |_|\__,_|___/\__, |\__,_|\___|_|   
                                  | |                
                                  |_|                