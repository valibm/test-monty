#include "monty.h"

/**
 * main - Monty bite code files interpreter
 * @argc: Argument counter
 * @argv: Argument vector
 *
 * Return: Void
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *fd;
	char *file_n;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_n = argv[1];
	fd = fopen(file_n, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_n);
		exit(EXIT_FAILURE);
	}

	get_com(fd, &stack);
	free_stack(stack);
	fclose(fd);

	exit(EXIT_SUCCESS);
}

/**
 * get_com - Gets command from monty file.
 * @file: File to read to gets the command.
 * @stack: Linear data structure.
 *
 * Return: Void.
 */
void get_com(FILE *file, stack_t **stack)
{
	char *opcode, *token = NULL;
	size_t size = 0;
	int counter = 0;

	while (getline(&opcode, &size, file) != -1)
	{
		counter++;
		token = strtok(opcode, "\n\t\r ");
		if (token == NULL || *token == '#')
			continue;

		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t\r ");
			push(token, stack, counter);
		}
		else
			check_ops(token, stack, counter);
	}

	free(opcode);
}
