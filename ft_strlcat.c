/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absouman <absouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:30:29 by absouman          #+#    #+#             */
/*   Updated: 2025/08/07 13:50:59 by absouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t lenght)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] && i < lenght)
		i++;
	j = 0;
	while (src[j] && (i + j + 1) < lenght)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < lenght)
		dst[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}
