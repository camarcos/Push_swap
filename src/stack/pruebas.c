/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camarcos <camarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:28:44 by camarcos          #+#    #+#             */
/*   Updated: 2024/11/26 13:30:04 by camarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long	ft_atol_strict(char **split, long i)
{
	long	result;
	int		j;
	int		sign;

	result = 0;
	j = 0;
	sign = check_sign(split, i, &j);
	while (split[i][j])
	{
		if (!ft_isdigit(split[i][j]))
		{
			ft_free_matrix(split);
			ft_error();
		}
		result = result * 10 + split[i][j++] - '0';
	}
	result = result * sign;
	check_fit_int(result, split);
	return (result);
}
