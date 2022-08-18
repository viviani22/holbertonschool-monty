#include "monty.h"
/**
 * Push - op function
 * @stack: structure
 * @num_line: ul
 * @n: string
 */
void Push(stack_t **stack, unsigned int num_line, char *n)
{
	stack_t *pushed = NULL;
	int i;

	if (n == NULL)
	{
		fprintf("L%d: usage: push integer\n", num_line);
		exit(EXIT_FAILURE);
	}
	for (i = 0; n[i] != '\0'; i++)
	{
		if (n[0] == '-' && i == 0)
			continue;
		if (isdigit(n[i]) == 0)
		{
			printf("L%d: usage: push integer\n", num_line);
			exit(EXIT_FAILURE);
		}
	}
	pushed = malloc(sizeof(stack_t));
	if (pushed == NULL)
	{
		fprintf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	pushed->n = atoi(n);
	pushed->prev = NULL;
	pushed->next = NULL;
	if (*stack != NULL)
	{
		pushed->next = *stack;
		(*stack)->prev = pushed;
	}
	*stack = pushed;
}
/**
 * Nop - op function
 * @stack: structure
 * @num_line: ul
 */
void Nop(stack_t **stack, unsigned int num_line)
{
	(void)stack;
	(void)num_line;
}
