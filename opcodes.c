#include "monty.h"

instruction_t opcodes[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
};

/**
 * push - pushes an element to the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the instruction
 * @arg: argument passed to the function
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	/* n_str */
	char *arg = NULL;
	arg = strtok(NULL, "\n\t\r");

	if (arg == NULL || !isdigit(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new -> n = atoi(arg);
	new -> prev = NULL;
	new -> next = *stack;

	if (*stack != NULL)
		(*stack) -> prev = new;
	*stack = new;
}

/**
 * pall - prints all the values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the instruction
 * @arg: argument passed to the instruction
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	temp = *stack;
	(void)line_number;
	/*(void)arg;*/

	while (temp != NULL)
	{
		printf("%d\n", temp -> n);
		temp = temp -> next;
	}
}

/* Deallocate memory previously allocated for stack */
void free_stack(stack_t *stack)
{
	stack_t *temp;
	while(stack != NULL)
	{
		temp = stack -> next;
		free(stack);
		stack = temp;
	}
}
