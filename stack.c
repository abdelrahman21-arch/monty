/**
 * File: stack.c
 * Auth: Sweilam
*/
#include "monty_header.h"
#include <string.h>
void free_stack(stack_t **stack_p);
int init_stack(stack_t **stack_p);

/**
 * free_stack - Frees a stack_t stack.
 * @stack_p: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack_p)
{
    stack_t *tmp = *stack_p;
    while(*stack_p != NULL)
    {
        tmp = *stack_p;
        (*stack_p) = (*stack_p)->next;
        free(tmp);
    }

}
/**
 * init_stack - Initializes a stack_t stack with beginning
 *              stack and ending queue nodes.
 * @stack_p: A pointer to an unitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
int init_stack(stack_t **stack_p) 
{
stack_t *s;
s = malloc(sizeof(stack_t));
if (s == NULL)
   return (malloc_error());
s->n = STACK;
s->prev = NULL;
s->next = NULL;
*stack_p = s;
return (EXIT_SUCCESS);
}

