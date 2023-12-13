#include "monty.h"

/**
 * free_info - free memory allocated to info struct
*/
void free_info(void)
{
	free(info);
}
