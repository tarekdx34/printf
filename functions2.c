#include "main.h"
/**print  pointer**?
 * print_pointer
 * @types
 * @buffer
 * @flags
 * @width
 * @precision
 * @size
 * @return number of char
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[ind--] = map_to[num_address % 16];
		num_address /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/**print no printable*
 * print_non_printable
 * @types
 * @buffer
 * @width
 * @flags
 * @precison
 * @size
 * retuen chars
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *strr = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (strr == NULL)
		return (write(1, "(null)", 6));

	while (strr[i] != '\0')
	{
		if (is_printable(strr[i]))
			buffer[i + offset] = strr[i];
		else
			offset += append_hexa_code(strr[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**reverse**
 * print_reverse
 * @types
 * @buffer
 * @width
 * @flags
 * @precison
 * @size
 * retuen chars
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *strr;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (strr == NULL)
	{
		UNUSED(precision);

		strr = ")Null(";
	}
	for (i = 0; strr[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = strr[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}


/**PRINT A STRING IN ROT13**/
/**
 * print_rot13string - Print a string in rot13.
 * @types
 * @buffer
 * @flags
 * @width
 * @precision
 * @size
 * Return
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *strr;
	unsigned int y, j;
	int cott = 0;
	char i[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	strr = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (strr == NULL)
		strr = "(AHYY)";
	for (y = 0; strr[y]; y++)
	{
		for (j = 0; i[j]; j++)
		{
			if (i[j] == strr[y])
			{
				x = out[j];
				write(1, &x, 1);
				cott++;
				break;
			}
		}
		if (!i[j])
		{
			x = strr[y];
			write(1, &x, 1);
			cott++;
		}
	}
	return (cott);
}
