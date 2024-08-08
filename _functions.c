#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - a char
 * @types: List a of arg
 * @buffer: Buffer arr
 * @flags:  Calculates flags
 * @width: Wid
 * @precision: Precision
 * @size: Size spec
 * Return: Number of c
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char ch = va_arg(types, int);

	return (handle_write_char(ch, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - a string
 * @types: List a of argu
 * @buffer: Buffer array to handle print
 * @flags:  Calculates a flags
 * @width: get width
 * @precision: Precisin spec
 * @size: Size spec
 * Return: Number of chars pri
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, j;
	char *ptr = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (ptr == NULL)
	{
		ptr = "(null)";
		if (precision >= 6)
			ptr = "      ";
	}

	while (ptr[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &ptr[0], len);
			for (j = width - len; j > 0; j--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (j = width - len; j > 0; j--)
				write(1, " ", 1);
			write(1, &ptr[0], len);
			return (width);
		}
	}

	return (write(1, ptr, len));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - a percent sign
 * @types: Lista of argum
 * @buffer: Buffer arr to handle print
 * @flags:  Calculates  flags
 * @width: get widt
 * @precision: Precision speci
 * @size: Size spe
 * Return: Number of chars pri
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

/************************* PRINT INT *************************/
/**
 * print_int - Print
 * @types: Lista of argum
 * @buffer: Buffer array to handle
 * @flags:  Calculates active fl
 * @width: get wi
 * @precision: Precision specific
 * @size: Size spec
 * Return: Number of chars prin
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	int is_negative = 0;
	long int x = va_arg(types, long int);
	unsigned long int number;

	x = convert_size_number(x, size);

	if (x == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)x;

	if (x < 0)
	{
		number = (unsigned long int)((-1) * x);
		is_negative = 1;
	}

	while (number > 0)
	{
		buffer[j--] = (number % 10) + '0';
		number /= 10;
	}

	j++;

	return (write_number(is_negative, j, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary -  an unsigned number
 * @types: Lista of argu
 * @buffer: Buffer array to hrint
 * @flags:  Calculates  flags
 * @width: get wid
 * @precision: Precision spec
 * @size: Size spec
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int x, m, j, s;
	unsigned int a[32];
	int counter;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = x / m;
	for (j = 1; j < 32; j++)
	{
		m /= 2;
		a[j] = (x / m) % 2;
	}
	for (j = 0, s = 0, counter = 0; j < 32; j++)
	{
		s += a[j];
		if (s || j == 31)
		{
			char z = '0' + a[j];

			write(1, &z, 1);
			counter++;
		}
	}
	return (counter);
}

