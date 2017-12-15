/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 23:06:54 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/13 23:06:59 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	pdix(double i)
{
	double j;

	j = 0;
	while (i != 0)
	{
		i /= 10;
		j++;
	}
	return (j * 100);
}

double			ft_sqrt(double i)
{
	double	sqrt;
	double	sqrtmp;

	sqrt = 0;
	sqrtmp = 0;
	if (i > 0)
	{
		sqrt = pdix(i);
		if (i == 0)
		{
			sqrt = 0;
			sqrtmp = 0;
		}
		while (sqrt != sqrtmp)
		{
			sqrtmp = sqrt;
			sqrt = ((0.5) * (sqrt + (i / sqrtmp)));
		}
		return (sqrt);
	}
	else if (i == 0)
		return ((double)0);
	return (0. / 0.);
}
