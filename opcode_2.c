#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, n;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		swap_error(stack, line_number);
	}
	temp = *stack;
	n = temp->n;
	temp->n = temp->next->n;
	temp->next->n = n;
}

/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, sum;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		add_error(stack, line_number);
	}
	temp = *stack;
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	*stack = temp->next;
	free(temp);
}

/**
 * sub - Subtracts the top two elements of the stack
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int difference, nodes;

	temp = *stack;
	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;
	if (nodes < 2)
	{
		sub_error(stack, line_number);
	}
	temp = *stack;
	difference = temp->next->n - temp->n;
	temp->next->n = difference;
	*stack = temp->next;
	free(temp);
}

/**
 * _div - Divides the top two elements of the stack
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, quotient;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		div_error(stack, line_number);
	}
	temp = *stack;
	if (temp->n == 0)
	{
		div_by_zero_error(stack, line_number);
	}
	quotient = temp->next->n / temp->n;
	temp->next->n = quotient;
	*stack = temp->next;
	free(temp);
}

/**
 * mul - Multiplies the top two elements of the stack
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, product;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		mul_error(stack, line_number);
	}
	temp = *stack;
	product = temp->next->n * temp->n;
	temp->next->n = product;
	*stack = temp->next;
	free(temp);
}
