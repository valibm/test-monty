#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: Pointer to the top of a stack.
 * @line: Number of the line.
 *
 * Retunr: Void.
 */

void pop(stack_t **stack, unsigned int line)
{
	stack_t *top;

	top = *stack;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}
