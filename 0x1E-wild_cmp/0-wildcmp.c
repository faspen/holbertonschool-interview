#include "holberton.h"

/**
 * wildcmp - sees if two strings are roughly the same
 * @s1: first string
 * @s2: compare string
 * 
 * Return: 1 if the same, 0 if not
 */
int wildcmp(char *s1, char *s2)
{
    if (*s1 == *s2 && *s1 != '\0')
        return wildcmp(s1 + 1, s2 + 1);
    else if (*s1 == *s2)
        return (1);

    else if (*s2 == '*' && *(s2 + 1) != *s1 && *(s2 + 1) != '*')
        return wildcmp(s1 + 1, s2);
    else if (*s2 == '*' && *(s2 + 1) != *s1 && *(s2 + 1) == '*')
        return wildcmp(s1, s2 + 1);
    else if (*s2 == '*' && wildcmp(s1, s2 + 1) == 1)
        return (1);
    else if (*s2 == '*' && wildcmp(s1, s2 + 1) == 0)
        return (wildcmp(s1 + 1, s2));

    else
        return (0);
}
