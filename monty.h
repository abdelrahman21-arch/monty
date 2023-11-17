#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#define STACK 0
#define DELIMS " \n\t\a\b"



/*Global opcode variable*/
extern char **op_code;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/*stack.c*/
void free_stack(stack_t **stack_p);
int init_stack(stack_t **stack_p);
/*convert_to_tokens.c*/
char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);
/*run_m.c*/
void free_tokens(void);
int is_line_empty(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_m(FILE *script_fd);
unsigned int op_arr_len(void);
/*monty_function1.c*/
void monty_push(stack_t **stack_p, unsigned int line_number);
void monty_pall(stack_t **stack_p, unsigned int line_number);
void monty_pint(stack_t **stack_p, unsigned int line_number);
void monty_pop(stack_t **stack_p, unsigned int line_number);
void monty_swap(stack_t **stack_p, unsigned int line_number);
/*monty_functions2.c*/
void monty_nop(stack_t **stack_p, unsigned int line_number);
void monty_add(stack_t **stack_p, unsigned int line_number);
/*errors1.c*/
int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_operand_err(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
/*errors2.c*/
int short_stack_error(unsigned int line_number, char *op);
int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);
















#endif
