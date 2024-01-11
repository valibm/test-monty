#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @opcode: Pointer to a string.
 * @top: Pointer to the top of a stack.
 * @line: Line number.
 *
 * Return: Void.
 */
void push(char *opcode, stack_t **top, unsigned int line)
{
	stack_t *stack;

	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
		return;
	}
	if (isnum(opcode) == 1 && opcode != NULL)
	{
		stack->n = atoi(opcode);
		stack->next = *top;
		stack->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	if (*top != NULL)
		(*top)->prev = stack;
	*top = stack;
}

/**
 * pall_func - prints all the values on the stack
 * @sstack: linear data structure
 * @line: unused attribute
 *
 * Return: void
 */
void pall_func(stack_t **sstack, unsigned int __attribute__((unused)) line)
{
	int index = 0;
	stack_t *current;

	current = *sstack;

	while (current)
	{
		if (current != NULL)
		printf("%d\n", current->n);
		index++;
		current = current->next;
	}
}
