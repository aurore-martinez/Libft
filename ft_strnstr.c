/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:02:40 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/20 16:22:21 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char *s1, const char *s2, size_t len)
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
