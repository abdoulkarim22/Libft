/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absouman <absouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:15:41 by absouman          #+#    #+#             */
/*   Updated: 2025/08/07 15:22:01 by absouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				len;
	char			*alpha;

	if (n < 0)
		nbr = (unsigned int)(-n);
	else
		nbr = (unsigned int)n;
	len = ft_len(n);
	alpha = malloc(sizeof(char) * (len + 1));
	if (alpha == NULL)
		return (NULL);
	alpha[len] = '\0';
	while (len > 0)
	{
		len--;
		alpha[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		alpha[0] = '-';
	return (alpha);
}
