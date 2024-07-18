#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	const char *p;
	char *value;
	int c;
	int count = 0;

	va_start(args, format);

	for (p = format; *p != '\0'; p++)
	{
		if (*p == '%')
			{
				p++;
				switch (*p) 
				{
					case 'c':
						c = va_arg(args, int);
						putchar(c);
						count++;
						break;
					case 's':
						value = va_arg(args, char *);
						if (value != NULL) 
						{
							for (; *value != '\0'; value++) 
							{
								putchar(*value);
								count++;
							}
						}
						break;
					case '%':
						putchar('%');
						count++;
						break;
				}
			}
		else
		{
			putchar(*p);
			count++;
		}
	}
	va_end(args);
	return count;
}
