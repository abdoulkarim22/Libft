/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absouman <absouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:35:28 by absouman          #+#    #+#             */
/*   Updated: 2025/08/07 13:51:16 by absouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t lenght)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
	{
		return ((char *)big);
	}
	i = 0;
	while (big[i] != '\0' && i < lenght)
	{
		j = 0;
		while (little[j] != '\0' && big[i + j] == little[j] && (i + j) < lenght)
		{
			j++;
		}
		if (little[j] == '\0')
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
