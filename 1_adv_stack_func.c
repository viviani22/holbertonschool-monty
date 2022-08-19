#include "monty.h"
/**
 * Sub - func
 * @stack: struc
 * @num_line: ul
 */
void Sub(stack_t **stack, unsigned int num_line)
{
	int a, b, sub;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	sub = b - a;
	Pop(stack, num_line);
	(*stack)->n = sub;
}
/**
 * Div - func
 * @stack: struc
 * @num_line: ul
 */
void Div(stack_t **stack, unsigned int num_line)
{
	int a, b, div;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	if (a == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", num_line);
		exit(EXIT_FAILURE);
	}
	b = (*stack)->next->n;
	div = a / b;
	Pop(stack, num_line);
	(*stack)->n = div;
}
/**
 * Mul - func
 * @stack: struc
 * @num_line: ul
 */
void Mul(stack_t **stack, unsigned int num_line)
{
	int a, b, mul;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	mul = a * b;
	Pop(stack, num_line);
	(*stack)->n = mul;
}
/**
 * Mod - func
 * @stack: struc
 * @num_line: ul
 */
void Mod(stack_t **stack, unsigned int num_line)
{
	int a, b, mod;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	if (a == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", num_line);
		exit(EXIT_FAILURE);
	}
	b = (*stack)->next->n;
	mod = b % a;
	Pop(stack, num_line);
	(*stack)->n = mod;
}
