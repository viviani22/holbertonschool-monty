#include "monty.h"
/**
 * main - entry point
 * @argc: argument number
 * @argv: array of arguments
 * Return: 0 is successful
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_and_read(argv);
	return (0);
}
