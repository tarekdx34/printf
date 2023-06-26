#include "main.h"

/**
 * get_size
 * @format
 * @i
 * Return precision
 */
int get_size(const char *format, int *i) /** int f (const char *, int *i) */
{
	int currenti = *i + 1;
	int size = 0;

	if (format[currenti] == 'l')
		size = S_LONG;
	else if (format[currenti] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = currenti - 1;
	else
		*i = currenti;

	return (size);
}
