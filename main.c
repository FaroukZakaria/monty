#include "monty.h"
/**
 * main - Main entry
 * @argc: n of args
 * @argv: arg vectors
 * Return: Always 0 or 1
 */
int main(int argc, char **argv)
{
	FILE *file;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}
	check(argv[1]);
	return (0);
}
