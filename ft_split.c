/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:55:51 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/23 09:55:06 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void free_split(char **str, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(split[i]);
		i++;
	}
	free(split);
}
*/

int	count_strs(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*get_word(char *str, char c)
{
	int		len_word;
	char	*word;

	len_word = 0;
	while (str[len_word] && str[len_word] != c)
		len_word++;
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, len_word + 1);
	return (word);
}

char	**ft_split(char *str, char c)
{
	int		count;
	int		index;
	char	**strings;

	count = count_strs(str, c);
	strings = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!strings)
		return (NULL);
	index = 0;
	while (*str)
	{
		if (*str != c)
		{
		strings[index] = get_word(str, c);
			if (!strings[index])
			{
				while (index--)
					free(strings[index]);
				free(strings);
				return (NULL);
			}
			index++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	strings[index] = NULL;
	return (strings);
}

/* #include <stdio.h>
int main() {
char **split = ft_split(",,,,coucou, salut,,,,azazaz", ',');
if (split == NULL) {
printf("Erreur Alloc.\n");
return 1;
}
int index = 0;
while (split[index] != NULL) {
printf("%s\n", split[index]);
index++;
}

int i = 0;
while (split[i] != NULL)
{
free(split[i]);
i++;
}
free(split);
return 0;
} */
