#include "main.h"
/**
 * invalid - checks for invalid opcodes
 * @file: the file to be checked
 * Return: 0 if invalid, 1 if otherwise
 */
int invalid(char *file)
{
	int nline;
	char line[256];

	fopen(file, "r");
	for (nline = 1; fgets(line, sizeof(line), file) != NULL; nline++)
	{
