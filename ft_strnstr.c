/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:02:40 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/21 11:03:32 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	len_n;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	if (ft_strlen(s2) == 0)
		return ((char *) s1);
	len_n = ft_strlen(s2);
	i = 0;
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i + j] && s1[i + j] == s2[j] && i + j < len)
			j++;
		if (j == len_n)
			return ((char *) s1 + i);
		i++;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>

void	test_ft_strnstr(const char *s1, const char *s2, size_t len, const char *expected_result)
{
	char *result = ft_strnstr(s1, s2, len);
	if (result == expected_result || (result && expected_result && strcmp(result, expected_result) == 0))
	{
		printf("Test passed: ft_strnstr(\"%s\", \"%s\", %zu) -> \"%s\"\n", s1, s2, len, result);
	}
	else {
		printf("Test failed: ft_strnstr(\"%s\", \"%s\", %zu) -> \"%s\", expected \"%s\"\n", s1, s2, len, result, expected_result);
	}
}

int	main()
{
	test_ft_strnstr("Hello World", "World", 11, "World");
	test_ft_strnstr("Hello World", "Worlde", 20, NULL);
	test_ft_strnstr("Hello World", "World", 5, NULL);
	test_ft_strnstr("Hello World", "", 11, "Hello World");
	test_ft_strnstr("", "World", 11, NULL);
	test_ft_strnstr("Hello", "Hello", 5, "Hello");
	test_ft_strnstr("Hello", "lo", 5, "lo");
	test_ft_strnstr("Hello", "lo", 4, NULL);
	test_ft_strnstr("abcdabc", "abc", 5, NULL);
	test_ft_strnstr(NULL, "abc", 5, NULL);
	test_ft_strnstr("abcdabc", NULL, 5, NULL);
	test_ft_strnstr("Hello World", "World", 0, NULL);
	test_ft_strnstr("Hello World", "", 0, "Hello World");
	return (0);
}
 */
