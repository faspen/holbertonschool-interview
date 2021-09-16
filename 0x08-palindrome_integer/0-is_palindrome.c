#include "palindrome.h"

/**
 * is_palindrome - check if int is a palindrome
 * @n: number to check
 * Return: 1 if yes, 0 if no
 */
int is_palindrome(unsigned long n)
{
	unsigned long tmp = n, rev = 0;
	int dig = 0;

	while (n != 0)
	{
		dig = n % 10;
		rev *= 10;
		rev += dig;
		n /= 10;
	}
	if (tmp == rev)
		return (1);
	return (0);
}
