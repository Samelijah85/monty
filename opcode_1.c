#include "monty.h"

/**
 * pall - Prints all the values on the stack,
 * starting from the top of the stack
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: Not used
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *stack;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * push - Pushes an element to the stack
 * @stack: Pointer to the pointer to the head of the list
 * @line_number: The line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n, i = 0, flag = 0;

	if (info.arg)
	{
		if (info.arg[0] == '-')
			i++;
		for (; info.arg[i] != '\0'; i++)
		{
			if (info.arg[i] > 57 || info.arg[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			push_error(stack, line_number);
		}
	}
	else
	{
		push_error(stack, line_number);
	}
	n = atoi(info.arg);
	if (info.lifi == 0)
		add_to_stack(stack, n);
	else
		add_to_queue(stack, n);
}
