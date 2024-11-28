/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:45:57 by camarcos          #+#    #+#             */
/*   Updated: 2024/11/29 00:06:06 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*current;

	if (!a || a->size <= 1)
		return (1);
	current = a->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
//verifica si esta ordenado
// 1--> true 2--> false

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (sign == 1 && result > (LONG_MAX - (*str - '0')) / 10)
			return (LONG_MAX);
		if (sign == -1 && result > (LONG_MAX - (*str - '0')) / 10)
			return (LONG_MIN);
		result = result * 10 + (*str - '0');
		str++;
	}
	if (sign == -1)
		result = -result;
	return (result);
}
//mirar si son solo numeros

// long	ft_atol_strict(const char *str)

int	duplicates(t_stack *a)
{
	t_node	*current;
	t_node	*check;

	current = a->top;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}
//comprobar si hay repetidos

void	error_exit(const char *message)
{
	(void) message;
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
//mensaje de error y salida del programa

int	calculate_max_bits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
//calcular el numerode bits para saber el numero de iteraciones necesario