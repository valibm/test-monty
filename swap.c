#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the top of a stack.
 * @line: Number of the line.
 *
 * Return: Void.
 */

void swap(stack_t **stack, unsigned int line)
{
	stack_t *tmp;
	stack_t *node;

	tmp = *stack;
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	node = tmp->next;
	tmp->next = node->next;
	node->next = *stack;
	tmp->prev = node;
	node->prev = NULL;
	*stack = node;
}
