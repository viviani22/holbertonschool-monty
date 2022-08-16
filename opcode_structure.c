#include "monty.h"
/*
 *
 *
 *
 *
 *
 */
int opcode_structure(char *opcode, stack_t **stack, unsigned int num_line)
{
	int i;
	instruction_t opcodes[] = {
		{"pall", Pall},
		{"pint", Pint},
		{"push", Push},
		{"pop", Pop},
		{"swap", Swap},
		{"nop", Nop},
		{"add", Add},
		{NULL, NULL}
	};
	for (i = 0; opcodes[i].opcode !=NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			(opcodes[i].f)(stack, num_line);
			exit(0);
		}
	}
	printf("L%d: unknown instruction %s\n", num_line, opcode);
	exit(1);
}
