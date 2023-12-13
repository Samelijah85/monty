#include "monty.h"

info_t *info = NULL;

/**
 * main - Entry point of the program
 * @argc: number of arguments supplied
 * @argv: array of arguments supplied
 *
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	initialize_info();
	info->filename = argv[1];
	get_stream();

	return (0);
}
