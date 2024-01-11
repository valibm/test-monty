#include "monty.h"

/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: Pointer to the top of a stack.
 * @line: Number of the line.
 * Return: Void.
 */

void pint(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	tmp = *stack;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", tmp->n);
}
