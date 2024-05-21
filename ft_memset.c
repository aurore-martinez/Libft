/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:56:20 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/21 10:02:25 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	if (!b)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char) c;
		i++;
	}
	return (b);
}

/* #include <stdio.h>
#include <string.h>
int main()
{
    char str[10];
    printf("str avant ft_memset: %s\n", str);
    ft_memset(str, 'A', 5);
    // memset(str, 'A', 5);
    printf("str après ft_memset: %s\n", str);
    return 0;
} */
