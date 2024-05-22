/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:55:51 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/22 14:04:29 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char **ft_split(char const *s, char c)
{

}
/* void free_split(char **str)
{
	if (!*str)
		return ;
}
 */

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_strs(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && is_sep(*str, charset))
			str++;
		if (*str != '\0')
		{
			count++;
			while (*str != '\0' && !is_sep(*str, charset))
				str++;
		}
	}
	return (count);
}

char	*get_word(char *str, char *charset)
{
	int		len_word;
	int		i;
	char	*word;

	len_word = 0;
	while (str[len_word] != '\0' && !is_sep(str[len_word], charset))
		len_word++;
	word = ft_calloc(sizeof(char) * (len_word + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[len_word] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		count;
	int		index;
	char	**strings;

	count = count_strs(str, charset);
	strings = malloc(sizeof(char *) * (count + 1));
	if (strings == NULL)
		return (NULL);
	index = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && is_sep(*str, charset))
			str++;
		if (*str != '\0')
		{
			strings[index++] = get_word(str, charset);
			if (strings[index - 1] == NULL)
				return (NULL);
		}
		while (*str != '\0' && !is_sep(*str, charset))
			str++;
	}
	strings[index] = NULL;
	return (strings);
}
/*
#include <stdio.h>
int main() {
char **split = ft_split(",,,,coucou, salut,,,,azazaz", ", ");
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
}
*/
