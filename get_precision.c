#include "main.h"
/**
 * get_precision 
 * @format formatted string
 * @i
 * @list
 * Return
 */
int get_precision(const char *format, int *i, va_list list)
{
	int precision = -1;
	int currenti = *i + 1;

	if (format[currenti] != '.')
		return (precision);

	precision = 0;

	for (currenti += 1; format[currenti] != '\0'; currenti++)
	{
		if (is_digit(format[currenti]))
		{
			precision *= 10;
			precision += format[currenti] - '0';
		}
		else if (format[currenti] == '*')
		{
			currenti++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = currenti - 1;

	return (precision);
}
