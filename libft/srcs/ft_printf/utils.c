/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:58:21 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/31 18:43:46 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf/printf_type.h>

int			ft_print_pad(int fd, int len_res, int pad, char c)
{
	int i;

	i = 0;
	while (pad > len_res)
	{
		ft_putchar_fd(c, fd);
		pad--;
		i++;
	}
	return (i);
}

intmax_t	ft_signed_from_lenght(t_args *sarg, intmax_t nb)
{
	if (sarg->len_modifier == h)
		return ((short)nb);
	else if (sarg->len_modifier == hh)
		return ((signed char)nb);
	else if (sarg->len_modifier == l)
		return ((long)nb);
	else if (sarg->len_modifier == ll)
		return ((long long)nb);
	else if (sarg->len_modifier == j)
		return (nb);
	else if (sarg->len_modifier == z)
		return ((size_t)nb);
	else
		return ((int)nb);
}

uintmax_t	ft_unsigned_from_lenght(t_args *sarg, uintmax_t nb)
{
	if (sarg->len_modifier == h)
		return ((unsigned short)nb);
	if (sarg->len_modifier == hh)
		return ((unsigned char)nb);
	else if (sarg->len_modifier == l)
		return ((unsigned long)nb);
	else if (sarg->len_modifier == ll)
		return ((unsigned long long)nb);
	else if (sarg->len_modifier == j)
		return (nb);
	else if (sarg->len_modifier == z)
		return ((size_t)nb);
	else
		return ((unsigned int)nb);
}

void		put_uprecision(t_args *s, size_t *len, char **nbr)
{
	char			*tmp;
	unsigned int	l;
	unsigned int	i;
	unsigned int	w;

	i = 0;
	if ((s->preci_len > *len)
		|| (s->zero_pad && s->min_width > *len && !s->left_pad))
	{
		w = (s->preci_len) ? s->preci_len : s->min_width;
		l = (s->precision) ? s->preci_len - *len : s->min_width - *len;
		tmp = ft_strnew((s->preci_len) ? s->preci_len : s->min_width);
		while (i < l)
			tmp[i++] = '0';
		l = 0;
		while (i < w)
			tmp[i++] = nbr[0][l++];
		ft_strdel(nbr);
		*nbr = tmp;
		*len = ft_strlen(tmp);
	}
}
