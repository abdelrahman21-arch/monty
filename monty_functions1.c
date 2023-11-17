/**
 * file: monty_functions1.c
 * Author: Sweilam
*/
#include "monty.h"
void monty_push(stack_t **stack_p, unsigned int line_number);
void monty_pall(stack_t **stack_p, unsigned int line_number);
void monty_pint(stack_t **stack_p, unsigned int line_number);
void monty_pop(stack_t **stack_p, unsigned int line_number);
void monty_swap(stack_t **stack_p, unsigned int line_number);

/**
 * monty_push - Pushes a value to a stack_t linked list.
 * @stack_p: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_push(stack_t **stack_p, unsigned int line_number)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
	   malloc_error();
		return;
	}

	if (op_code[1] == NULL)
	{
		no_int_error(line_number);
		return;
	}

	for (i = 0; op_code[1][i]; i++)
	{
		if (op_code[1][i] == '-' && i == 0)
			continue;
		if (op_code[1][i] < '0' || op_code[1][i] > '9')
		{
			no_int_error(line_number);
			return;
		}
	}
	new->n = atoi(op_code[1]);
    tmp = (*stack_p)->next;
	new->prev = *stack_p;
	new->next = tmp;
	if (tmp)
	  tmp->prev = new;
	(*stack_p)->next = new;
}
/**
 * monty_pall - Prints the values of a stack_t linked list.
 * @stack_p: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pall(stack_t **stack_p, unsigned int line_number)
{
	stack_t *tmp = (*stack_p)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}
/**
 * monty_pint - Prints the top value of a stack_t linked list.
 * @stack_p: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pint(stack_t **stack_p, unsigned int line_number)
{
	if ((*stack_p)->next == NULL)
	{
		pint_error(line_number);
		return;
	}

	printf("%d\n", (*stack_p)->next->n);
}


/**
 * monty_pop - Removes the top value element of a stack_t linked list.
 * @stack_p: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pop(stack_t **stack_p, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack_p)->next == NULL)
	{
		pop_error(line_number);
		return;
	}

	next = (*stack_p)->next->next;
	free((*stack_p)->next);
	if (next)
		next->prev = *stack_p;
	(*stack_p)->next = next;
}

/**
 * monty_swap - Swaps the top two value elements of a stack_t linked list.
 * @stack_p: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_swap(stack_t **stack_p, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack_p)->next == NULL || (*stack_p)->next->next == NULL)
	{
		short_stack_error(line_number, "swap");
		return;
	}

	tmp = (*stack_p)->next->next;
	(*stack_p)->next->next = tmp->next;
	(*stack_p)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack_p)->next;
	tmp->next = (*stack_p)->next;
	tmp->prev = *stack_p;
	(*stack_p)->next = tmp;
}
