/**
 * File: run_m.c
 * Auth: sweilam
*/
#include "monty.h"
#include <string.h>
void free_tokens(void);
int is_line_empty(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_m(FILE *script_fd);
unsigned int op_arr_len(void);

/**
 * free_tokens - Frees the global op_toks array of strings.
 */

void free_tokens(void)
{
size_t i;
if (op_code == NULL)
{
    return;
}
for (i = 0; op_code[i];i++) 
         free(op_code[i]);
free(op_code);
}
/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line(char *line, char *delims)
{
    int i,j;
    for (i = 0; line[i]; i++)
    {
        for (j = 0; delims[j]; j++)
        {
            if (line[i] == delims[j])
                         break;
        }
        if (delims[j] == '\0')
        return (0);
    }
    return (1);
}
/**
 * token_arr_len - Gets the length of current op_code.
 *
 * Return: Length of current op_code (as int).
 */
unsigned int op_arr_len(void)
{
	unsigned int ops_len = 0;

	while (op_code[ops_len])
		ops_len++;
	return (ops_len);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{NULL, NULL}
	};
    int i;
    for (i = 0; op_funcs[i].opcode; i++)
    {
        if(strcmp(opcode, op_funcs[i].opcode) == 0)
        {
            return(op_funcs[i].f);
        }
    }
    return (NULL);
}
/**
 * run_m - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int run_m(FILE *script_fd)
{
    stack_t *stack = NULL;
    char *line = NULL;
    size_t line_len =0, exit_status = EXIT_SUCCESS;
    unsigned int line_number =0, prev_op_len = 0;
    void (*op_func)(stack_t**,  unsigned int);   

    if (init_stack(&stack) == EXIT_FAILURE)
         return (EXIT_FAILURE);
    while (getline(&line, &line_len, script_fd) != -1)
    {
      line_number++;
      op_code = strtow(line, DELIMS);
      if (op_code == NULL)
      {
        if(is_empty_line(line, DELIMS))
        continue;
        free_stack(&stack);
        return (malloc_error());
      }
      else if (op_code[0][0] == '#')
      {
        free_tokens();
        continue;
      }
      op_func = get_op_func(op_code[0]);
      if (op_func == NULL)
      {
        free_stack(&stack);
        exit_status = unknown_operand_err(op_code[0], line_number);
        free_tokens();
        break;
      }
    prev_op_len = op_arr_len();
	op_func(&stack, line_number);
    if(op_arr_len() != prev_op_len )
    {
        if((op_code != NULL) && (op_code[prev_op_len] != NULL))
        {
            exit_status = atoi(op_code[prev_op_len]);
        }
        else
        exit_status = EXIT_FAILURE;
        free_tokens();
        break;
    }
    
    free_tokens();
    }
    free_stack(&stack);
    if (line != NULL && *line == 0) 
    {
        free(line);
        return(malloc_error());
    }
free(line);
return(exit_status);

}
    
