#include "monty.h"
/**
 * invalid - checks for invalid opcodes
 * @file: the file to be checked
 * Return: 0 if not failure and "-1" if invalid opcode
 */
int check(char *file)
{
	int nline, i, j = 0, neg = -1;
	char line[256];
	char *opc, *arg;
	char *opcs[] = {"push", NULL};
	FILE *fp;

	fp = fopen(file, "r");
	for (nline = 1; fgets(line, sizeof(line), fp) != NULL; nline++)
	{
		for (i = 0; line[i] == ' ';)
			i++;
		opc = &line[i];
		while (opcs[j] != NULL)
		{
			if (strncmp(opc, opcs[j], strlen(opcs[j])) == 0)
			{
				arg = opc + strlen(opcs[j]);
				if (*arg == '\0')
				{
					printf("L%d: usage: %s integer\n", nline, opcs[j]);
					fclose(fp);
					exit(EXIT_FAILURE);
				}
				else if (*arg == ' ' && *(arg + 1) != '\0' && *(arg + 1) != ' ')
				{
					arg++;
					if ((atoi(arg) == 0) && (*arg != '0'))
					{
						printf("L%d: usage: %s integer\n", nline, opcs[j]);
						fclose(fp);
						exit(EXIT_FAILURE);
					}
					continue;
				}
				else if (*arg == ' ' && *(arg + 1) == ' ')
				{
					while (isspace(*arg))
					{
						arg++;
						if (*arg == '\0')
						{
							printf("L%d: usage: %s integer\n", nline, opcs[j]);
							fclose(fp);
							exit(EXIT_FAILURE);
						}
					}
					if ((atoi(arg) == 0) && (*arg != '0'))
					{
						printf("L%d: usage: %s integer\n", nline, opcs[j]);
						fclose(fp);
						exit(EXIT_FAILURE);
					}
				}
				neg = 0;
			}
			if ((neg != 0) && (opcs[j + 1] == NULL))
			{
				printf("L%d: unknown instruction %s\n", nline, opcs[j]);
				fclose(fp);
				exit(EXIT_FAILURE);
			}
			j++;
		}
	}
	fclose(fp);
	return (0);
}
