/**
 * file: monty_functions2.c
 * Author: sweilam
*/
#include "monty.h"
void monty_nop(stack_t **stack_p, unsigned int line_number);
void monty_add(stack_t **stack_p, unsigned int line_number);

/**
 * monty_add - Adds the top two values of a stack_t linked list.
 * @stack_p: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void monty_add(stack_t **stack_p, unsigned int line_number)
{
	if ((*stack_p)->next == NULL || (*stack_p)->next->next == NULL)
	{
		short_stack_error(line_number, "add");
		return;
	}

	(*stack_p)->next->next->n += (*stack_p)->next->n;
	monty_pop(stack_p, line_number);
}
/**
 * monty_nop - does nothing 
 * @stack_p: pointer to stack
 * @line_number: The current working line number 
*/
void monty_nop(stack_t **stack_p, unsigned int line_number)
{
    (void)stack_p;
    (void)line_number;
}
