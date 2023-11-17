Welcome to the Monty Bytecode Interpreter. This interpreter was built in the C language and is compliant with ISO90, ISO99, & ISO11. It reads Monty bytecode files of any extension (preferably .m although it doesn't matter), and interprets the opcodes contained..
The interpeter runs in stack mode only
* push
 - Usage: push <int>
 - pushes an element on top of the stack
 - <int> must be an integer
*pop
 - Removes top element
*pall
 - prints all values inside the stack
*swap
 - swaps 2 elements insde the stack
*nop
 - does nothing.
*add
 - adds two top elements of the stack

opcodes preceded by '#' are considered comments.