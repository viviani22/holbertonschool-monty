#include "main.h"
/*
 *
 *
 */

void Push(stack_t **stack, unsigned int num_line, char *n)
{
	stack_t *pushed = NULL;
	int i;

	if (n == NULL)
	{
		printf("L%d: usage: push integer", num_line);
		exit(1);
	}
	for (i = 0; n[i] != '\0'; i++)
	{
		if (n[0] == '-' && i == 0)
			continue;
		if (isdigit(n[i]) == 0)
		{
			printf("L%d: usage: push integer", num_line);
			exit(1);
		}
	}
	pushed = malloc(sizeof(stack_t));
	if (pushed == NULL)
	{
		printf("Error: malloc failed\n");
		exit(1);
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
/*
 *
 *
 *
 */

