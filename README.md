The Monty Language

The Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.
A. Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account.
B. The Monty program

    Usage: monty file
            where file is the path to the file containing Monty byte code.

Compilation

$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
$

Run

$ ./monty monty_file.m
5
7
1
2

Interpreter Synopsis

$ ./monty [montyfilename]
$

    If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE

    If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE.
            where <file> is the name of the file.

    If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE

        where is the line number where the instruction appears.

        Line numbers always start at 1

    The monty program runs the bytecodes line by line and stop if either:

        it executed properly every line of the file

        it finds an error in the file

        an error occured

    If you can’t malloc anymore, the program prints the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.

C. Opcodes

    pint

    The opcode pint prints the value at the top of the stack, followed by a new line.

Usage: pint

    If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

    Example:

    micahondiwa@ubuntu:~/monty$ cat bytecodes/06.m
        push 1
	    pint
	        push 2
		    pint
		        push 3
			    pint
			        micahondiwa@ubuntu:~/monty$ ./monty bytecodes/06.m
				    1
				        2
					    3
					        micahondiwa@ubuntu:~/monty$

    2. pop

    The opcode pop removes the top element of the stack.

Usage: pop

    If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE

    Example:

micahondiwa@ubuntu:~/monty$ cat bytecodes/07.m
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
micahondiwa@ubuntu:~/monty$ ./monty bytecodes/07.m
3
2
1
2
1
1
micahondiwa@ubuntu:~/monty$

    swap

    The opcode swap swaps the top two elements of the stack.

Usage: swap

    If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE -Example:

micahondiwa@ubuntu:~/monty$ cat bytecodes/09.m
push 1
push 2
push 3
pall
swap
pall
micahondiwa@ubuntu:~/monty$ ./monty bytecodes/09.m
3
2
1
2
3
1
micahondiwa@ubuntu:~/monty$

    add

    The opcode add adds the top two elements of the stack.

Usage: add

    If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE -The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

        The top element of the stack contains the result

        The stack is one element shorter

    Example:

    micahondiwa@ubuntu:~/monty$ cat bytecodes/12.m
        push 1
	    push 2
	        push 3
		    pall
		        add
			    pall micahondiwa@ubuntu:~/monty$ ./monty bytecodes/12.m
			        3
				    2
				        1
					    5
					        1
						    micahondiwa@ubuntu:~/monty$

    nop

    The opcode nop doesn’t do anything!

Usage: nop

    sub

    The opcode sub subtracts the top element of the stack from the second top element of the stack.

Usage: sub

    If the stack contains less than two elements, print the error message L<line_number>: can't sub, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

    The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

        The top element of the stack contains the result

        The stack is one element shorter

    Example:

micahondiwa@ubuntu:~/monty$ cat bytecodes/19.m
push 1
push 2
push 10
push 3
sub
pall
micahondiwa@ubuntu:~/monty$ ./monty bytecodes/19.m
7
2
1

    div

    The opcode div divides the second top element of the stack by the top element of the stack.

Usage: div

    If the stack contains less than two elements, print the error message L<line_number>: can't div, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

    The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

        The top element of the stack contains the result

        The stack is one element shorter

    If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE

    mul

    The opcode ```mul`` multiplies the second top element of the stack with the top element of the stack.

Usage: mul

    If the stack contains less than two elements, print the error message L<line_number>: can't mul, stack too short, followed by a new line, and exit with the status EXIT_FAILURE.

    The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

        The top element of the stack contains the result

        The stack is one element shorter

    mod

    The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack.

Usage: mod

    If the stack contains less than two elements, print the error message L<line_number>: can't mod, stack too short, followed by a new line, and exit with the status EXIT_FAILURE.

    The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

        The top element of the stack contains the result

        The stack is one element shorter

    If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE

    pchar

    The opcode pchar prints the char at the top of the stack, followed by a new line.

    Usage: pchar

    The integer stored at the top of the stack is treated as the ascii value of the character to be printed

    If the value is not in the ascii table (man ascii) print the error message L<line_number>: can't pchar, value out of range, followed by a new line, and exit with the status EXIT_FAILURE

    If the stack is empty, print the error message L<line_number>: can't pchar, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

    Example:

    micahondiwa@ubuntu:~/monty$ cat bytecodes/28.m
        push 72
	    pchar
	        micahondiwa@ubuntu:~/monty$ ./monty bytecodes/28.m
		    H
		        micahondiwa@ubuntu:~/monty$

    pstr

    The opcode pstr prints the string starting at the top of the stack, followed by a new line.

Usage: pstr

    The integer stored in each element of the stack is treated as the ascii value of the character to be printed

    The string stops when either:

        the stack is over

        the value of the element is 0

        the value of the element is not in the ascii table

    If the stack is empty, print only a new line

    Example:

micahondiwa@ubuntu:~/monty$ cat bytecodes/31.m
push 1
push 2
push 3
push 4
push 0
push 110
push 0
push 108
push 111
push 111
push 104
push 99
push 83
pstr
micahondiwa@ubuntu:~/monty$ ./monty bytecodes/31.m
School
micahondiwa@ubuntu:~/monty$

    rotl

    The opcode rotl rotates the stack to the top.

Usage: rotl

    The top element of the stack becomes the last one, and the second top element of the stack becomes the first one rotl never fails

    Example:

micahondiwa@ubuntu:~/monty$ cat bytecodes/35.m
push 1
push 2
push 3
push 4
push 5
push 6
push 7
push 8
push 9
push 0
pall
rotl
pall
micahondiwa@ubuntu:~/monty$ ./monty bytecodes/35.m
0
9
8
7
6
5
4
3
2
1
9
8
7
6
5
4
3
2
1
0
micahondiwa@ubuntu:~/monty$

    rotr

    The opcode rotr rotates the stack to the bottom.

Usage: rotr

    The last element of the stack becomes the top element of the stack rotr never fails

    stack, queue

The stack opcode

    The opcode stack sets the format of the data to a stack (LIFO). This is the default behavior of the program.

    Usage: ```stack``

The queue opcode

    The opcode queue sets the format of the data to a queue (FIFO).

    Usage: queue

When switching mode:

    The top of the stack becomes the front of the queue

    The front of the queue becomes the top of the stack

-Example:

micahondiwa@ubuntu:~/monty$ cat bytecodes/47.m
queue
push 1
push 2
push 3
pall
stack
push 4
push 5
push 6
pall
add
pall
queue
push 11111
add
pall
micahondiwa@ubuntu:~/monty$ ./monty bytecodes/47.m
1
2
3
6
5
4
1
2
3
11
4
1
2
3
15
1
2
3
11111
micahondiwa@ubuntu:~/monty$