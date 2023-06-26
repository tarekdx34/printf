#include "main.h"

/**get flags**
 * get_flags
 * @format
 * @i
 * Return: flags
 */
int get_flags(const char *format, int *ii)
{
	int jj, currenti;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (currenti = *ii + 1; format[currenti] != '\0'; currenti++)
	{
		for (jj = 0; FLAGS_CH[jj] != '\0'; j++)
			if (format[currenti] == FLAGS_CH[jj])
			{
				flags |= FLAGS_ARR[jj];
				break;
			}

		if (FLAGS_CH[jj] == 0)
			break;
	}

	*ii = currenti - 1;

	return (flags);
}
