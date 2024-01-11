#include "monty.h"

/**
 * check_ops - Checks the opcode in the line
 * @opcode: Requested function
 * @stack: Pointer to the top of the stack
 * @line: Line number
 *
 * Return: Function pointer or EXIT_FAILURE if it fails
 */
void check_ops(char *opcode, stack_t **stack, unsigned int line)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"pall", pall},
		{"pint",  pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"nop", nop_func},
		{NULL, NULL}
	};

	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			opcodes[i].f(stack, line);
			break;
		}
		i++;
	}

	if (opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
		exit(EXIT_FAILURE);
	}
}


/**
 * free_stack - Frees a stack.
 * @stack: Pointer to the top of the stack.
 * Return: Void.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

/**
 * isnum - Checks a string for numbers.
 * @opcode: String to be checked.
 * Return: 1 if true, 0 otherwise.
 */

int isnum(char *opcode)
{
	unsigned int i = 0;

	if (opcode == NULL)
		return (0);

	while (opcode[i])
	{
		if (opcode[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(opcode[i]))
			return (0);
		i++;
	}
	return (1);
}
