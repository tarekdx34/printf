#include "main.h"

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
char a = va_arg(types, int);

return (handle_write_char(a, buffer, flags, width, precision, size));
}
<<<<<<< HEAD
/**
=======
/** print strng
>>>>>>> parent of efd52dd... done
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *strr = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (strr == NULL)
	{
		strr = "(null)";
		if (precision >= 6)
			strr = "      ";
	}

	while (strr[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &strr[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &strr[0], length);
			return (width);
		}
	}

	return (write(1, strr, length));
}
<<<<<<< HEAD
/************************* PRINT PERCENT SIGN *************************/
/**
=======
/**print %
>>>>>>> parent of efd52dd... done
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

<<<<<<< HEAD
/**
=======
/*** print integer
>>>>>>> parent of efd52dd... done
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int nn = va_arg(types, long int);
	unsigned long int numm;

	nn = convert_size_number(n, size);

	if (nn == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	numm = (unsigned long int)nn;

	if (nn < 0)
	{
		numm = (unsigned long int)((-1) * nn);
		is_negative = 1;
	}

	while (numm > 0)
	{
		buffer[i--] = (numm % 10) + '0';
		numm /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[], 
	int flags, int width, int precision, int size)
{
	unsigned int n, mn, j, sum;
	unsigned int aa[32];
	int countt;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	mn = 2147483648;
	/* 2 power 31 */
	a[0] = n / mn;
	for (j = 1; j < 32; j++)
	{
		mn /= 2;
		a[j] = (n / mn) % 2;
	}
	for (j = 0, sum = 0, countt = 0; j < 32; j++)
	{
		sum += a[j];
		if (sum || j == 31)
		{
			char y = '0' + a[j];

			write(1, &y, 1);
			countt++;
		}
	}
	return (countt);
}
