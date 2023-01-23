#include "monty.h"
/*#include "opcode.h"*/

int main(int argc, char **argv)
{
	
	FILE *file;
	char line[1024];
	char *opcode;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

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
		opcode = strtok(line, " \n\t\r");

		/* Handle empty line or comments */
		if (opcode == NULL || opcode[0] == '#')
			continue;
		/* Extract next arg passed to the instruction
		 * Continue to look for next token in the string 
		 * after the last time it was called, using the delimiters
		 */
		execute_instruction(opcode, &stack, line_number);
	}
	/*
		for (i = 0; opcodes[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, opcodes[i].opcode) == 0)
			{
				opcodes[i].f(&stack, line_number);
				break;
			}
		}
		if (opcodes[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}*/

	free_stack(stack);
	fclose(file);

	return (EXIT_SUCCESS);
}
