#include "monty.h"

/**
 * push_func - pushes an element to the stack
 * @opcode: pointer to the string
 * @top_stack: linear data structure
 * @line: number of the line of the command
 *
 * Return: void
 */
void push_func(char *opcode, stack_t **top_stack, unsigned int line)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
		return;
	}
	if (isnum(opcode) == 1 && opcode != NULL)
	{
		new->n = atoi(opcode);
		new->next = *top_stack;
		new->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	if (*top_stack != NULL)
		(*top_stack)->prev = new;
	*top_stack = new;
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
