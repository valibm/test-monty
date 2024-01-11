#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int);
} instruction_t;

void get_com(FILE *file, stack_t **stack);
void get_func(char *opcode, stack_t **cp_stack, unsigned int line);
void mem_free(stack_t *head);
void push_func(char *opcode, stack_t **top_stack, unsigned int line);
void pall_func(stack_t **sstack, unsigned int __attribute__((unused)) line);
int _isnumber(char *opcode);
void pop_func(stack_t **stack, unsigned int line);
void swap_func(stack_t **stack, unsigned int line);
void add_func(stack_t **stack, unsigned int line);
void nop_func(stack_t **stack, unsigned int line);
void pint_func(stack_t **sstack, unsigned int __attribute((unused)) line);

#endif