#include "monty.h"
/**
 * Pchar - func
 * @stack: ptr
 * @num_line: ul
 */
void Pchar(stack_t **stack, unsigned int num_line)
{
	int num;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", num_line);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->n;
	if (num < 0 || num > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", num_line);
		exit(EXIT_FAILURE);
	}
	putchar(num);
	putchar('\n');
}
/**
 * Pstr - func
 * @stack: ptr
 * @num_line: ul
 */
void Pstr(stack_t **stack, __attribute__((unused)) unsigned int num_line)
{
	stack_t *tmp;
	int num;

	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		num = (*stack)->n;
		if (num <= 0 || num > 127)
			break;
		putchar(num);
		tmp = tmp->next;
	}
	putchar('\n');
}
