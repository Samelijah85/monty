#include "monty.h"

/**
 * mod - computes the rest of the division of the top
 * two elements of the stack
 * @stack: pointer to the pointer to the head of the list
 * @line_number: the line number
*/
void mod(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		stack_too_short_error("mod");
	}

	if ((*stack)->n == 0)
	{
		div_by_zero_error();
	}

	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the pointer to the head of the list
 * @line_number: the line number
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (*stack == NULL)
	{
		empty_stack_error("pchar");
	}

	if ((*stack)->n > 127)
	{
		out_of_range_error();
	}

	fprintf(stdout, "%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the pointer to the head of the list
 * @line_number: the line number
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	if (current == NULL)
	{
		fprintf(stdout, "\n");
	}

	while (current)
	{
		if (current->n == 0 || current->n > 127)
		{
			break;
		}
		fprintf(stdout, "%c\n", current->n);
		current = current->next;
	}
}

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the pointer to the head of the list
 * @line_number: the line number
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the pointer to the head of the list
 * @line_number: the line number
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}
