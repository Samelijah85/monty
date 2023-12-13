#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct info_s - struct containing global variables
 * @line: holds line contents
 * @file: points to the stream to read from
 * @filename: name of the file to read
 * @stack: points to the top element of the stack
 * @elements: keep track of the number of elements in a stack
 * @line_number: keep track of the line number
 * @token_number: stores the number of opcode args
 * @tokens: list of opcode args
 * @instr: points to the intructions
 *
 * Description: global variable
 */
typedef struct info_s
{
	char *line;
	FILE *file;
	char *filename;
	stack_t *stack;
	unsigned int elements;
	unsigned int line_number;
	unsigned int token_number;
	char **tokens;
	instruction_t *instr;
} info_t;

extern info_t *info;

/* opcode.c */
void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/* opcode2.c */
void add(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);

/* opcode_3.c */
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/* validate.c */
void validate_usage(int argc);

/* errors.c */
void malloc_error(void);
void usage_error(void);
void open_file_error(void);
void invalid_instruction_error(char *opcode);
void out_of_range_error(void);

/* errors2.c */
void no_argument_error(void);
void empty_stack_error(char *opcode);
void pop_empty_stack_error(void);
void stack_too_short_error(char *opcode);
void div_by_zero_error(void);

/* memory_free.c */
void free_all(void);
void free_tokens(void);
void free_line(void);
void free_stack(stack_t *head);
void free_instruction(void);

/* memory_free_2.c */
void free_info(void);

/* get_stream.c */
void close_stream(void);
void get_stream(void);

/* memory_alloc.c */
void create_inst(void);
void create_info(void);
void create_stack(void);
void alloc_tokens(void);
void initialize_info(void);

/* parse.c */
void tokenize_input(void);
void get_instruction(void);

/* is_integer.c */
int isInteger(const char *str);

/* execute.c */
void execute(void);

#endif /* MONTY_H */
