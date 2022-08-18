#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int opcode_function(char *token, stack_t **top, unsigned int num_line);
void Push(stack_t **stack, unsigned int num_line, char *n);
void Pall(stack_t **stack, unsigned int num_line);
void Pint(stack_t **stack, unsigned int num_line);
void Pop(stack_t **stack, unsigned int num_line);
void Swap(stack_t **stack, unsigned int num_line);
void Add(stack_t **stack, unsigned int num_line);
void Nop(stack_t **stack, unsigned int num_line);
void open_and_read(char **argv);
int found_number(char *token);
int found_comment(char *token, int counter);
void free_stack(stack_t **top);
int number;
#endif
