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
``		{
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
void Pall(stack_t **stack, unsigned int __attibute__((unused))num_line)
{
	stack_t *actual = *stack;

	if (stack == NULL || *stack == NULL)
		return;
	while (actual != NULL)
	{
		printf("%d\n", actual->n);
		actual = actual->next;
	}
}
/*
 *
 *
 */
void Pint(stack_t **stack, unsigned int num_line)
{
	int operator;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", num_line);
		exit(1);
	}
	operator = (*stack)->n;
	printf("%d\n", operator);
}
/*
 *
 *
 */
void Pop(stack_t **stack, unsigned int num_line)
{
	stack_t *poped;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", num_line);
		exit(1);
	}
	poped = (*stack)->next;
	free(*stack);
	*stack = poped;
}
/*
 *
 *
 *
 */
void Swap(stack_t **stack, unsigned int num_line)
{
	int temp1, temp2;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't pop an empty stack", num_line);
		exit(1);
	}
	temp1 = (*stack)->n;
	temp2 = (*stack)->next->n;
	(*stack)->n = temp2;
	(*stack)->next->n = temp1;
}
/*
 *
 *
 *
 */
void Add(stack_t **stack, unsigned int num_line)
{
	int a, b, sum;

	if (stack_length(stack) < 2)
	{
		printf("L%d: can't add, stack too short\n", num_line);
		exit(1);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	sum = a + b;
	Pop(stack, num_line);
	(*stack)->n = sum;
}

/*
 *
 *
 *
 */
void Nop(stack_t **stack, unsigned int num_line)
{
	(void)stack;
	(void)num_line;
}
