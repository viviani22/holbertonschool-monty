#include "monty.h"
/**
 * Pall - op function
 * @stack: structure
 * @num_line: ul
 */
void Pall(stack_t **stack, __attribute__((unused)) unsigned int num_line)
{
	stack_t *actual = *stack;

	if (*stack == NULL)
		return;
	while (actual != NULL)
	{
		printf("%d\n", actual->n);
		actual = actual->next;
	}
}
/**
 * Pint - op function
 * @stack: structure
 * @num_line: ul
 */
void Pint(stack_t **stack, unsigned int num_line)
{
	int operator;

	if (*stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", num_line);
		exit(EXIT_FAILURE);
	}
	operator = (*stack)->n;
	printf("%d\n", operator);
}
/**
 * Pop - op function
 * @stack: structure
 * @num_line: ul
 */
void Pop(stack_t **stack, unsigned int num_line)
{
	stack_t *poped;

	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", num_line);
		exit(EXIT_FAILURE);
	}
	poped = (*stack)->next;
	free(*stack);
	*stack = poped;
}
/**
 * Swap - op function
 * @stack: structure
 * @num_line: ul
 */
void Swap(stack_t **stack, unsigned int num_line)
{
	int temp1, temp2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't pop an empty stack", num_line);
		exit(EXIT_FAILURE);
	}
	temp1 = (*stack)->n;
	temp2 = (*stack)->next->n;
	(*stack)->n = temp2;
	(*stack)->next->n = temp1;
}
/**
 * Add - op function
 * @stack: structure
 * @num_line: ul
 */
void Add(stack_t **stack, unsigned int num_line)
{
	int a, b, sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	sum = a + b;
	Pop(stack, num_line);
	(*stack)->n = sum;
}
