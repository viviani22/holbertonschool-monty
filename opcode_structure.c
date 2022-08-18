#include "monty.h"
/**
 * opcode_function - called from main
 * @token: string
 * @top: structure
 * @num_line: ul
 * Return: int
 */
int opcode_function(char *token, stack_t **top, unsigned int num_line)
{
	int i;

	instruction_t opcodes[] = {
		{"pall", Pall},
		{"pint", Pint},
		{"pop", Pop},
		{"swap", Swap},
		{"nop", Nop},
		{"add", Add},
		{NULL, NULL}
	};
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(token, opcodes[i].opcode) == 0)
		{
			(opcodes[i].f)(top, num_line);
			return (EXIT_SUCCESS);
		}

	}
	fprintf(stderr, "L%u: unknown instruction %s\n", num_line, token);
	exit(EXIT_FAILURE);
}
/**
 * free_stack - func for testing
 * @top: pointer to pointer
 */
void free_stack(stack_t **top)
{
	stack_t *tmp;

	if (*top == NULL)
		return;
	while (*top != NULL)
	{
		tmp = *top;
		*top = (*top)->next;
		free(tmp);
	}
}
