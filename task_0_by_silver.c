#include "main.h"
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int index = 0;
	va_list array;
	const char *str;
	char c;

	va_start(array, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;

			switch (*format)
			{
				case '%':
					c = '%';
					write(1, &c, 1);
					index++;
					break;
				case 'c':
					c = (char)va_arg(array, int);
					write(1, &c, 1);
					index++;
					break;
				case 's':
					str = va_arg(array, const char*);
					if (str != NULL)
					{
						write(1, str, strlen(str));
						index += strlen(str);
					}
					break;
				default:
					write(1, "%", 1);
					write(1, format, 1);
					index += 2;
					break;
			}
		}
		else
		{
			write(1, format, 1);
			index++;
		}
		format++;
	}
	va_end(array);
	return (index);
}
