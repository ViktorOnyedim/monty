#include "monty.h"

int main(int argc, char **argv)
{
	FILE *file;
	/*char *lineptr = NULL;
	__attribute__((unused)) size_t len = 0;*/
	char line[1024];
	unsigned int line_number = 0;
	char *opcode, __attribute__((unused)) *arg;
	__attribute__((unused)) stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	/* Check if file can be opened or not */
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	/* Reading each line in the file */
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		opcode = strtok(line, "\n\t\r");

		/* Handle empty line or comments */
		if (opcode == NULL || opcode[0] == '#')
			continue;
		/* Extract next arg passed to the instruction
		 * Continue to look for next token in the string 
		 * after the last time it was called, using the delimiters
		 */
		if (strcmp(opcode, "push") == 0)
			push();
		else if (strcmp(opcode, "pall") == 0)
			pall();
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
		}
	}

	free_stack(stack);	

	fclose(file);

	return (0);
}
