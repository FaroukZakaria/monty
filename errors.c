#include "main.h"
/**
 * invalid - checks for invalid opcodes
 * @file: the file to be checked
 * Return: "value" if not failure
 */
int check(char *file)
{
	int nline, i, value, j = 0;
	char line[256];
	char *opc, *arg, *result;
	char **opcs == {"push", NULL};
	FILE *fp;

	fp = fopen(file, "r");
	for (nline = 1; fgets(line, sizeof(line), file) != NULL; nline++)
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
					value = atoi(arg);
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
					value = atoi(arg);
					continue;
					}
				}
			}
			j++;
		}
	}
	fclose(fp);
	return (value);
}
