#include "monty.h"

/**
 * mod - Computes the rest of the division of the top
 * two elements of the stack
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, remainder;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		mod_error(stack, line_number);
	}
	temp = *stack;
	if (temp->n == 0)
	{
		div_by_zero_error(stack, line_number);
	}
	remainder = temp->next->n % temp->n;
	temp->next->n = remainder;
	*stack = temp->next;
	free(temp);
}

/**
 * pchar - Prints the char at the top of the stack
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack == NULL)
	{
		pchar_error(stack, line_number);
	}

	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		pchar_out_of_range_error(stack, line_number);
	}

	fprintf(stdout, "%c\n", (*stack)->n);
}

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	while (temp)
	{
		if (temp->n > 127 || temp->n <= 0)
		{
			break;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the stack to the top
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack, *copy;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	copy = (*stack)->next;
	copy->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = copy;
}

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *copy;
	(void)line_number;

	copy = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}
