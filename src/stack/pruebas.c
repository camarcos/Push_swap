/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:28:44 by camarcos          #+#    #+#             */
/*   Updated: 2024/11/30 10:55:12 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	process_quoted_argument(const char *arg, t_stack *a)
{
	char	**numbers;
	int		i;

	numbers = ft_split(arg, ' ');
	if (!numbers)
		error_exit("Error al dividir la cadena.");
	i = 0;
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i]))
			error_exit("Entrada no válida.");
		push_number_to_stack(ft_atoi(numbers[i]), a);
		i++;
	}
	free_split(numbers);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	parse_arguments(int argc, char **argv, t_stack *a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			process_quoted_argument(argv[i], a);
		else
		{
			if (!is_valid_number(argv[i]))
				error_exit("Entrada no válida.");
			push_number_to_stack(ft_atoi(argv[i]), a);
		}
		i++;
	}
}

int	is_valid_number(const char *str)
{
	if (!ft_isdigit(*str) && *str != '-' && *str != '+')
		return (0);
	if ((*str == '-' || *str == '+') && !ft_isdigit(*(str + 1)))
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

// int	main(int argc, char **argv)
// {
// 	t_stack	a;
// 	t_stack	b;

// 	if (argc < 2)
// 		return (0);
// 	initialize_stack(&a);
// 	initialize_stack(&b);
// 	parse_arguments(argc, argv, &a);
// 	sort_stack(&a, &b);
// 	free_stack(&a);
// 	free_stack(&b);
// 	return (0);
// }
