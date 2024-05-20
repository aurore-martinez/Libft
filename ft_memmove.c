/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:00:30 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/20 13:53:35 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	temp[n];

	ft_memcpy(temp, src, n);
	ft_memcpy(dest, temp, n);
	return (dest);
}

/* #include <stdio.h>
#include <string.h>
int main()
{
    char src[10] = "Aurore";
    char dest[10] = "cc";
    printf("Avant ft_memmove - src : %s, dest : %s\n", src, dest);
    ft_memmove(dest + 2, src, 6);
    printf("Après ft_memmove - src : %s, dest : %s\n", src, dest);
    return 0;
} */
