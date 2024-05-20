/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:55:07 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/20 13:53:13 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%d : %d\n", ft_isalpha('a'), isalpha('a'));
	printf("%d : %d\n", ft_isalpha('\0'), isalpha('\0'));
	printf("%d : %d\n", ft_isalpha('1'), isalpha('1'));
	printf("%d : %d\n", ft_isalpha('N'), isalpha('N'));
	printf("%d : %d\n", ft_isalpha('\n'), isalpha('\n'));
	printf("%d : %d\n", ft_isalpha(126), isalpha(126));
	printf("%d : %d\n", ft_isalpha(87), isalpha(87));
} */
