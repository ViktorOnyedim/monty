#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the instruction
 * @arg: argument passed to the function
 */

void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new;

	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = (stack_t *)malloc(sizeof(stack_t));

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

void pall(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *temp;
	temp = *stack;
	(void)line_number;
	(void)arg;

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
